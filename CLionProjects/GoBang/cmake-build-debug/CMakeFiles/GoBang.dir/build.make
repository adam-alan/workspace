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
CMAKE_SOURCE_DIR = /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GoBang.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GoBang.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GoBang.dir/flags.make

CMakeFiles/GoBang.dir/main.cpp.o: CMakeFiles/GoBang.dir/flags.make
CMakeFiles/GoBang.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GoBang.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoBang.dir/main.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/main.cpp

CMakeFiles/GoBang.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoBang.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/main.cpp > CMakeFiles/GoBang.dir/main.cpp.i

CMakeFiles/GoBang.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoBang.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/main.cpp -o CMakeFiles/GoBang.dir/main.cpp.s

CMakeFiles/GoBang.dir/GameState.cpp.o: CMakeFiles/GoBang.dir/flags.make
CMakeFiles/GoBang.dir/GameState.cpp.o: ../GameState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GoBang.dir/GameState.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoBang.dir/GameState.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/GameState.cpp

CMakeFiles/GoBang.dir/GameState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoBang.dir/GameState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/GameState.cpp > CMakeFiles/GoBang.dir/GameState.cpp.i

CMakeFiles/GoBang.dir/GameState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoBang.dir/GameState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/GameState.cpp -o CMakeFiles/GoBang.dir/GameState.cpp.s

CMakeFiles/GoBang.dir/Player.cpp.o: CMakeFiles/GoBang.dir/flags.make
CMakeFiles/GoBang.dir/Player.cpp.o: ../Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GoBang.dir/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoBang.dir/Player.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/Player.cpp

CMakeFiles/GoBang.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoBang.dir/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/Player.cpp > CMakeFiles/GoBang.dir/Player.cpp.i

CMakeFiles/GoBang.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoBang.dir/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/Player.cpp -o CMakeFiles/GoBang.dir/Player.cpp.s

CMakeFiles/GoBang.dir/ComputerPlayer.cpp.o: CMakeFiles/GoBang.dir/flags.make
CMakeFiles/GoBang.dir/ComputerPlayer.cpp.o: ../ComputerPlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GoBang.dir/ComputerPlayer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoBang.dir/ComputerPlayer.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/ComputerPlayer.cpp

CMakeFiles/GoBang.dir/ComputerPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoBang.dir/ComputerPlayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/ComputerPlayer.cpp > CMakeFiles/GoBang.dir/ComputerPlayer.cpp.i

CMakeFiles/GoBang.dir/ComputerPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoBang.dir/ComputerPlayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/ComputerPlayer.cpp -o CMakeFiles/GoBang.dir/ComputerPlayer.cpp.s

CMakeFiles/GoBang.dir/Evaluator.cpp.o: CMakeFiles/GoBang.dir/flags.make
CMakeFiles/GoBang.dir/Evaluator.cpp.o: ../Evaluator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GoBang.dir/Evaluator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoBang.dir/Evaluator.cpp.o -c /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/Evaluator.cpp

CMakeFiles/GoBang.dir/Evaluator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoBang.dir/Evaluator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/Evaluator.cpp > CMakeFiles/GoBang.dir/Evaluator.cpp.i

CMakeFiles/GoBang.dir/Evaluator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoBang.dir/Evaluator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/Evaluator.cpp -o CMakeFiles/GoBang.dir/Evaluator.cpp.s

# Object files for target GoBang
GoBang_OBJECTS = \
"CMakeFiles/GoBang.dir/main.cpp.o" \
"CMakeFiles/GoBang.dir/GameState.cpp.o" \
"CMakeFiles/GoBang.dir/Player.cpp.o" \
"CMakeFiles/GoBang.dir/ComputerPlayer.cpp.o" \
"CMakeFiles/GoBang.dir/Evaluator.cpp.o"

# External object files for target GoBang
GoBang_EXTERNAL_OBJECTS =

GoBang: CMakeFiles/GoBang.dir/main.cpp.o
GoBang: CMakeFiles/GoBang.dir/GameState.cpp.o
GoBang: CMakeFiles/GoBang.dir/Player.cpp.o
GoBang: CMakeFiles/GoBang.dir/ComputerPlayer.cpp.o
GoBang: CMakeFiles/GoBang.dir/Evaluator.cpp.o
GoBang: CMakeFiles/GoBang.dir/build.make
GoBang: CMakeFiles/GoBang.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable GoBang"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GoBang.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GoBang.dir/build: GoBang

.PHONY : CMakeFiles/GoBang.dir/build

CMakeFiles/GoBang.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GoBang.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GoBang.dir/clean

CMakeFiles/GoBang.dir/depend:
	cd /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/cmake-build-debug /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/cmake-build-debug /home/zhuxingtian/WorkingSpace/CLionProjects/GoBang/cmake-build-debug/CMakeFiles/GoBang.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GoBang.dir/depend
