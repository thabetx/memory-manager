#include <iostream>
#include "FirstFitMemory.h"
#include "BestFitMemory.h"
#include "WorstFitMemory.h"
#include <vector>
#include <algorithm>
using namespace std;

int main(){

  vector<pair<int,int>>holes;
  int numHoles=0;

  while(numHoles<=0){
    cout<<"Enter number of holes: ";
    cin>>numHoles;
    if(numHoles<=0)
      cout<<"Number of holes must be > 0\n";
    else break;
  }

  int holeStart,holeSize;
  for(int i=0;i<numHoles;i++){
    cout<<"Enter hole starting position and hole size: ";
    cin>>holeStart>>holeSize;
    if(holeStart<0){cout<<"start can't be negative"<<endl;i--;continue;}
    if(holeSize<0){cout<<"size can't be negative"<<endl;i--;continue;}
    holes.push_back({holeStart,holeSize});
  }

  sort(holes.begin(),holes.end());
  int j=0;
  vector<pair<int,int>>merged_holes;
  for(int i=0;i<holes.size();i=j){
    for(j=i+1;j<holes.size();j++){
      if(holes[i].first+holes[i].second>=holes[j].first){
        holes[i].second=max(holes[i].first+holes[i].second,holes[j].first+holes[j].second)-holes[i].first;
      }
      else break;
    }
    merged_holes.push_back({holes[i].first,holes[i].second});
  }

  vector<Block*>initial_blocks;
  int process_counter=-1;
  if(merged_holes[0].first!=0){
    initial_blocks.push_back(new Process(process_counter,0,merged_holes[0].first));
  }
  for(int i=0;i<merged_holes.size();i++){
    initial_blocks.push_back(new Block(merged_holes[i].first,merged_holes[i].second));
    if(i==merged_holes.size()-1)break;
    initial_blocks.push_back(new Process(process_counter,merged_holes[i].first+merged_holes[i].second,merged_holes[i+1].first-(merged_holes[i].first+merged_holes[i].second)));
  }

  Memory *memory;

  int type;
  cout<<"Enter the type of the memory (1- First Fit, 2-Best Fit, 3-Worst Fit): ";
  cin>>type;

  if(type==1){
    memory = new FirstFitMemory(initial_blocks);
  }else if(type==2){
    memory = new BestFitMemory(initial_blocks);
  }else if(type==3){
    memory = new WorstFitMemory(initial_blocks);
  }else{
    cout<<"Type is invalid.";
    return 0;
  }

  cout<<"Memory was successfully created"<<endl;
  memory->print();

  int id,limit;
  
  for(;;){
    int query_type;
    cout<<"Enter the query type (1- Allocate, 2- Deallocate, 3- Finish): ";
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
        memory->print();
      }
      else{
        cout<<"The process was not found"<<endl;
      }
    }else if(query_type==3){
        return 0;
    }else{
      cout<<"invalid query type\n";
    }
  }
}
