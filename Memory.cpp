#include "Memory.h"
Memory::Memory()
{
	Block b(0,1024);
	memoryLocations.insert(memoryLocations.end(),b);
}
bool Memory::deallocateMemory(int processID)
{
	for(int blockIndex=0;blockIndex<memoryLocations.size();blockIndex++)
	{
		//check if block has id 
	}
}
