# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /home/kai/.local/lib/python2.7/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/kai/.local/lib/python2.7/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kai/shell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kai/shell

# Include any dependencies generated for this target.
include CMakeFiles/rm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rm.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rm.dir/flags.make

CMakeFiles/rm.dir/rm.cpp.o: CMakeFiles/rm.dir/flags.make
CMakeFiles/rm.dir/rm.cpp.o: rm.cpp
CMakeFiles/rm.dir/rm.cpp.o: CMakeFiles/rm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kai/shell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rm.dir/rm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rm.dir/rm.cpp.o -MF CMakeFiles/rm.dir/rm.cpp.o.d -o CMakeFiles/rm.dir/rm.cpp.o -c /home/kai/shell/rm.cpp

CMakeFiles/rm.dir/rm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rm.dir/rm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kai/shell/rm.cpp > CMakeFiles/rm.dir/rm.cpp.i

CMakeFiles/rm.dir/rm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rm.dir/rm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kai/shell/rm.cpp -o CMakeFiles/rm.dir/rm.cpp.s

CMakeFiles/rm.dir/tools.cpp.o: CMakeFiles/rm.dir/flags.make
CMakeFiles/rm.dir/tools.cpp.o: tools.cpp
CMakeFiles/rm.dir/tools.cpp.o: CMakeFiles/rm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kai/shell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rm.dir/tools.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rm.dir/tools.cpp.o -MF CMakeFiles/rm.dir/tools.cpp.o.d -o CMakeFiles/rm.dir/tools.cpp.o -c /home/kai/shell/tools.cpp

CMakeFiles/rm.dir/tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rm.dir/tools.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kai/shell/tools.cpp > CMakeFiles/rm.dir/tools.cpp.i

CMakeFiles/rm.dir/tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rm.dir/tools.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kai/shell/tools.cpp -o CMakeFiles/rm.dir/tools.cpp.s

# Object files for target rm
rm_OBJECTS = \
"CMakeFiles/rm.dir/rm.cpp.o" \
"CMakeFiles/rm.dir/tools.cpp.o"

# External object files for target rm
rm_EXTERNAL_OBJECTS =

build/rm: CMakeFiles/rm.dir/rm.cpp.o
build/rm: CMakeFiles/rm.dir/tools.cpp.o
build/rm: CMakeFiles/rm.dir/build.make
build/rm: CMakeFiles/rm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kai/shell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable build/rm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rm.dir/build: build/rm
.PHONY : CMakeFiles/rm.dir/build

CMakeFiles/rm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rm.dir/clean

CMakeFiles/rm.dir/depend:
	cd /home/kai/shell && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kai/shell /home/kai/shell /home/kai/shell /home/kai/shell /home/kai/shell/CMakeFiles/rm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rm.dir/depend

