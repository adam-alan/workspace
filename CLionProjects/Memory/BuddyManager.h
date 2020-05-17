//
// Created by zhuxingtian on 19-6-9.
//

#ifndef MEMORY_BUDDYMANAGER_H
#define MEMORY_BUDDYMANAGER_H

#include "MemoryManager.h"
#include <vector>
class FreeBlockSpace{
public:
    std::size_t size;
    std::list<FreeBlock> freeBlockList;
};


class BuddyManager final:public MemoryManager{
public:
    BuddyManager(int limitSize);
    virtual int memoryAlloc(int size) override ;
    virtual void memoryFree(FreeBlock freeBlock) override;
    virtual void memoryInit(int size) override ;
    std::list<FreeBlock> & getfreeBlockList()override;
private:
    std::vector<FreeBlockSpace> freeBlockSpace;
    std::size_t memorySize;
    std::size_t limitSize;
    bool doAlloc(FreeBlock & request);
    bool isExist(FreeBlock node);

};


#endif //MEMORY_BUDDYMANAGER_H
