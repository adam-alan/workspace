//
// Created by zhuxingtian on 19-6-7.
//

#ifndef MEMORY_FIRSTFITMANAGER_H
#define MEMORY_FIRSTFITMANAGER_H

#include "MemoryManager.h"
#include <list>

class FirstFitManager final: public MemoryManager{
public:
    FirstFitManager(int limitSize);
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


#endif //MEMORY_FIRSTFITMANAGER_H
