#ifndef PROCESS
#define PROCESS

#include "Block.h"

class Process:public Block{
private:
  int id;
public:	
  Process(int id=0,int base=0,int limit=0)
  {
  	this->id=id;
  	this->base=base;
  	this->limit=limit;
  }	
  void setId(int id);
  int getId();
  bool isOccupied();
};

#endif
