//
// Created by zhuxingtian on 19-6-8.
//

#include "MemoryManagerFactory.h"


std::shared_ptr<MemoryManager> MemoryManagerFactory::createMemoryManager(std::size_t memoryManger) {
	switch (memoryManger){
		case 1:
			return std::make_shared<FirstFitManager>(20);
			break;
		case 2:
			return std::make_shared<BestFitManager>(20);
			break;
	}
}