# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/ader/Pulpit/Zad 5.2 GIT/zad5_2-Szymon-Sobczak"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ader/Pulpit/Zad 5.2 GIT/zad5_2-Szymon-Sobczak/build"

# Utility rule file for coverage.

# Include the progress variables for this target.
include tests/CMakeFiles/coverage.dir/progress.make

tests/CMakeFiles/coverage:
	cd "/home/ader/Pulpit/Zad 5.2 GIT/zad5_2-Szymon-Sobczak/build/tests" && echo [31mCode\ coverage\ only\ available\ in\ coverage\ builds.
	cd "/home/ader/Pulpit/Zad 5.2 GIT/zad5_2-Szymon-Sobczak/build/tests" && echo [32mMake\ a\ new\ build\ directory\ and\ rerun\ cmake\ with\ -DCMAKE_BUILD_TYPE=Coverage\ to\ enable\ this\ target.[m

coverage: tests/CMakeFiles/coverage
coverage: tests/CMakeFiles/coverage.dir/build.make

.PHONY : coverage

# Rule to build all files generated by this target.
tests/CMakeFiles/coverage.dir/build: coverage

.PHONY : tests/CMakeFiles/coverage.dir/build

tests/CMakeFiles/coverage.dir/clean:
	cd "/home/ader/Pulpit/Zad 5.2 GIT/zad5_2-Szymon-Sobczak/build/tests" && $(CMAKE_COMMAND) -P CMakeFiles/coverage.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/coverage.dir/clean

tests/CMakeFiles/coverage.dir/depend:
	cd "/home/ader/Pulpit/Zad 5.2 GIT/zad5_2-Szymon-Sobczak/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ader/Pulpit/Zad 5.2 GIT/zad5_2-Szymon-Sobczak" "/home/ader/Pulpit/Zad 5.2 GIT/zad5_2-Szymon-Sobczak/tests" "/home/ader/Pulpit/Zad 5.2 GIT/zad5_2-Szymon-Sobczak/build" "/home/ader/Pulpit/Zad 5.2 GIT/zad5_2-Szymon-Sobczak/build/tests" "/home/ader/Pulpit/Zad 5.2 GIT/zad5_2-Szymon-Sobczak/build/tests/CMakeFiles/coverage.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/coverage.dir/depend

