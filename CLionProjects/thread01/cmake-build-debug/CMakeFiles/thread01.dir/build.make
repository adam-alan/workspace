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
CMAKE_SOURCE_DIR = /home/zhuxingtian/WorkingSpace/CLionProjects/thread01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhuxingtian/WorkingSpace/CLionProjects/thread01/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/thread01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/thread01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/thread01.dir/flags.make

CMakeFiles/thread01.dir/main.cpp.o: CMakeFiles/thread01.dir/flags.make
CMakeFiles/thread01.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/thread01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/thread01.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/thread01.dir/main.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/thread01/main.cpp

CMakeFiles/thread01.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thread01.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/thread01/main.cpp > CMakeFiles/thread01.dir/main.cpp.i

CMakeFiles/thread01.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thread01.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/thread01/main.cpp -o CMakeFiles/thread01.dir/main.cpp.s

CMakeFiles/thread01.dir/threadsafe_quene.cpp.o: CMakeFiles/thread01.dir/flags.make
CMakeFiles/thread01.dir/threadsafe_quene.cpp.o: ../threadsafe_quene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/thread01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/thread01.dir/threadsafe_quene.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/thread01.dir/threadsafe_quene.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/thread01/threadsafe_quene.cpp

CMakeFiles/thread01.dir/threadsafe_quene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thread01.dir/threadsafe_quene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/thread01/threadsafe_quene.cpp > CMakeFiles/thread01.dir/threadsafe_quene.cpp.i

CMakeFiles/thread01.dir/threadsafe_quene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thread01.dir/threadsafe_quene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/thread01/threadsafe_quene.cpp -o CMakeFiles/thread01.dir/threadsafe_quene.cpp.s

# Object files for target thread01
thread01_OBJECTS = \
"CMakeFiles/thread01.dir/main.cpp.o" \
"CMakeFiles/thread01.dir/threadsafe_quene.cpp.o"

# External object files for target thread01
thread01_EXTERNAL_OBJECTS =

thread01: CMakeFiles/thread01.dir/main.cpp.o
thread01: CMakeFiles/thread01.dir/threadsafe_quene.cpp.o
thread01: CMakeFiles/thread01.dir/build.make
thread01: CMakeFiles/thread01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/thread01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable thread01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thread01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/thread01.dir/build: thread01

.PHONY : CMakeFiles/thread01.dir/build

CMakeFiles/thread01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/thread01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/thread01.dir/clean

CMakeFiles/thread01.dir/depend:
	cd /home/zhuxingtian/WorkingSpace/CLionProjects/thread01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhuxingtian/WorkingSpace/CLionProjects/thread01 /home/zhuxingtian/WorkingSpace/CLionProjects/thread01 /home/zhuxingtian/WorkingSpace/CLionProjects/thread01/cmake-build-debug /home/zhuxingtian/WorkingSpace/CLionProjects/thread01/cmake-build-debug /home/zhuxingtian/WorkingSpace/CLionProjects/thread01/cmake-build-debug/CMakeFiles/thread01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/thread01.dir/depend

