#include "FirstFitMemory.h"
FirstFitMemory::FirstFitMemory(int memorySize):Memory(memorySize) {}
FirstFitMemory::FirstFitMemory(std::vector<Block*>& initialBlocks):Memory(initialBlocks) {}
bool FirstFitMemory::allocateMemory(int processID , int processSize)
{
	for(std::list<Block *>::iterator blk=memoryLocations.begin();blk!=memoryLocations.end();blk++)
	{
		if(!(*blk)->isOccupied())
		{
			if((*blk)->getLimit()>processSize)
			{
				Process * p=new Process(processID,(*blk)->getBase(),processSize);
				(*blk)->setBase((*blk)->getBase()+processSize);
				(*blk)->setLimit((*blk)->getLimit()-processSize);
				memoryLocations.insert(blk,p);
				return true;
			}
			else if((*blk)->getLimit()==processSize)
			{
				Process *p=new Process(processID,(*blk)->getBase(),processSize);
				memoryLocations.insert(blk,p);
				memoryLocations.erase(blk);
				return true;
			}
		}
	}
	return false;
}