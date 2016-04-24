#include "Process.h"

void Process::setId(int id){
  this->id=id;
}

int Process::getId(){
  return id;
}

bool Process::isOccupied(){
  return true;
}
