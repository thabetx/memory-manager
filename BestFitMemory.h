#ifndef BESTFITMEMORY
#define BESTFITMEMORY

#include "Memory.h"
#include "Process.h"
class BestFitMemory : public Memory{
private:

public:
BestFitMemory(int memorySize=1024);
BestFitMemory(std::vector<Block*>& initialBlocks);
bool allocateMemory(int processID , int processSize);

};

#endif