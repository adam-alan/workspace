cmake_minimum_required(VERSION 3.14)
project(Memory)

set(CMAKE_CXX_STANDARD 17)

add_executable(Memory main.cpp MemoryManager.h FirstFitManager.cpp FirstFitManager.h MemoryManager.cpp BestFitManager.cpp BestFitManager.h MemoryView.cpp MemoryView.h MemoryController.cpp MemoryController.h MemoryManagerFactory.cpp MemoryManagerFactory.h WorstFitManager.cpp WorstFitManager.h ProcessControlBlock.h ProcessManager.cpp ProcessManager.h ProcessView.cpp ProcessView.h BuddyManager.cpp BuddyManager.h)