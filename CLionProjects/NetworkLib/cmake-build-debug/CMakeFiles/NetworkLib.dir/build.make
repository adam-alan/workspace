# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/zhuxingtian/Applications/Programming/IDE/CLion-2019.1.4/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zhuxingtian/Applications/Programming/IDE/CLion-2019.1.4/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NetworkLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NetworkLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NetworkLib.dir/flags.make

CMakeFiles/NetworkLib.dir/main.cpp.o: CMakeFiles/NetworkLib.dir/flags.make
CMakeFiles/NetworkLib.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NetworkLib.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NetworkLib.dir/main.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/main.cpp

CMakeFiles/NetworkLib.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetworkLib.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/main.cpp > CMakeFiles/NetworkLib.dir/main.cpp.i

CMakeFiles/NetworkLib.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetworkLib.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/main.cpp -o CMakeFiles/NetworkLib.dir/main.cpp.s

CMakeFiles/NetworkLib.dir/base/buffer.cc.o: CMakeFiles/NetworkLib.dir/flags.make
CMakeFiles/NetworkLib.dir/base/buffer.cc.o: ../base/buffer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NetworkLib.dir/base/buffer.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NetworkLib.dir/base/buffer.cc.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/buffer.cc

CMakeFiles/NetworkLib.dir/base/buffer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetworkLib.dir/base/buffer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/buffer.cc > CMakeFiles/NetworkLib.dir/base/buffer.cc.i

CMakeFiles/NetworkLib.dir/base/buffer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetworkLib.dir/base/buffer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/buffer.cc -o CMakeFiles/NetworkLib.dir/base/buffer.cc.s

CMakeFiles/NetworkLib.dir/base/socket_native_api.cc.o: CMakeFiles/NetworkLib.dir/flags.make
CMakeFiles/NetworkLib.dir/base/socket_native_api.cc.o: ../base/socket_native_api.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/NetworkLib.dir/base/socket_native_api.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NetworkLib.dir/base/socket_native_api.cc.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/socket_native_api.cc

CMakeFiles/NetworkLib.dir/base/socket_native_api.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetworkLib.dir/base/socket_native_api.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/socket_native_api.cc > CMakeFiles/NetworkLib.dir/base/socket_native_api.cc.i

CMakeFiles/NetworkLib.dir/base/socket_native_api.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetworkLib.dir/base/socket_native_api.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/socket_native_api.cc -o CMakeFiles/NetworkLib.dir/base/socket_native_api.cc.s

CMakeFiles/NetworkLib.dir/base/inet_address.cc.o: CMakeFiles/NetworkLib.dir/flags.make
CMakeFiles/NetworkLib.dir/base/inet_address.cc.o: ../base/inet_address.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/NetworkLib.dir/base/inet_address.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NetworkLib.dir/base/inet_address.cc.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/inet_address.cc

CMakeFiles/NetworkLib.dir/base/inet_address.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetworkLib.dir/base/inet_address.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/inet_address.cc > CMakeFiles/NetworkLib.dir/base/inet_address.cc.i

CMakeFiles/NetworkLib.dir/base/inet_address.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetworkLib.dir/base/inet_address.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/inet_address.cc -o CMakeFiles/NetworkLib.dir/base/inet_address.cc.s

CMakeFiles/NetworkLib.dir/net/inet_address.cc.o: CMakeFiles/NetworkLib.dir/flags.make
CMakeFiles/NetworkLib.dir/net/inet_address.cc.o: ../net/inet_address.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/NetworkLib.dir/net/inet_address.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NetworkLib.dir/net/inet_address.cc.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/net/inet_address.cc

CMakeFiles/NetworkLib.dir/net/inet_address.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetworkLib.dir/net/inet_address.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/net/inet_address.cc > CMakeFiles/NetworkLib.dir/net/inet_address.cc.i

CMakeFiles/NetworkLib.dir/net/inet_address.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetworkLib.dir/net/inet_address.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/net/inet_address.cc -o CMakeFiles/NetworkLib.dir/net/inet_address.cc.s

CMakeFiles/NetworkLib.dir/base/log_stream.cc.o: CMakeFiles/NetworkLib.dir/flags.make
CMakeFiles/NetworkLib.dir/base/log_stream.cc.o: ../base/log_stream.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/NetworkLib.dir/base/log_stream.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NetworkLib.dir/base/log_stream.cc.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/log_stream.cc

CMakeFiles/NetworkLib.dir/base/log_stream.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetworkLib.dir/base/log_stream.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/log_stream.cc > CMakeFiles/NetworkLib.dir/base/log_stream.cc.i

CMakeFiles/NetworkLib.dir/base/log_stream.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetworkLib.dir/base/log_stream.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/log_stream.cc -o CMakeFiles/NetworkLib.dir/base/log_stream.cc.s

CMakeFiles/NetworkLib.dir/base/logger.cc.o: CMakeFiles/NetworkLib.dir/flags.make
CMakeFiles/NetworkLib.dir/base/logger.cc.o: ../base/logger.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/NetworkLib.dir/base/logger.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NetworkLib.dir/base/logger.cc.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/logger.cc

CMakeFiles/NetworkLib.dir/base/logger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetworkLib.dir/base/logger.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/logger.cc > CMakeFiles/NetworkLib.dir/base/logger.cc.i

CMakeFiles/NetworkLib.dir/base/logger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetworkLib.dir/base/logger.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/logger.cc -o CMakeFiles/NetworkLib.dir/base/logger.cc.s

CMakeFiles/NetworkLib.dir/base/fixedbuffer.cc.o: CMakeFiles/NetworkLib.dir/flags.make
CMakeFiles/NetworkLib.dir/base/fixedbuffer.cc.o: ../base/fixedbuffer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/NetworkLib.dir/base/fixedbuffer.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NetworkLib.dir/base/fixedbuffer.cc.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/fixedbuffer.cc

CMakeFiles/NetworkLib.dir/base/fixedbuffer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetworkLib.dir/base/fixedbuffer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/fixedbuffer.cc > CMakeFiles/NetworkLib.dir/base/fixedbuffer.cc.i

CMakeFiles/NetworkLib.dir/base/fixedbuffer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetworkLib.dir/base/fixedbuffer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/base/fixedbuffer.cc -o CMakeFiles/NetworkLib.dir/base/fixedbuffer.cc.s

# Object files for target NetworkLib
NetworkLib_OBJECTS = \
"CMakeFiles/NetworkLib.dir/main.cpp.o" \
"CMakeFiles/NetworkLib.dir/base/buffer.cc.o" \
"CMakeFiles/NetworkLib.dir/base/socket_native_api.cc.o" \
"CMakeFiles/NetworkLib.dir/base/inet_address.cc.o" \
"CMakeFiles/NetworkLib.dir/net/inet_address.cc.o" \
"CMakeFiles/NetworkLib.dir/base/log_stream.cc.o" \
"CMakeFiles/NetworkLib.dir/base/logger.cc.o" \
"CMakeFiles/NetworkLib.dir/base/fixedbuffer.cc.o"

# External object files for target NetworkLib
NetworkLib_EXTERNAL_OBJECTS =

NetworkLib: CMakeFiles/NetworkLib.dir/main.cpp.o
NetworkLib: CMakeFiles/NetworkLib.dir/base/buffer.cc.o
NetworkLib: CMakeFiles/NetworkLib.dir/base/socket_native_api.cc.o
NetworkLib: CMakeFiles/NetworkLib.dir/base/inet_address.cc.o
NetworkLib: CMakeFiles/NetworkLib.dir/net/inet_address.cc.o
NetworkLib: CMakeFiles/NetworkLib.dir/base/log_stream.cc.o
NetworkLib: CMakeFiles/NetworkLib.dir/base/logger.cc.o
NetworkLib: CMakeFiles/NetworkLib.dir/base/fixedbuffer.cc.o
NetworkLib: CMakeFiles/NetworkLib.dir/build.make
NetworkLib: CMakeFiles/NetworkLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable NetworkLib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NetworkLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NetworkLib.dir/build: NetworkLib

.PHONY : CMakeFiles/NetworkLib.dir/build

CMakeFiles/NetworkLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NetworkLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NetworkLib.dir/clean

CMakeFiles/NetworkLib.dir/depend:
	cd /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/cmake-build-debug /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/cmake-build-debug /home/zhuxingtian/WorkingSpace/CLionProjects/NetworkLib/cmake-build-debug/CMakeFiles/NetworkLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NetworkLib.dir/depend
