#ifndef PROCESS
#define PROCESS

#include "Block.h"

class Process:public Block{
private:
  int id;
public:	
  Process(int id,int base,int limit)
  {
  	this->id=id;
  	this->base=base;
  	this->limit=limit;
  }	
  void setId(int i);
  int getId();
  bool isOccupied();
};

#endif
