#ifndef FIRSTFITMEMORY
#define FIRSTFITMEMORY
#include "Memory.h"

class FirstFitMemory: public Memory{
private:

public:
bool allocateMemory(int processID , int processSize);

};
#endif