#include "Memory.h"
Memory::Memory()
{
	Block b(0,1024);
	memoryLocations.insert(memoryLocations.end(),&b);
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
