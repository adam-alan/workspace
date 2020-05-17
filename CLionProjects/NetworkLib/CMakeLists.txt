cmake_minimum_required(VERSION 3.14)
project(NetworkLib)

set(CMAKE_CXX_STANDARD 17)


add_executable(NetworkLib main.cpp base/buffer.cc base/buffer.h data_struct/binary_tree.h base/socket_native_api.cc base/socket_native_api.h base/inet_address.cc base/inet_address.h net/inet_address.cc net/inet_address.h base/log_stream.cc base/log_stream.h base/logger.cc base/logger.h base/fixedbuffer.cc base/fixedbuffer.h)