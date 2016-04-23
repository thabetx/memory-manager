#include "Process.h"

void Process::setId(int i){
  id=i;
}

int Process::getId(){
  return id;
}

bool Process::isOccupied(){
  return true;
}
