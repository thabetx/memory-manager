#include <iostream>
#include "FirstFitMemory.h"
#include "BestFitMemory.h"
#include "WorstFitMemory.h"
#include "Process.h"
using namespace std;

int main(){
  FirstFitMemory *memory = new FirstFitMemory();
  
  memory->allocateMemory(1,5);
  memory->allocateMemory(2,5);
  memory->allocateMemory(3,5);
  memory->allocateMemory(4,5);
  memory->allocateMemory(5,5);

  memory->deallocateMemory(2);
  memory->deallocateMemory(4);
  memory->deallocateMemory(3);

  memory->print();
}
