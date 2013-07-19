//
// Debug.cpp
// BlindStorage
//

#include "Debug.h"

void printhex(unsigned char* pointer, int32_t size, string tag){
	cout << "************************************************************ " << tag << " (start) ************************************************************" << endl;    
	for(int i = 0; i < size; i++)
		printf("%02x ", pointer[i]);
	cout << endl;
	cout << "************************************************************* " << tag << " (end) *************************************************************" << endl;  
}

void printhex(char* pointer, int32_t size, string tag){
	cout << "************************************************************ " << tag << " (start) ************************************************************" << endl;
	for(int i = 0; i < size; i++)
		printf("%02x ", (unsigned char)pointer[i]);
	cout << endl;
	cout << "************************************************************* " << tag << " (end) *************************************************************" << endl;
}

void printhex(unsigned char** pointer, int32_t rows, int32_t cols, string tag){
	cout << "************************************************************ " << tag << " (start) ************************************************************" << endl;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++)
			printf("%02x ", pointer[i][j]);
		cout << endl;
	}
	cout << endl;
	cout << "************************************************************* " << tag << " (end) *************************************************************" << endl; 
}

void printhex(vector<byte> vector, string tag){
	cout << "************************************************************ " << tag << " (start) ************************************************************" << endl;
	for(int i = 0; i < vector.size(); i++){
		printf("%02x ", vector[i]);
	}
	cout << endl;
	cout << "************************************************************* " << tag << " (end) *************************************************************" << endl; 

}

void printdec(uint32_t* pointer, int32_t size, string tag){
	cout << "************************************************************ " << tag << " (start) ************************************************************" << endl;
	for(int i = 0; i < size; i++)
		printf("%d ",  pointer[i]);
	cout << endl;
	cout << "************************************************************* " << tag << " (end) *************************************************************" << endl;   
}
 
void printdec(uint64_t* pointer, int32_t size, string tag){
	cout << "************************************************************ " << tag << " (start) ************************************************************" << endl;
	for(int i = 0; i < size; i++)
		printf("%llu ",  pointer[i]);
	cout << endl;
	cout << "************************************************************* " << tag << " (end) *************************************************************" << endl;   
}
 
void printchars(unsigned char* pointer, int32_t size, string tag){
	cout << "************************************************************ " << tag << " (start) ************************************************************" << endl;
	for(int i = 0; i < size; i++)
		printf("%c", pointer[i]);
	cout << endl;
	cout << "*************************************************************" << tag << " (end) **************************************************************" << endl;
}

void printchars(vector<unsigned char>& vector, int32_t size, string tag){
	cout << "************************************************************" << tag << " (start) ************************************************************" << endl;
	for( int i = 0; i < size; i++)
		printf("%c", vector[i]);
	cout << endl;
	cout << "*************************************************************" << tag << " (end) *************************************************************" << endl;
}

void print_docid_t(vector<unsigned char>& vector, string tag){
	cout << "*********************************************************** " << tag << " (start) *************************************************************" << endl;
	for ( int i = 0; i < vector.size()/8; i++){
		if(i!=0 && i%4 == 0)
			cout << endl;
		cout << *(uint64_t*)(&vector[i*8]) << "\t\t\t\t";
	}
	cout << endl;
	cout << "************************************************************" << tag << " (end) **************************************************************" << endl; 
}   
