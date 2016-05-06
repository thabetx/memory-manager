#ifndef FIRSTFITMEMORY
#define FIRSTFITMEMORY
#include "Memory.h"
#include "Process.h"

class FirstFitMemory: public Memory{
private:

public:
FirstFitMemory(int memorySize=1024);
FirstFitMemory(std::vector<Block*>& initialBlocks);
bool allocateMemory(int processID , int processSize);

};
#endif