//
// Created by zhuxingtian on 19-6-8.
//

#include "BestFitManager.h"

#include <iostream>
#include <string>


BestFitManager::BestFitManager(int limitSize)
		:limitSize(limitSize)
{

}

void BestFitManager::memoryInit(int size) {
	if (freeBlockList.empty() == true){
		this->memorySize = size;
		freeBlockList.push_back(FreeBlock(size, false,0));
	}
}
int BestFitManager::memoryAlloc(int size){
	FreeBlock request(size, true,0);
	freeBlockList.sort([](FreeBlock freeBlock1,FreeBlock freeBlock2)->bool {
		return freeBlock1.getSize() < freeBlock2.getSize();
	});

	if (doAlloc(request) == true){
		return request.getStartAddr();
	}

	return -1;
}


bool BestFitManager::doAlloc(FreeBlock & request) {
	for (auto iter = freeBlockList.begin();iter!= freeBlockList.end(); iter++){
		if (iter->getSize() > request.getSize() && iter->getAlloced() == false){
			//if =>多余部分太小,不用再切割
			//else =>多余部分需要切割
			if (iter->getSize() - request.getSize() <= limitSize){
				iter->setAlloced(true);
				request.setStartAddr(iter->getStartAddr());
				return true;
			} else {
				//std::cout << iter->getSize() << " " << iter->getAlloced() << " " << iter->getStartAddr() << std::endl;
				//切割空闲块
				request.setStartAddr(iter->getStartAddr());
				iter->setSize(iter->getSize() - request.getSize());
				iter->setStartAddr(iter->getStartAddr() + request.getSize());
				freeBlockList.insert(iter,request);
				return true;
			}
		}
	}

	return false;
}
void BestFitManager::memoryFree(FreeBlock freeBlock) {
	freeBlockList.sort([](FreeBlock freeBlock1,FreeBlock freeBlock2)->bool {
		return freeBlock1.getSize() < freeBlock2.getSize();
	});

	for (auto iter = freeBlockList.begin();iter != freeBlockList.end();iter++){
		//顺序查找合适的空闲块
		if (*iter == freeBlock){
			auto prev = std::prev(iter);
			auto next = std::next(iter);


			//不是第一个表目且与前一个空闲块相邻？ Yes:if No:else
			if (iter != freeBlockList.begin() && prev->getAlloced() == false){

				iter->setSize(prev->getSize() + iter->getSize());
				iter->setAlloced(false);
				iter->setStartAddr(prev->getStartAddr());
				freeBlockList.erase(prev);

				//与后一可用区相邻？ Yes:if No:else
				if (next->getAlloced() == false){
					iter->setSize(next->getSize() + iter->getSize());
					freeBlockList.erase(next);
					return;
				} else {
					return;
				}

			} else {
				//与后一可用分区相邻且不为空表目
				if (next->getAlloced() == false && next != freeBlockList.end()){
					//所释放的可用区与后一可用区合并
					iter->setSize(iter->getSize() + next->getSize());
					iter->setAlloced(false);
					return;
				} else {
					if (freeBlock.getSize() == 0){
						return;
					} else {
						iter->setAlloced(false);
						return;
					}
				}
			}

		}
	}
}

std::list<FreeBlock>& BestFitManager::getfreeBlockList(){
	return freeBlockList;
}