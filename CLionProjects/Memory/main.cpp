

#include "MemoryController.h"

#include "MemoryManagerFactory.h"
#include "ProcessManager.h"
#include "ProcessView.h"
#include <iostream>

#include <map>
#include <string>


#include "BuddyManager.h"
void display_menu();

int main() {
    /*
	std::map<std::string,std::size_t> dict;
	dict.insert(std::pair<std::string,std::size_t>("FirstFitManager",1));
	dict.insert(std::pair<std::string,std::size_t>("BestFitManager",2));
	dict.insert(std::pair<std::string,std::size_t>("WorstFitManager",3));

	MemoryView memoryView;
	MemoryManagerFactory factory;
	ProcessView processView;
	ProcessManager processManager(processView);

	std::shared_ptr<MemoryManager> memoryManger = factory.createMemoryManager(dict["FirstFitManager"]);

	MemoryController memoryController(memoryManger,memoryView);

	memoryController.memoryInit(4096);

	for (int i = 1;i <= 9;i++){
		processManager.processCreate(memoryController,100);
	}
	memoryController.updateView();
	processManager.updateView();

	for (int i = 1;i <= 9;i++){
		processManager.killProcess(memoryController,i);
	}
	memoryController.updateView();
	processManager.updateView();
    */
    BuddyManager buddyManager(20);

    return 0;
}

void display_menu(){
	std::cout << "1 - set memory size(default = " << 4096 << ")" << std::endl;
	std::cout << "2 - select memory allocation algorithm" << std::endl;
	std::cout << "3 - new process" << std::endl;
	std::cout << "4 - terminate a process" << std::endl;
	std::cout << "5 - display memory usage" << std::endl;
}


