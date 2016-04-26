#ifndef WORSTFITMEMORY
#define WORSTFITMEMORY
#include "Memory.h"

class WorstFitMemory : public Memory{
private:

public:
WorstFitMemory(int memorySize=1024);
bool allocateMemory(int processID , int processSize);

};
#endif