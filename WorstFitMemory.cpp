#include "WorstFitMemory.h"
#include "Process.h"
WorstFitMemory::WorstFitMemory(int memorySize):Memory(memorySize)
{

}
bool WorstFitMemory::allocateMemory(int processID, int processSize)
{
	std::list<Block *>::iterator worstLocation = memoryLocations.end();
	for (std::list<Block *>::iterator blk = memoryLocations.begin(); blk != memoryLocations.end(); blk++)
	{
		if (!(*blk)->isOccupied())
		{
			if ((*blk)->getLimit() >= processSize)
			{
				if (worstLocation == memoryLocations.end())
					worstLocation = blk;
				else if ((*blk)->getLimit()>(*worstLocation)->getLimit())
				{
					worstLocation = blk;
				}
			}

		}
	}

	if (worstLocation != memoryLocations.end())
	{
		Process * p = new Process(processID, (*worstLocation)->getBase(), processSize);
		(*worstLocation)->setBase((*worstLocation)->getBase() + processSize);
		(*worstLocation)->setLimit((*worstLocation)->getLimit() - processSize);
		memoryLocations.insert(worstLocation, p);
		if ((*worstLocation)->getLimit() == 0)
		{
			memoryLocations.erase(worstLocation);
		}
		return true;
	}
	return false;
}