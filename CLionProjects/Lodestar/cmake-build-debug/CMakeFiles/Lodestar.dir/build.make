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
CMAKE_SOURCE_DIR = /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lodestar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lodestar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lodestar.dir/flags.make

CMakeFiles/Lodestar.dir/main.cpp.o: CMakeFiles/Lodestar.dir/flags.make
CMakeFiles/Lodestar.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lodestar.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lodestar.dir/main.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/main.cpp

CMakeFiles/Lodestar.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lodestar.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/main.cpp > CMakeFiles/Lodestar.dir/main.cpp.i

CMakeFiles/Lodestar.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lodestar.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/main.cpp -o CMakeFiles/Lodestar.dir/main.cpp.s

CMakeFiles/Lodestar.dir/reactor/Channel.cpp.o: CMakeFiles/Lodestar.dir/flags.make
CMakeFiles/Lodestar.dir/reactor/Channel.cpp.o: ../reactor/Channel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lodestar.dir/reactor/Channel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lodestar.dir/reactor/Channel.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/reactor/Channel.cpp

CMakeFiles/Lodestar.dir/reactor/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lodestar.dir/reactor/Channel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/reactor/Channel.cpp > CMakeFiles/Lodestar.dir/reactor/Channel.cpp.i

CMakeFiles/Lodestar.dir/reactor/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lodestar.dir/reactor/Channel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/reactor/Channel.cpp -o CMakeFiles/Lodestar.dir/reactor/Channel.cpp.s

CMakeFiles/Lodestar.dir/reactor/EventLoop.cpp.o: CMakeFiles/Lodestar.dir/flags.make
CMakeFiles/Lodestar.dir/reactor/EventLoop.cpp.o: ../reactor/EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Lodestar.dir/reactor/EventLoop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lodestar.dir/reactor/EventLoop.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/reactor/EventLoop.cpp

CMakeFiles/Lodestar.dir/reactor/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lodestar.dir/reactor/EventLoop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/reactor/EventLoop.cpp > CMakeFiles/Lodestar.dir/reactor/EventLoop.cpp.i

CMakeFiles/Lodestar.dir/reactor/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lodestar.dir/reactor/EventLoop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/reactor/EventLoop.cpp -o CMakeFiles/Lodestar.dir/reactor/EventLoop.cpp.s

CMakeFiles/Lodestar.dir/reactor/poller/Poller.cpp.o: CMakeFiles/Lodestar.dir/flags.make
CMakeFiles/Lodestar.dir/reactor/poller/Poller.cpp.o: ../reactor/poller/Poller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Lodestar.dir/reactor/poller/Poller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lodestar.dir/reactor/poller/Poller.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/reactor/poller/Poller.cpp

CMakeFiles/Lodestar.dir/reactor/poller/Poller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lodestar.dir/reactor/poller/Poller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/reactor/poller/Poller.cpp > CMakeFiles/Lodestar.dir/reactor/poller/Poller.cpp.i

CMakeFiles/Lodestar.dir/reactor/poller/Poller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lodestar.dir/reactor/poller/Poller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/reactor/poller/Poller.cpp -o CMakeFiles/Lodestar.dir/reactor/poller/Poller.cpp.s

CMakeFiles/Lodestar.dir/reactor/poller/PollPoller.cpp.o: CMakeFiles/Lodestar.dir/flags.make
CMakeFiles/Lodestar.dir/reactor/poller/PollPoller.cpp.o: ../reactor/poller/PollPoller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Lodestar.dir/reactor/poller/PollPoller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lodestar.dir/reactor/poller/PollPoller.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/reactor/poller/PollPoller.cpp

CMakeFiles/Lodestar.dir/reactor/poller/PollPoller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lodestar.dir/reactor/poller/PollPoller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/reactor/poller/PollPoller.cpp > CMakeFiles/Lodestar.dir/reactor/poller/PollPoller.cpp.i

CMakeFiles/Lodestar.dir/reactor/poller/PollPoller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lodestar.dir/reactor/poller/PollPoller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/reactor/poller/PollPoller.cpp -o CMakeFiles/Lodestar.dir/reactor/poller/PollPoller.cpp.s

CMakeFiles/Lodestar.dir/base/Buffer.cpp.o: CMakeFiles/Lodestar.dir/flags.make
CMakeFiles/Lodestar.dir/base/Buffer.cpp.o: ../base/Buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Lodestar.dir/base/Buffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lodestar.dir/base/Buffer.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/base/Buffer.cpp

CMakeFiles/Lodestar.dir/base/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lodestar.dir/base/Buffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/base/Buffer.cpp > CMakeFiles/Lodestar.dir/base/Buffer.cpp.i

CMakeFiles/Lodestar.dir/base/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lodestar.dir/base/Buffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/base/Buffer.cpp -o CMakeFiles/Lodestar.dir/base/Buffer.cpp.s

CMakeFiles/Lodestar.dir/base/TimeStamp.cpp.o: CMakeFiles/Lodestar.dir/flags.make
CMakeFiles/Lodestar.dir/base/TimeStamp.cpp.o: ../base/TimeStamp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Lodestar.dir/base/TimeStamp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lodestar.dir/base/TimeStamp.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/base/TimeStamp.cpp

CMakeFiles/Lodestar.dir/base/TimeStamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lodestar.dir/base/TimeStamp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/base/TimeStamp.cpp > CMakeFiles/Lodestar.dir/base/TimeStamp.cpp.i

CMakeFiles/Lodestar.dir/base/TimeStamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lodestar.dir/base/TimeStamp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/base/TimeStamp.cpp -o CMakeFiles/Lodestar.dir/base/TimeStamp.cpp.s

# Object files for target Lodestar
Lodestar_OBJECTS = \
"CMakeFiles/Lodestar.dir/main.cpp.o" \
"CMakeFiles/Lodestar.dir/reactor/Channel.cpp.o" \
"CMakeFiles/Lodestar.dir/reactor/EventLoop.cpp.o" \
"CMakeFiles/Lodestar.dir/reactor/poller/Poller.cpp.o" \
"CMakeFiles/Lodestar.dir/reactor/poller/PollPoller.cpp.o" \
"CMakeFiles/Lodestar.dir/base/Buffer.cpp.o" \
"CMakeFiles/Lodestar.dir/base/TimeStamp.cpp.o"

# External object files for target Lodestar
Lodestar_EXTERNAL_OBJECTS =

Lodestar: CMakeFiles/Lodestar.dir/main.cpp.o
Lodestar: CMakeFiles/Lodestar.dir/reactor/Channel.cpp.o
Lodestar: CMakeFiles/Lodestar.dir/reactor/EventLoop.cpp.o
Lodestar: CMakeFiles/Lodestar.dir/reactor/poller/Poller.cpp.o
Lodestar: CMakeFiles/Lodestar.dir/reactor/poller/PollPoller.cpp.o
Lodestar: CMakeFiles/Lodestar.dir/base/Buffer.cpp.o
Lodestar: CMakeFiles/Lodestar.dir/base/TimeStamp.cpp.o
Lodestar: CMakeFiles/Lodestar.dir/build.make
Lodestar: CMakeFiles/Lodestar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Lodestar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lodestar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lodestar.dir/build: Lodestar

.PHONY : CMakeFiles/Lodestar.dir/build

CMakeFiles/Lodestar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lodestar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lodestar.dir/clean

CMakeFiles/Lodestar.dir/depend:
	cd /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/cmake-build-debug /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/cmake-build-debug /home/zhuxingtian/WorkingSpace/CLionProjects/Lodestar/cmake-build-debug/CMakeFiles/Lodestar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lodestar.dir/depend
