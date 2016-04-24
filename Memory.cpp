#include "Memory.h"
Memory::Memory()
{
	Block *b=new Block(0,1024);
	memoryLocations.insert(memoryLocations.end(),b);
}
bool Memory::deallocateMemory(int processID)
{
  for(auto it=memoryLocations.begin();it!=memoryLocations.end();it++){
    if((*it)->isOccupied()&&(*it)->getId()==processID){
      auto process=it;
	  auto previous = it,next=it;	 

      int base=(*process)->getBase();
      int limit=(*process)->getLimit();

	  if (it != memoryLocations.begin())
	  {
		  previous--;
		  if ((*previous) != NULL&&!(*previous)->isOccupied()){
			  base = (*previous)->getBase();
			  limit += (*process)->getLimit();
			  memoryLocations.erase(previous);
		  }
	  }

	  if (it != --memoryLocations.end())
	  {
		  next++;
		  if ((*next) != NULL&&!(*next)->isOccupied()){
			  limit += (*next)->getLimit();
			  memoryLocations.erase(next);
		  }
	  }

      Block * b = new Block(base,limit);
      memoryLocations.insert(process,b);
      memoryLocations.erase(process);
      return true;
    }
  }
	return false;
}
void Memory::print(){
  std::cout<<std::setw(10)<<std::left<<"Location"<<"|"<<"State"<<std::endl;
  std::cout<<std::setfill('-')<<std::setw(10)<<"-"<<"+"<<std::setw(25)<<"-"<<std::setfill(' ')<<std::endl;
  for(auto i:memoryLocations){
    std::cout<<std::setw(10)<<std::to_string(i->getBase())+"->"+std::to_string(i->getBase()+i->getLimit()-1)<<"|";
    if(i->isOccupied()){
      std::cout<<"Ocuupied by Process "<<i->getId()<<std::endl;
    }else{
      std::cout<<"free"<<std::endl;
    }
  }
}