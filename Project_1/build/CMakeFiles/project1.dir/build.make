# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1/build"

# Include any dependencies generated for this target.
include CMakeFiles/project1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project1.dir/flags.make

CMakeFiles/project1.dir/src/main.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/project1.dir/src/main.cpp.o: CMakeFiles/project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project1.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project1.dir/src/main.cpp.o -MF CMakeFiles/project1.dir/src/main.cpp.o.d -o CMakeFiles/project1.dir/src/main.cpp.o -c "/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1/src/main.cpp"

CMakeFiles/project1.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1/src/main.cpp" > CMakeFiles/project1.dir/src/main.cpp.i

CMakeFiles/project1.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1/src/main.cpp" -o CMakeFiles/project1.dir/src/main.cpp.s

CMakeFiles/project1.dir/src/add_sub_exercise.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/src/add_sub_exercise.cpp.o: ../src/add_sub_exercise.cpp
CMakeFiles/project1.dir/src/add_sub_exercise.cpp.o: CMakeFiles/project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project1.dir/src/add_sub_exercise.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project1.dir/src/add_sub_exercise.cpp.o -MF CMakeFiles/project1.dir/src/add_sub_exercise.cpp.o.d -o CMakeFiles/project1.dir/src/add_sub_exercise.cpp.o -c "/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1/src/add_sub_exercise.cpp"

CMakeFiles/project1.dir/src/add_sub_exercise.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/src/add_sub_exercise.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1/src/add_sub_exercise.cpp" > CMakeFiles/project1.dir/src/add_sub_exercise.cpp.i

CMakeFiles/project1.dir/src/add_sub_exercise.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/src/add_sub_exercise.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1/src/add_sub_exercise.cpp" -o CMakeFiles/project1.dir/src/add_sub_exercise.cpp.s

# Object files for target project1
project1_OBJECTS = \
"CMakeFiles/project1.dir/src/main.cpp.o" \
"CMakeFiles/project1.dir/src/add_sub_exercise.cpp.o"

# External object files for target project1
project1_EXTERNAL_OBJECTS =

project1: CMakeFiles/project1.dir/src/main.cpp.o
project1: CMakeFiles/project1.dir/src/add_sub_exercise.cpp.o
project1: CMakeFiles/project1.dir/build.make
project1: CMakeFiles/project1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable project1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project1.dir/build: project1
.PHONY : CMakeFiles/project1.dir/build

CMakeFiles/project1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project1.dir/clean

CMakeFiles/project1.dir/depend:
	cd "/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1" "/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1" "/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1/build" "/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1/build" "/Users/zhiweichen/OneDrive/Code/C++ Project/Project_1/build/CMakeFiles/project1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/project1.dir/depend

