//
// Created by zhuxingtian on 19-6-8.
//

#include "MemoryController.h"
#include "FirstFitManager.h"
MemoryController::MemoryController(const std::shared_ptr<MemoryManager> & memoryManager, const MemoryView & memoryView) {
	this->memoryManager = memoryManager;
	this->memoryView = memoryView;
}

void MemoryController::memoryInit(const std::size_t & size) {
	this->memoryManager->memoryInit(size);
}

int MemoryController::memoryAlloc(const std::size_t &size) {
	return this->memoryManager->memoryAlloc(size);
}

void MemoryController::memoryFree(const FreeBlock & freeBlock) {
	this->memoryManager->memoryFree(freeBlock);
}

void MemoryController::updateView() {
	this->memoryView.showMemory(memoryManager->getfreeBlockList());
}
