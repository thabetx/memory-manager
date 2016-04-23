#ifndef MEMORY
#define MEMORY
#include <list>
#include "Block.h"
#include <iostream>
#include <iomanip>

class Memory{
protected:

	std::list<Block *> memoryLocations;

public:
	Memory();
	virtual bool allocateMemory(int processID , int processSize)=0;
	bool deallocateMemory(int processID);
  void print();

};
#endif