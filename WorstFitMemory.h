#ifndef WORSTFITMEMORY
#define WORSTFITMEMORY
#include "Memory.h"
#include "Process.h"

class WorstFitMemory : public Memory{
private:

public:
WorstFitMemory(int memorySize=1024);
WorstFitMemory(std::vector<Block*>& initialBlocks);
bool allocateMemory(int processID , int processSize);

};
#endif