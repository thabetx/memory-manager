#ifndef WORSTFITMEMORY
#define WORSTFITMEMORY
#include "Memory.h"

class WorstFitMemory : public Memory{
private:

public:
bool allocateMemory(int processID , int processSize);

};
#endif