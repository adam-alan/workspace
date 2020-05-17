cmake_minimum_required(VERSION 3.14)
project(Lodestar)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_executable(Lodestar main.cpp reactor/Channel.cpp reactor/Channel.h reactor/EventLoop.cpp reactor/EventLoop.h reactor/poller/Poller.cpp reactor/poller/Poller.h base/NoCopyable.h base/Copyable.h reactor/poller/PollPoller.cpp reactor/poller/PollPoller.h base/Buffer.cpp base/Buffer.h base/TimeStamp.cpp base/TimeStamp.h)