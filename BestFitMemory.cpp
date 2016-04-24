#include "BestFitMemory.h"

bool BestFitMemory::allocateMemory(int processID , int processSize)
{
	std::list<Block *>::iterator bestLocation = memoryLocations.end();
	for (std::list<Block *>::iterator blk = memoryLocations.begin(); blk != memoryLocations.end(); blk++)
	{
		if (!(*blk)->isOccupied())
		{
			if ((*blk)->getLimit() >= processSize)
			{
				if (bestLocation == memoryLocations.end())
					bestLocation = blk;
				else if ((*blk)->getLimit()<(*bestLocation)->getLimit())
				{
					bestLocation = blk;
				}
			}

		}
	}

	if (bestLocation != memoryLocations.end())
	{
		Process * p = new Process(processID, (*bestLocation)->getBase(), processSize);
		(*bestLocation)->setBase((*bestLocation)->getBase() + processSize);
		(*bestLocation)->setLimit((*bestLocation)->getLimit() - processSize);
		memoryLocations.insert(bestLocation, p);
		bestLocation++;
		if (bestLocation != memoryLocations.end() && (*bestLocation)->getLimit() == 0)
		{
			memoryLocations.erase(bestLocation);
		}
		return true;
	}
	return false;
}
