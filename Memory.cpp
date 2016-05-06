#include "Memory.h"
Memory::Memory(int memorySize)
{
	Block *b=new Block(0,memorySize);
	memoryLocations.insert(memoryLocations.end(),b);
}
Memory::Memory(std::vector<Block*>& initialBlocks)
{
  for(auto &i:initialBlocks)
    memoryLocations.insert(memoryLocations.end(),i);
}
bool Memory::deallocateMemory(int processID)
{
  for(auto it=memoryLocations.begin();it!=memoryLocations.end();it++){
    if((*it)->isOccupied()&&(*it)->getId()==processID){
      auto process=it;
      auto previous=it;
      auto next=it;

      int base=(*process)->getBase();
      int limit=(*process)->getLimit();

    if (it != memoryLocations.begin())
    {
      previous--;
      if (!(*previous)->isOccupied()){
        base = (*previous)->getBase();
        limit += (*previous)->getLimit();
        memoryLocations.erase(previous);
      }
    }

    if (it != --memoryLocations.end())
    {
      next++;
      if (!(*next)->isOccupied()){
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
  std::cout<<std::setw(36)<<std::setfill('_')<<"_"<<std::setfill(' ')<<std::endl;
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
  std::cout<<std::setw(36)<<std::setfill('-')<<"-"<<std::setfill(' ')<<std::endl;
}