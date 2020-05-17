//
// Created by zhuxingtian on 19-6-8.
//

#ifndef MEMORY_MEMORYMANAGERFACTORY_H
#define MEMORY_MEMORYMANAGERFACTORY_H

#include "FirstFitManager.h"
#include "BestFitManager.h"
#include "MemoryManager.h"
#include <string>
#include <memory>
class MemoryManagerFactory final{
public:
	std::shared_ptr<MemoryManager> createMemoryManager(std::size_t memoryManger);
};


#endif //MEMORY_MEMORYMANAGERFACTORY_H
