//
// Created by zhuxingtian on 19-6-8.
//

#ifndef MEMORY_PROCESSCONTROLBLOCK_H
#define MEMORY_PROCESSCONTROLBLOCK_H

#include <iostream>
#include <string>
class ProcessControlBlock {
private:
	std::size_t pid;
	std::string name;
	std::size_t size;
	std::size_t startAddr;
public:
	ProcessControlBlock(std::size_t pid,
						std::string name,
						std::size_t size,
						std::size_t startAddr)
	:pid(pid),name(name),size(size),startAddr(startAddr){

	}
	void setPid(std::size_t pid){
		this->pid = pid;
	}
	std::size_t getPid() const {
		return this->pid;
	}
	void setName(std::string name){
		this->name = name;
	}
	std::string getName() const {
		return this->name;
	}
	void setSize(std::size_t size){
		this->size = size;
	}
	std::size_t getSize()const {
		return this->size;
	}
	void setStartAddr(std::size_t startAddr){
		this->startAddr = startAddr;
	}
	std::size_t getStartAddr() const {
		return this->startAddr;
	}
};


#endif //MEMORY_PROCESSCONTROLBLOCK_H
