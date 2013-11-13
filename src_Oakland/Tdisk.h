//
//  Tdisk.h
//  BlindStorage
//

#ifndef __BlindStorage__Tdisk__
#define __BlindStorage__Tdisk__

#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include "TBlock.h"
#include "CRI.h"
#include "parameters.h"
#include "fileID.h"
#include "PRSubset.h"
#include "PRF.h"
#include <unordered_map>
#include <vector>
#include "Ddisk.h"
#include "Debug.h"
//#include <tr1/memory>

using std::shared_ptr;
using std::unordered_map;

class Tdisk{
private:
	TBlock** T;
	unordered_map<higherfid_t, CRI> criMap;
	vector<vector<byte> > criBytes;

public:
	Tdisk();
	~Tdisk();
	void addFile(fileID fid, size_t filesize, PRSubset prSubset);
	void finalize(Ddisk &D);
	void upload();
	void getBlock(t_index_t index, TBlock& block);
	void writeToDisk();  
};

#endif /* defined(__BlindStorage__Tdisk__) */
