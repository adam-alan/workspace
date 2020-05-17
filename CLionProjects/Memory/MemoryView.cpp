//
// Created by zhuxingtian on 19-6-8.
//

#include "MemoryView.h"
#include <iostream>

void MemoryView::showMemory(std::list<FreeBlock> model) {

	printf("%-16s%-16s%-16s\n","Size","isAlloced","StartAddr");
	for (FreeBlock freeBlock:model) {
		printf("%-16s%-16s%-16s\n",std::to_string(freeBlock.getSize()).c_str(),
		       std::to_string(freeBlock.getAlloced()).c_str(),
		       std::to_string(freeBlock.getStartAddr()).c_str());
	}

}