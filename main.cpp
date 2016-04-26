#include <iostream>
#include "FirstFitMemory.h"
#include "BestFitMemory.h"
#include "WorstFitMemory.h"
#include "Process.h"
using namespace std;

int main(){

  int type;
  cout<<"Enter the type of the memory (1- First Fit, 2-Best Fit, 3-Worst Fit): ";
  cin>>type;
  Memory *memory;
  if(type==1){
    memory = new FirstFitMemory;
  }else if(type==2){
    memory = new BestFitMemory;
  }else if(type==3){
    memory = new WorstFitMemory;
  }else{
    cout<<"Type is invalid.";
    return 0;
  }

  cout<<"Memory was successfully created"<<endl;
  memory->print();

  int numberOfQueries, id,limit;
  cout<<"Enter the number of queries: ";
  cin>>numberOfQueries;

  for(int i=0;i<numberOfQueries;i++){
    int query_type;
    cout<<"Enter the query type (1-Allocate, 2- Deallocate): ";
    cin>>query_type;
    if(query_type==1){
      cout<<"Enter the id of the process: ";
      cin>>id;
      cout<<"Enter the size of the process: ";
      cin>>limit;
      if(memory->allocateMemory(id,limit)){
        cout<<"The Process was successfully allocated"<<endl;
        memory->print();
      }
      else{
        cout<<"No enough space to add the process"<<endl;
      }
    }else if(query_type==2){
      cout<<"Enter the id of the process to be deleted: ";
      cin>>id;
      if(memory->deallocateMemory(id)){
        cout<<"The process was successfully deallocated"<<endl;
      }else{
        cout<<"The process was not found"<<endl;
      }
    }else{
      cout<<"invalid query type";
    }
  }
}
