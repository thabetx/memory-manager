#ifndef BESTFITMEMORY
#define BESTFITMEMORY

#include "Memory.h"

class BestFitMemory : public Memory{
private:

public:
bool allocateMemory(int processID , int processSize);

};

#endif