//
// Created by zhuxingtian on 19-6-8.
//

#ifndef MEMORY_WORSTFITMANAGER_H
#define MEMORY_WORSTFITMANAGER_H

#include "MemoryManager.h"

class WorstFitManager final:public MemoryManager{
public:
	WorstFitManager(int limitSize);
	virtual int memoryAlloc(int size) override ;
	virtual void memoryFree(FreeBlock freeBlock) override;
	virtual void memoryInit(int size) override ;
	std::list<FreeBlock> & getfreeBlockList()override;
private:
	std::list<FreeBlock> freeBlockList;
	std::size_t memorySize;
	std::size_t limitSize;
	bool doAlloc(FreeBlock & request);
};


#endif //MEMORY_WORSTFITMANAGER_H
