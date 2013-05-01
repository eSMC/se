//
// Key.h
// BlindStorage
//

#ifndef __BlindStorage__Key__
#define __BlindStorage__Key__

#include "parameters.h"
#include "AES.h"
#include <iostream>
#include <fstream>

using std::ifstream;

class Key{
private:
	char* key;
	std::fstream keyfile;
	
	void generate();
	bool isKeyPresentOnDisk();
	
public:
	Key(const char filename[]);
	~Key();
	char* get();
	void save();
	void load();
	void setup();
};

#endif /* defined(__BlindStorage__Key__) */
