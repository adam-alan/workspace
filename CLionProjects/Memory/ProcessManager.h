//
// Created by zhuxingtian on 19-6-8.
//

#ifndef MEMORY_PROCESSMANAGER_H
#define MEMORY_PROCESSMANAGER_H

#include "ProcessControlBlock.h"
#include "MemoryController.h"
#include "ProcessView.h"
#include <list>

class ProcessManager {
public:
	ProcessManager(const ProcessView & _processView);
	bool processCreate(MemoryController & memoryController,std::size_t size);
	bool killProcess(MemoryController & memoryController,const std::size_t & pid);
	std::list<ProcessControlBlock>::iterator findProcess(const std::size_t & pid);
	std::list<ProcessControlBlock> getProcessList();
	void updateView();
private:
	std::list<ProcessControlBlock> processList;
	ProcessView processView;
};


#endif //MEMORY_PROCESSMANAGER_H
