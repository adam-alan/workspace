//
// Created by zhuxingtian on 19-6-8.
//

#ifndef MEMORY_MEMORYCONTROLLER_H
#define MEMORY_MEMORYCONTROLLER_H

#include "MemoryManager.h"
#include "MemoryView.h"
#include <memory>

class MemoryController {
public:
	MemoryController(const std::shared_ptr<MemoryManager> & memoryManager,const MemoryView & memoryView);

	void memoryInit(const std::size_t & size);
	int memoryAlloc(const std::size_t & size);
	void memoryFree(const FreeBlock & freeBlock);

	void updateView();

private:
	std::shared_ptr<MemoryManager> memoryManager;
	MemoryView memoryView;
};


#endif //MEMORY_MEMORYCONTROLLER_H
