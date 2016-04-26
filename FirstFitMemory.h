#ifndef FIRSTFITMEMORY
#define FIRSTFITMEMORY
#include "Memory.h"

class FirstFitMemory: public Memory{
private:

public:
FirstFitMemory(int memorySize=1024);
bool allocateMemory(int processID , int processSize);

};
#endif