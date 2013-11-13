//
// CRIBlock.h
// BlindStorage
//

#ifndef __BlindStorage__CRIBlock__
#define __BlindStorage__CRIBlock__

#include "parameters.h"

#include <stdio.h>
#include <string>

#include <vector>
using std::vector;

#include <cstring>
using std::memset;
using std::memcpy;

#include "Debug.h"

class CRIBlock{
public:
	CRIBlock();
	~CRIBlock();
	
	void make(prSubsetSize_t size, prSubsetSeed_t seed, size_t filesize, byte lowerFid[]);
	void update(prSubsetSize_t size, prSubsetSeed_t seed, size_t filesize);
	void parse(byte block[]);

	void get(byte block[]);
	void get(vector<byte>& block);

	bool match(byte lowerFid[]);

	prSubsetSize_t getSize();
	prSubsetSeed_t getSeed();
	size_t getFileSize();

private:
	prSubsetSize_t size;
	prSubsetSeed_t seed;
	size_t filesize;

	byte lowerFid[LOWERFID_SIZE];

	byte block[CRI_BLOCK_SIZE];
};
#endif /* defined(__BlindStorage__CRIBlock__) */
