#ifndef PROCESS
#define PROCESS

#include "Block.h"

class Process:public Block{
private:
  int id;
public:
  void setId(int i);
  int getId();
  bool isOccupied();
};

#endif
