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

  memory->allocateMemory(6, 3);

  memory->print();


  BestFitMemory *memBest = new BestFitMemory;

  memBest->allocateMemory(1, 5);
  memBest->allocateMemory(2, 5);
  memBest->allocateMemory(3, 5);
  memBest->allocateMemory(4, 5);
  memBest->allocateMemory(5, 5);

  memBest->deallocateMemory(2);
  memBest->deallocateMemory(4);
  memBest->deallocateMemory(3);

  memBest->allocateMemory(6, 3);


  memBest->print();


  WorstFitMemory *memWorst = new WorstFitMemory;
  memWorst->allocateMemory(1, 5);
  memWorst->allocateMemory(2, 5);
  memWorst->allocateMemory(3, 5);
  memWorst->allocateMemory(4, 5);
  memWorst->allocateMemory(5, 5);

  memWorst->deallocateMemory(2);
  memWorst->deallocateMemory(4);
  memWorst->deallocateMemory(3);

  memWorst->allocateMemory(6, 3);


  memWorst->print();



}
