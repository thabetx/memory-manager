#include <iostream>
#include "FirstFitMemory.h"
#include "BestFitMemory.h"
#include "WorstFitMemory.h"
#include "Process.h"
using namespace std;

int main(){
  FirstFitMemory *memFirst = new FirstFitMemory();
  
  memFirst->allocateMemory(1,1024);
  memFirst->allocateMemory(5,6);
  memFirst->deallocateMemory(1);
  
  memFirst->allocateMemory(2,2);
  memFirst->allocateMemory(3,3);
  memFirst->allocateMemory(4,4);
  memFirst->allocateMemory(5,5);

  memFirst->deallocateMemory(2);
  memFirst->deallocateMemory(4);
  memFirst->deallocateMemory(3);

  memFirst->allocateMemory(6, 3);
  
  memFirst->print();

  BestFitMemory *memBest = new BestFitMemory;

  memBest->allocateMemory(1, 1024);
  memBest->deallocateMemory(1);

  memBest->allocateMemory(2,2);
  memBest->allocateMemory(3,3);
  memBest->allocateMemory(4,4);
  memBest->allocateMemory(5,5);

  memBest->deallocateMemory(2);
  memBest->deallocateMemory(4);
  memBest->deallocateMemory(3);

  memBest->allocateMemory(6, 3);

  memBest->print();

  WorstFitMemory *memWorst = new WorstFitMemory;

  memWorst->allocateMemory(1,1024);
  memWorst->allocateMemory(5,6);
  memWorst->deallocateMemory(1);

  memWorst->allocateMemory(2,2);
  memWorst->allocateMemory(3,3);
  memWorst->allocateMemory(4,4);
  memWorst->allocateMemory(5,5);

  memWorst->deallocateMemory(2);
  memWorst->deallocateMemory(4);
  memWorst->deallocateMemory(3);

  memWorst->allocateMemory(6, 3);

  memWorst->print();
}
