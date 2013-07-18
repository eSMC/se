//
// OnlineSession_test.cc
// BlindStorage Test
//

#include "gtest/gtest.h"

#include "./../src/OnlineSession.h"
#include "./../src/BStore.h"
#include "./../src/DiskCommunicator.h"
#include "./../src/helper.h"

TEST(OnlineSessionRead, Test1){
	string directoryPath = "/Users/naveed/BStore/datasets/email/enron_mail_20110402/maildir/mann-k/inbox/";
//	string directoryPath = "/Users/naveed/BStore/datasets/testdir/";
	BStore store(directoryPath);
//	DiskCommunicator dcomm;
	
	while(true){
		cout << "Enter filenumber (Enter q to quit): ";
		string filenumber;
		cin >> filenumber;
		if(filenumber.compare("q") == 0){
			cout << "Thank you for using Blind Storage System." << endl;
			break;
		}
		string filename = directoryPath + filenumber + ".";
		cout << "Reading file: " << filename << endl;
		OnlineSession session;
		byte* file;
		size_t filesize = session.read(filename, file);
		printchars(file, filesize, "FILE");
		delete[] file;
		}
}

TEST(OnlineSessionWrite, Test1){
//	string directoryPath = "/Users/naveed/BStore/datasets/testdir/";
	string directoryPath = "/Users/naveed/BStore/datasets/email/enron_mail_20110402/maildir/mann-k/inbox/" ;
//	BStore store(directoryPath);
	while(true){
		OnlineSession* writeSession = new OnlineSession();;
		string filenumber;
		string newfilenumber;

		cout << "Enter filenumber you want to update (Enter q to quit): ";
		cin >> filenumber;
		if(filenumber.compare("q") == 0){
			cout << "Thank you for using Blind Storage System." << endl;
			break;
		}

		cout << "Enter new filenumber (Enter q to quit): ";
		cin >> newfilenumber;
		if(newfilenumber.compare("q") == 0){
			cout << "Thank you for using Blind Storage System." << endl;
			break;
		}
			
		string filename = directoryPath + filenumber + ".";
		string newfilename = directoryPath + newfilenumber + ".";
		
		size_t size = readFileSize(newfilename);
		cout << "New file size is " << size << endl;
		byte updateFileBytes[size];
		memset(updateFileBytes, 0, size);
		readFile(newfilename, updateFileBytes, size);
		
		writeSession->update(filename, updateFileBytes, size);
		delete writeSession;
	}

	while(true){
		string filenumber;
		cout << "Enter file to read (Enter q to quit): ";
		cin >> filenumber;

		if(filenumber.compare("q") == 0){
			cout << "Thank you for using Blind Storage System." << endl;
			break;
		}

		string filename = directoryPath + filenumber + ".";
		OnlineSession* readSession = new OnlineSession();
		byte* file;
		size_t filesize = readSession->read(filename, file);
		printchars(file, filesize, "UPDATED FILE");
		delete[] file;
		delete readSession;
	}
}

TEST(OnlineSessionRemove, Test1){
	string directoryPath = "/Users/naveed/BStore/datasets/email/enron_mail_20110402/maildir/mann-k/inbox/";
	OnlineSession sessionDelete;
	string filename1 = directoryPath + "2" + ".";
	string filename2 = directoryPath + "207" + ".";
	sessionDelete.remove(filename1);

	OnlineSession session0;
	byte* file0;
	size_t filesize0 = session0.read(filename1, file0);
	byte expectedFile[filesize0];
	memset(expectedFile, 0, filesize0);
	EXPECT_TRUE(0 == memcmp(file0, expectedFile, filesize0));
	printchars(file0, filesize0, "DELETED FILE");
	delete[] file0;

	OnlineSession session1;
	size_t filesize1 = readFileSize(filename2);
	byte updateFileBytes[filesize1];
	readFile(filename2, updateFileBytes, filesize1);
	session1.update(filename1, updateFileBytes, filesize1);

	OnlineSession session2;
	byte* file2;
	size_t filesize2 = session2.read(filename1, file2);
	printchars(file2, filesize2, "UPDATED DELTED FILE");
	EXPECT_TRUE(0 == memcmp(file2, updateFileBytes, filesize2));
	delete[] file2;

	while(true){
		cout << "Enter filenumber (Enter q to quit): ";
		string filenumber;
		cin >> filenumber;
		if(filenumber.compare("q") == 0){
			cout << "Thank you for using Blind Storage System." << endl;
			break;
		}
		string filename = directoryPath + filenumber + ".";
		cout << "Reading file: " << filename << endl;
		OnlineSession session;
		byte* file;
		size_t filesize = session.read(filename, file);
		printchars(file, filesize, "FILE");
		delete[] file;
	}
}
