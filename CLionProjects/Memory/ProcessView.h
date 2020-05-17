//
// Created by zhuxingtian on 19-6-8.
//

#ifndef MEMORY_PROCESSVIEW_H
#define MEMORY_PROCESSVIEW_H

#include "ProcessControlBlock.h"
#include <list>

class ProcessView{
public:
	void showProcess(const std::list<ProcessControlBlock> & model);
};


#endif //MEMORY_PROCESSVIEW_H
