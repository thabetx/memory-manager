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

void Block::setBase(int b){
  base=b;
}

int Block::getBase(){
  return base;
}

void Block::setLimit(int l){
  limit=l;
}

int Block::getLimit(){
  return limit;
}
