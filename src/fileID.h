//
// fileID.h
// BlindStorage
//

#ifndef __BlindStorage__fileID__
#define __BlindStorage__fileID__

#include <iostream>

#include <string>
using std::string;

#include "parameters.h"
#include "Key.h"
#include "HashMAC.h"
#include "PRF.h"

class fileID {
private:
	byte ID[FILEID_SIZE];
	higherfid_t higherID;

	static byte hmacKey[];
	static byte prfKey[];

	static bool keyGenerated;
	void setupKey();
	
public:
	fileID();
	fileID(string filename);
	fileID(byte ID[]);
	~fileID();
	
	void get(byte ID[]);
	void getLowerID(byte lowerID[]);
	higherfid_t getHigherID();
};

#endif /* define(__BlindStorage__fileID__) */
