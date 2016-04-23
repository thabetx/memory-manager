#include <iostream>
#include "FirstFitMemory.h"
#include "BestFitMemory.h"
#include "WorstFitMemory.h"
#include "Process.h"
using namespace std;

int main(){
  FirstFitMemory *memory = new FirstFitMemory();
  cout<<memory->allocateMemory(5,2)<<endl;
  memory->print();
}
