#include "Memory.h"
Memory::Memory()
{
	Block *b=new Block(0,1024);
	memoryLocations.insert(memoryLocations.end(),b);
}
bool Memory::deallocateMemory(int processID)
{
	/*
	for(std::list<Block *>::iterator blk=memoryLocations.begin();blk!=memoryLocations.end();blk++)
	{
		if((*blk).isOccupied())
		{
			if((*blk).getId()==processID)
			{
				Block b((*blk).getBase(),(*blk).getLimit());
				//check if block before is a hole
				
				return true;
			}	
		}
	}
	*/
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