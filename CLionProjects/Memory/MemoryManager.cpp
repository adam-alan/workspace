//
// Created by zhuxingtian on 19-6-7.
//
#include "MemoryManager.h"

FreeBlock::FreeBlock(int size,bool Alloced,int startAddr)
        :size(size),Alloced(Alloced),startAddr(startAddr)
{
}

bool FreeBlock::operator==(const FreeBlock & other) const {
    return  (this->getSize() == other.getSize() &&
             this->getAlloced() == other.getAlloced() &&
             this->getStartAddr() == other.getStartAddr());
}

int FreeBlock::getSize() const {
    return size;
}

void FreeBlock::setSize(int size) {
    this->size = size;
}

bool FreeBlock::getAlloced() const {
    return Alloced;
}

void FreeBlock::setAlloced(bool alloced) {
    this->Alloced = alloced;
}

int FreeBlock::getStartAddr() const {
    return startAddr;
}

void FreeBlock::setStartAddr(int startAddr) {
    this->startAddr = startAddr;
}
