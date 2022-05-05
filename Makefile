# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/home/kai/.local/lib/python2.7/site-packages/cmake/data/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/home/kai/.local/lib/python2.7/site-packages/cmake/data/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kai/shell/CMakeFiles /home/kai/shell//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kai/shell/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

#=============================================================================
# Target rules for targets named ls

# Build rule for target.
ls: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 ls
.PHONY : ls

# fast build rule for target.
ls/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ls.dir/build.make CMakeFiles/ls.dir/build
.PHONY : ls/fast

#=============================================================================
# Target rules for targets named cat

# Build rule for target.
cat: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 cat
.PHONY : cat

# fast build rule for target.
cat/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cat.dir/build.make CMakeFiles/cat.dir/build
.PHONY : cat/fast

#=============================================================================
# Target rules for targets named rm

# Build rule for target.
rm: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 rm
.PHONY : rm

# fast build rule for target.
rm/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rm.dir/build.make CMakeFiles/rm.dir/build
.PHONY : rm/fast

#=============================================================================
# Target rules for targets named touch

# Build rule for target.
touch: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 touch
.PHONY : touch

# fast build rule for target.
touch/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/touch.dir/build.make CMakeFiles/touch.dir/build
.PHONY : touch/fast

#=============================================================================
# Target rules for targets named mkdir

# Build rule for target.
mkdir: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mkdir
.PHONY : mkdir

# fast build rule for target.
mkdir/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mkdir.dir/build.make CMakeFiles/mkdir.dir/build
.PHONY : mkdir/fast

#=============================================================================
# Target rules for targets named xargs

# Build rule for target.
xargs: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 xargs
.PHONY : xargs

# fast build rule for target.
xargs/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/xargs.dir/build.make CMakeFiles/xargs.dir/build
.PHONY : xargs/fast

cat.o: cat.cpp.o
.PHONY : cat.o

# target to build an object file
cat.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cat.dir/build.make CMakeFiles/cat.dir/cat.cpp.o
.PHONY : cat.cpp.o

cat.i: cat.cpp.i
.PHONY : cat.i

# target to preprocess a source file
cat.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cat.dir/build.make CMakeFiles/cat.dir/cat.cpp.i
.PHONY : cat.cpp.i

cat.s: cat.cpp.s
.PHONY : cat.s

# target to generate assembly for a file
cat.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/cat.dir/build.make CMakeFiles/cat.dir/cat.cpp.s
.PHONY : cat.cpp.s

ls.o: ls.cpp.o
.PHONY : ls.o

# target to build an object file
ls.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ls.dir/build.make CMakeFiles/ls.dir/ls.cpp.o
.PHONY : ls.cpp.o

ls.i: ls.cpp.i
.PHONY : ls.i

# target to preprocess a source file
ls.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ls.dir/build.make CMakeFiles/ls.dir/ls.cpp.i
.PHONY : ls.cpp.i

ls.s: ls.cpp.s
.PHONY : ls.s

# target to generate assembly for a file
ls.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ls.dir/build.make CMakeFiles/ls.dir/ls.cpp.s
.PHONY : ls.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.s
.PHONY : main.cpp.s

mkdir.o: mkdir.cpp.o
.PHONY : mkdir.o

# target to build an object file
mkdir.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mkdir.dir/build.make CMakeFiles/mkdir.dir/mkdir.cpp.o
.PHONY : mkdir.cpp.o

mkdir.i: mkdir.cpp.i
.PHONY : mkdir.i

# target to preprocess a source file
mkdir.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mkdir.dir/build.make CMakeFiles/mkdir.dir/mkdir.cpp.i
.PHONY : mkdir.cpp.i

mkdir.s: mkdir.cpp.s
.PHONY : mkdir.s

# target to generate assembly for a file
mkdir.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mkdir.dir/build.make CMakeFiles/mkdir.dir/mkdir.cpp.s
.PHONY : mkdir.cpp.s

rm.o: rm.cpp.o
.PHONY : rm.o

# target to build an object file
rm.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rm.dir/build.make CMakeFiles/rm.dir/rm.cpp.o
.PHONY : rm.cpp.o

rm.i: rm.cpp.i
.PHONY : rm.i

# target to preprocess a source file
rm.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rm.dir/build.make CMakeFiles/rm.dir/rm.cpp.i
.PHONY : rm.cpp.i

rm.s: rm.cpp.s
.PHONY : rm.s

# target to generate assembly for a file
rm.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rm.dir/build.make CMakeFiles/rm.dir/rm.cpp.s
.PHONY : rm.cpp.s

shell.o: shell.cpp.o
.PHONY : shell.o

# target to build an object file
shell.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/shell.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/xargs.dir/build.make CMakeFiles/xargs.dir/shell.cpp.o
.PHONY : shell.cpp.o

shell.i: shell.cpp.i
.PHONY : shell.i

# target to preprocess a source file
shell.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/shell.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/xargs.dir/build.make CMakeFiles/xargs.dir/shell.cpp.i
.PHONY : shell.cpp.i

shell.s: shell.cpp.s
.PHONY : shell.s

# target to generate assembly for a file
shell.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/shell.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/xargs.dir/build.make CMakeFiles/xargs.dir/shell.cpp.s
.PHONY : shell.cpp.s

tools.o: tools.cpp.o
.PHONY : tools.o

# target to build an object file
tools.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/tools.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ls.dir/build.make CMakeFiles/ls.dir/tools.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rm.dir/build.make CMakeFiles/rm.dir/tools.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/xargs.dir/build.make CMakeFiles/xargs.dir/tools.cpp.o
.PHONY : tools.cpp.o

tools.i: tools.cpp.i
.PHONY : tools.i

# target to preprocess a source file
tools.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/tools.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ls.dir/build.make CMakeFiles/ls.dir/tools.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rm.dir/build.make CMakeFiles/rm.dir/tools.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/xargs.dir/build.make CMakeFiles/xargs.dir/tools.cpp.i
.PHONY : tools.cpp.i

tools.s: tools.cpp.s
.PHONY : tools.s

# target to generate assembly for a file
tools.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/tools.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ls.dir/build.make CMakeFiles/ls.dir/tools.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rm.dir/build.make CMakeFiles/rm.dir/tools.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/xargs.dir/build.make CMakeFiles/xargs.dir/tools.cpp.s
.PHONY : tools.cpp.s

touch.o: touch.cpp.o
.PHONY : touch.o

# target to build an object file
touch.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/touch.dir/build.make CMakeFiles/touch.dir/touch.cpp.o
.PHONY : touch.cpp.o

touch.i: touch.cpp.i
.PHONY : touch.i

# target to preprocess a source file
touch.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/touch.dir/build.make CMakeFiles/touch.dir/touch.cpp.i
.PHONY : touch.cpp.i

touch.s: touch.cpp.s
.PHONY : touch.s

# target to generate assembly for a file
touch.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/touch.dir/build.make CMakeFiles/touch.dir/touch.cpp.s
.PHONY : touch.cpp.s

xargs.o: xargs.cpp.o
.PHONY : xargs.o

# target to build an object file
xargs.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/xargs.dir/build.make CMakeFiles/xargs.dir/xargs.cpp.o
.PHONY : xargs.cpp.o

xargs.i: xargs.cpp.i
.PHONY : xargs.i

# target to preprocess a source file
xargs.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/xargs.dir/build.make CMakeFiles/xargs.dir/xargs.cpp.i
.PHONY : xargs.cpp.i

xargs.s: xargs.cpp.s
.PHONY : xargs.s

# target to generate assembly for a file
xargs.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/xargs.dir/build.make CMakeFiles/xargs.dir/xargs.cpp.s
.PHONY : xargs.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... cat"
	@echo "... ls"
	@echo "... main"
	@echo "... mkdir"
	@echo "... rm"
	@echo "... touch"
	@echo "... xargs"
	@echo "... cat.o"
	@echo "... cat.i"
	@echo "... cat.s"
	@echo "... ls.o"
	@echo "... ls.i"
	@echo "... ls.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... mkdir.o"
	@echo "... mkdir.i"
	@echo "... mkdir.s"
	@echo "... rm.o"
	@echo "... rm.i"
	@echo "... rm.s"
	@echo "... shell.o"
	@echo "... shell.i"
	@echo "... shell.s"
	@echo "... tools.o"
	@echo "... tools.i"
	@echo "... tools.s"
	@echo "... touch.o"
	@echo "... touch.i"
	@echo "... touch.s"
	@echo "... xargs.o"
	@echo "... xargs.i"
	@echo "... xargs.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

