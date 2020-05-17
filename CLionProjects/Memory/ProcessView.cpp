//
// Created by zhuxingtian on 19-6-8.
//

#include "ProcessView.h"
#include <iostream>


void ProcessView::showProcess(const std::list<ProcessControlBlock> & model) {
	printf("%-16s%-16s%-16s%-16s\n","pid","name","size","startAddr");

	for (ProcessControlBlock iter:model){
		printf("%-16lu%-16s%-16lu%-16lu\n",
				iter.getPid(),
				iter.getName().c_str(),
				iter.getSize(),
				iter.getStartAddr());
	}

}