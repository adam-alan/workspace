//
// Created by zhuxingtian on 19-6-7.
//

#ifndef MEMORY_MEMORYMANAGER_H
#define MEMORY_MEMORYMANAGER_H

#include <list>
class FreeBlock final{
private:
    int size;
    bool Alloced;
    int startAddr;

public:
    FreeBlock(int size,bool Alloced,int startAddr);
    bool operator==(const FreeBlock & other) const;
    int getSize() const;
    void setSize(int size);
    bool getAlloced() const ;
    void setAlloced(bool alloced);
    int getStartAddr() const ;
    void setStartAddr(int startAddr);
};

class MemoryManager {
public:
    virtual int memoryAlloc(int size) = 0;
    virtual void memoryFree(FreeBlock freeBlock) = 0;
    virtual void memoryInit(int size) = 0;
	virtual std::list<FreeBlock> & getfreeBlockList() = 0;

};


#endif //MEMORY_MEMORYMANAGER_H
