#include "Block.h"
Block::Block(int base,int limit)
{
	this->base=base;
	this->limit=limit;
}
int Block::getId(){
  return -1;
}

bool Block::isOccupied(){
  return false;
}

void Block::setBase(int base){
  this->base=base;
}

int Block::getBase(){
  return base;
}

void Block::setLimit(int limit){
  this->limit=limit;
}

int Block::getLimit(){
  return limit;
}
