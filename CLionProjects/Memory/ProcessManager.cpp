//
// Created by zhuxingtian on 19-6-8.
//

#include "ProcessManager.h"

ProcessManager::ProcessManager(const ProcessView & _processView)
:processView(_processView){

}

bool ProcessManager::processCreate(MemoryController &memoryController,std::size_t size) {
	std::string name = "process";
	static std::size_t pid;
	pid++;
	name = name + std::to_string(pid);

	ProcessControlBlock processControlBlock(pid,name,size,0);

	std::size_t startAddr = memoryController.memoryAlloc(size);
	processControlBlock.setStartAddr(startAddr);
	if (processControlBlock.getStartAddr() == -1){
		return false;
	} else {
		processList.push_back(processControlBlock);
		return true;
	}
	return false;
}


std::list<ProcessControlBlock>::iterator
ProcessManager::findProcess(const std::size_t & pid) {
	for (auto iter = processList.begin();iter != processList.end();iter++){
		if (iter->getPid() == pid){
			return iter;
		}
	}
	return processList.end();
}

bool ProcessManager::killProcess(MemoryController &memoryController,const std::size_t & pid) {
	auto iter = this->findProcess(pid);
	FreeBlock freeBlock(iter->getSize(),true,iter->getStartAddr());

	if (iter != processList.end()){
		this->processList.erase(iter);
		memoryController.memoryFree(freeBlock);
		return true;
	}

	return false;
}

std::list<ProcessControlBlock> ProcessManager::getProcessList() {
	return this->processList;
}

void ProcessManager::updateView() {
	processView.showProcess(processList);
}