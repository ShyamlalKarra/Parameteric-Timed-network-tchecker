# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build

# Include any dependencies generated for this target.
include test/testutils/CMakeFiles/testutils.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/testutils/CMakeFiles/testutils.dir/compiler_depend.make

# Include the progress variables for this target.
include test/testutils/CMakeFiles/testutils.dir/progress.make

# Include the compile flags for this target's objects.
include test/testutils/CMakeFiles/testutils.dir/flags.make

test/testutils/CMakeFiles/testutils.dir/utils.cc.o: test/testutils/CMakeFiles/testutils.dir/flags.make
test/testutils/CMakeFiles/testutils.dir/utils.cc.o: /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/test/testutils/utils.cc
test/testutils/CMakeFiles/testutils.dir/utils.cc.o: test/testutils/CMakeFiles/testutils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/testutils/CMakeFiles/testutils.dir/utils.cc.o"
	cd /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/test/testutils && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/testutils/CMakeFiles/testutils.dir/utils.cc.o -MF CMakeFiles/testutils.dir/utils.cc.o.d -o CMakeFiles/testutils.dir/utils.cc.o -c /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/test/testutils/utils.cc

test/testutils/CMakeFiles/testutils.dir/utils.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testutils.dir/utils.cc.i"
	cd /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/test/testutils && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/test/testutils/utils.cc > CMakeFiles/testutils.dir/utils.cc.i

test/testutils/CMakeFiles/testutils.dir/utils.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testutils.dir/utils.cc.s"
	cd /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/test/testutils && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/test/testutils/utils.cc -o CMakeFiles/testutils.dir/utils.cc.s

# Object files for target testutils
testutils_OBJECTS = \
"CMakeFiles/testutils.dir/utils.cc.o"

# External object files for target testutils
testutils_EXTERNAL_OBJECTS =

test/testutils/libtestutils.a: test/testutils/CMakeFiles/testutils.dir/utils.cc.o
test/testutils/libtestutils.a: test/testutils/CMakeFiles/testutils.dir/build.make
test/testutils/libtestutils.a: test/testutils/CMakeFiles/testutils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libtestutils.a"
	cd /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/test/testutils && $(CMAKE_COMMAND) -P CMakeFiles/testutils.dir/cmake_clean_target.cmake
	cd /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/test/testutils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testutils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/testutils/CMakeFiles/testutils.dir/build: test/testutils/libtestutils.a
.PHONY : test/testutils/CMakeFiles/testutils.dir/build

test/testutils/CMakeFiles/testutils.dir/clean:
	cd /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/test/testutils && $(CMAKE_COMMAND) -P CMakeFiles/testutils.dir/cmake_clean.cmake
.PHONY : test/testutils/CMakeFiles/testutils.dir/clean

test/testutils/CMakeFiles/testutils.dir/depend:
	cd /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/test/testutils /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/test/testutils /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/test/testutils/CMakeFiles/testutils.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/testutils/CMakeFiles/testutils.dir/depend

