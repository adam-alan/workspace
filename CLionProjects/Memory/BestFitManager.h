//
// Created by zhuxingtian on 19-6-8.
//

#ifndef MEMORY_BESTFITMANAGER_H
#define MEMORY_BESTFITMANAGER_H
#include "MemoryManager.h"
#include <list>

class BestFitManager final:public MemoryManager{
public:
    BestFitManager(int limitSize);
    virtual int memoryAlloc(int size) override ;
    virtual void memoryFree(FreeBlock freeBlock) override;
    virtual void memoryInit(int size) override ;
	virtual std::list<FreeBlock> & getfreeBlockList() override ;

private:
    std::list<FreeBlock> freeBlockList;
	std::size_t memorySize;
	std::size_t limitSize;
	bool doAlloc(FreeBlock & request);
};


#endif //MEMORY_BESTFITMANAGER_H
