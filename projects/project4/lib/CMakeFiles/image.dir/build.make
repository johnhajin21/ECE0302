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
include lib/CMakeFiles/image.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/image.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/image.dir/flags.make

lib/CMakeFiles/image.dir/image.cpp.o: lib/CMakeFiles/image.dir/flags.make
lib/CMakeFiles/image.dir/image.cpp.o: lib/image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnhajin21/ECE0302/assignments/projects/project4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/image.dir/image.cpp.o"
	cd /home/johnhajin21/ECE0302/assignments/projects/project4/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image.dir/image.cpp.o -c /home/johnhajin21/ECE0302/assignments/projects/project4/lib/image.cpp

lib/CMakeFiles/image.dir/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image.dir/image.cpp.i"
	cd /home/johnhajin21/ECE0302/assignments/projects/project4/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnhajin21/ECE0302/assignments/projects/project4/lib/image.cpp > CMakeFiles/image.dir/image.cpp.i

lib/CMakeFiles/image.dir/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image.dir/image.cpp.s"
	cd /home/johnhajin21/ECE0302/assignments/projects/project4/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnhajin21/ECE0302/assignments/projects/project4/lib/image.cpp -o CMakeFiles/image.dir/image.cpp.s

lib/CMakeFiles/image.dir/lodepng.cpp.o: lib/CMakeFiles/image.dir/flags.make
lib/CMakeFiles/image.dir/lodepng.cpp.o: lib/lodepng.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnhajin21/ECE0302/assignments/projects/project4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/CMakeFiles/image.dir/lodepng.cpp.o"
	cd /home/johnhajin21/ECE0302/assignments/projects/project4/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image.dir/lodepng.cpp.o -c /home/johnhajin21/ECE0302/assignments/projects/project4/lib/lodepng.cpp

lib/CMakeFiles/image.dir/lodepng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image.dir/lodepng.cpp.i"
	cd /home/johnhajin21/ECE0302/assignments/projects/project4/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnhajin21/ECE0302/assignments/projects/project4/lib/lodepng.cpp > CMakeFiles/image.dir/lodepng.cpp.i

lib/CMakeFiles/image.dir/lodepng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image.dir/lodepng.cpp.s"
	cd /home/johnhajin21/ECE0302/assignments/projects/project4/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnhajin21/ECE0302/assignments/projects/project4/lib/lodepng.cpp -o CMakeFiles/image.dir/lodepng.cpp.s

# Object files for target image
image_OBJECTS = \
"CMakeFiles/image.dir/image.cpp.o" \
"CMakeFiles/image.dir/lodepng.cpp.o"

# External object files for target image
image_EXTERNAL_OBJECTS =

lib/libimage.a: lib/CMakeFiles/image.dir/image.cpp.o
lib/libimage.a: lib/CMakeFiles/image.dir/lodepng.cpp.o
lib/libimage.a: lib/CMakeFiles/image.dir/build.make
lib/libimage.a: lib/CMakeFiles/image.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/johnhajin21/ECE0302/assignments/projects/project4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libimage.a"
	cd /home/johnhajin21/ECE0302/assignments/projects/project4/lib && $(CMAKE_COMMAND) -P CMakeFiles/image.dir/cmake_clean_target.cmake
	cd /home/johnhajin21/ECE0302/assignments/projects/project4/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/image.dir/build: lib/libimage.a

.PHONY : lib/CMakeFiles/image.dir/build

lib/CMakeFiles/image.dir/clean:
	cd /home/johnhajin21/ECE0302/assignments/projects/project4/lib && $(CMAKE_COMMAND) -P CMakeFiles/image.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/image.dir/clean

lib/CMakeFiles/image.dir/depend:
	cd /home/johnhajin21/ECE0302/assignments/projects/project4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/johnhajin21/ECE0302/assignments/projects/project4 /home/johnhajin21/ECE0302/assignments/projects/project4/lib /home/johnhajin21/ECE0302/assignments/projects/project4 /home/johnhajin21/ECE0302/assignments/projects/project4/lib /home/johnhajin21/ECE0302/assignments/projects/project4/lib/CMakeFiles/image.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/image.dir/depend

