cmake_minimum_required(VERSION 3.14)
project(GoBang)

set(CMAKE_CXX_STANDARD 17)

add_executable(GoBang main.cpp GameState.h GameState.cpp ACSymbolTable.h TrieSymbolTable.h Player.h Player.cpp ComputerPlayer.h ComputerPlayer.cpp Evaluator.cpp Evaluator.h)