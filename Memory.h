#ifndef MEMORY
#define MEMORY
#include <vector>
#include "Block.h"
class Memory{
protected:

std::vector<Block> memoryLocations;

public:
virtual bool allocateMemory(int processID , int processSize)=0;
bool deallocateMemory(int processID);

};
#endif