# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/johnhajin21/ECE0302/assignments/projects/project4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/johnhajin21/ECE0302/assignments/projects/project4

# Include any dependencies generated for this target.
include CMakeFiles/pathfinder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pathfinder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pathfinder.dir/flags.make

CMakeFiles/pathfinder.dir/pathfinder.cpp.o: CMakeFiles/pathfinder.dir/flags.make
CMakeFiles/pathfinder.dir/pathfinder.cpp.o: pathfinder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnhajin21/ECE0302/assignments/projects/project4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pathfinder.dir/pathfinder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pathfinder.dir/pathfinder.cpp.o -c /home/johnhajin21/ECE0302/assignments/projects/project4/pathfinder.cpp

CMakeFiles/pathfinder.dir/pathfinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pathfinder.dir/pathfinder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnhajin21/ECE0302/assignments/projects/project4/pathfinder.cpp > CMakeFiles/pathfinder.dir/pathfinder.cpp.i

CMakeFiles/pathfinder.dir/pathfinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pathfinder.dir/pathfinder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnhajin21/ECE0302/assignments/projects/project4/pathfinder.cpp -o CMakeFiles/pathfinder.dir/pathfinder.cpp.s

# Object files for target pathfinder
pathfinder_OBJECTS = \
"CMakeFiles/pathfinder.dir/pathfinder.cpp.o"

# External object files for target pathfinder
pathfinder_EXTERNAL_OBJECTS =

pathfinder: CMakeFiles/pathfinder.dir/pathfinder.cpp.o
pathfinder: CMakeFiles/pathfinder.dir/build.make
pathfinder: lib/libimage.a
pathfinder: CMakeFiles/pathfinder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/johnhajin21/ECE0302/assignments/projects/project4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pathfinder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pathfinder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pathfinder.dir/build: pathfinder

.PHONY : CMakeFiles/pathfinder.dir/build

CMakeFiles/pathfinder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pathfinder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pathfinder.dir/clean

CMakeFiles/pathfinder.dir/depend:
	cd /home/johnhajin21/ECE0302/assignments/projects/project4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/johnhajin21/ECE0302/assignments/projects/project4 /home/johnhajin21/ECE0302/assignments/projects/project4 /home/johnhajin21/ECE0302/assignments/projects/project4 /home/johnhajin21/ECE0302/assignments/projects/project4 /home/johnhajin21/ECE0302/assignments/projects/project4/CMakeFiles/pathfinder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pathfinder.dir/depend

