//
// Created by zhuxingtian on 19-6-9.
//

#include "BuddyManager.h"
#include <cmath>
#include <iostream>

BuddyManager::BuddyManager(int limitSize)
:limitSize(limitSize){

}


void BuddyManager::memoryInit(int size) {
    int nums = static_cast<int>(log2(size));
    printf("%d\n",nums);
    freeBlockSpace[nums].freeBlockList.push_back(FreeBlock(nums, false,0));
}

int BuddyManager::memoryAlloc(int size) {

}

void BuddyManager::memoryFree(FreeBlock freeBlock) {
    FreeBlock node(false,freeBlock.getSize(),freeBlock.getStartAddr());
    bool canMerge = true;
    std::size_t size = freeBlock.getSize();

    while (size != freeBlockSpace.size() && canMerge){
        std::size_t buddyAddr = 0;
        std::size_t num1 = static_cast<std::size_t >(std::exp2(node.getSize() + 1));
        std::size_t num2 = static_cast<std::size_t >(std::exp2(node.getSize()));

        if (freeBlock.getStartAddr() % num1 == 0){
            buddyAddr = node.getStartAddr() + num2;
        } else if (node.getStartAddr() % num1 == num2){
            buddyAddr = node.getStartAddr() - num2;
        }

        std::cout << buddyAddr << std::endl;

        FreeBlock buddy(node.getAlloced(),node.getSize(),buddyAddr);

        if (isExist(buddy) == false){
            canMerge = false;
        } else {
            //从空闲链表中擦除伙伴

            for (auto iter = freeBlockSpace[node.getSize()].freeBlockList.begin();
                 iter != freeBlockSpace[node.getSize()].freeBlockList.end();
                 iter++)
            {
                if (*iter == buddy){
                    freeBlockSpace[node.getSize()].freeBlockList.erase(iter);
                    break;
                }

            }
            node.setAlloced(false);
            node.setSize(node.getSize() + 1);
            node.setStartAddr(std::min(node.getStartAddr(),buddy.getStartAddr()));

        }

    }
    freeBlockSpace[node.getSize()].freeBlockList.push_front(node);
}


bool BuddyManager::isExist(FreeBlock node) {

    for (auto iter = freeBlockSpace[node.getSize()].freeBlockList.begin();
            iter != freeBlockSpace[node.getSize()].freeBlockList.end();
            iter++)
    {
        if (*iter == node){
            return true;
        }
    }
    return false;
}


bool BuddyManager::doAlloc(FreeBlock &request) {
    int k = 0;
    //找到合适的分配节点

    for(;(k <= freeBlockSpace.size() &&
            (freeBlockSpace[k].size < k) || freeBlockSpace[k].freeBlockList.empty());k++);
    //从空闲链表中擦除节点
    request = *freeBlockSpace[k].freeBlockList.begin();
    freeBlockSpace[k].freeBlockList.pop_front();
    int i = 1;
    for (;freeBlockSpace[k-i].size >= request.getSize();i++){
        FreeBlock tmp(false,k-i,request.getStartAddr() + exp2(k - i));
        freeBlockSpace[k-i].freeBlockList.push_front(tmp);
    }
    request.setAlloced(true);
    i -= 1;
    request.setSize(k-i);

}

std::list<FreeBlock>& BuddyManager::getfreeBlockList() {

}