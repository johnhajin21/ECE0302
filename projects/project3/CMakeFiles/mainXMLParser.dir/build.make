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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/johnhajin21/ECE0302/assignments/projects/project3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/johnhajin21/ECE0302/assignments/projects/project3

# Include any dependencies generated for this target.
include CMakeFiles/mainXMLParser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mainXMLParser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mainXMLParser.dir/flags.make

CMakeFiles/mainXMLParser.dir/XMLParser.cpp.o: CMakeFiles/mainXMLParser.dir/flags.make
CMakeFiles/mainXMLParser.dir/XMLParser.cpp.o: XMLParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnhajin21/ECE0302/assignments/projects/project3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mainXMLParser.dir/XMLParser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mainXMLParser.dir/XMLParser.cpp.o -c /home/johnhajin21/ECE0302/assignments/projects/project3/XMLParser.cpp

CMakeFiles/mainXMLParser.dir/XMLParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainXMLParser.dir/XMLParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnhajin21/ECE0302/assignments/projects/project3/XMLParser.cpp > CMakeFiles/mainXMLParser.dir/XMLParser.cpp.i

CMakeFiles/mainXMLParser.dir/XMLParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainXMLParser.dir/XMLParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnhajin21/ECE0302/assignments/projects/project3/XMLParser.cpp -o CMakeFiles/mainXMLParser.dir/XMLParser.cpp.s

CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o: CMakeFiles/mainXMLParser.dir/flags.make
CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o: mainXMLParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johnhajin21/ECE0302/assignments/projects/project3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o -c /home/johnhajin21/ECE0302/assignments/projects/project3/mainXMLParser.cpp

CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johnhajin21/ECE0302/assignments/projects/project3/mainXMLParser.cpp > CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.i

CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johnhajin21/ECE0302/assignments/projects/project3/mainXMLParser.cpp -o CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.s

# Object files for target mainXMLParser
mainXMLParser_OBJECTS = \
"CMakeFiles/mainXMLParser.dir/XMLParser.cpp.o" \
"CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o"

# External object files for target mainXMLParser
mainXMLParser_EXTERNAL_OBJECTS =

mainXMLParser: CMakeFiles/mainXMLParser.dir/XMLParser.cpp.o
mainXMLParser: CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o
mainXMLParser: CMakeFiles/mainXMLParser.dir/build.make
mainXMLParser: CMakeFiles/mainXMLParser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/johnhajin21/ECE0302/assignments/projects/project3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable mainXMLParser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mainXMLParser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mainXMLParser.dir/build: mainXMLParser

.PHONY : CMakeFiles/mainXMLParser.dir/build

CMakeFiles/mainXMLParser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mainXMLParser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mainXMLParser.dir/clean

CMakeFiles/mainXMLParser.dir/depend:
	cd /home/johnhajin21/ECE0302/assignments/projects/project3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/johnhajin21/ECE0302/assignments/projects/project3 /home/johnhajin21/ECE0302/assignments/projects/project3 /home/johnhajin21/ECE0302/assignments/projects/project3 /home/johnhajin21/ECE0302/assignments/projects/project3 /home/johnhajin21/ECE0302/assignments/projects/project3/CMakeFiles/mainXMLParser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mainXMLParser.dir/depend

