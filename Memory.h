#ifndef MEMORY
#define MEMORY
#include <list>
#include "Block.h"
#include <iostream>
#include <iomanip>
#include <vector>

class Memory{
protected:

	std::list<Block *> memoryLocations;

public:
	Memory(int memorySize=1024);
  Memory(std::vector<Block*>& initialBlocks);
	virtual bool allocateMemory(int processID , int processSize)=0;
	bool deallocateMemory(int processID);
  void print();

};
#endif