# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/pedram/Downloads/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/pedram/Downloads/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pedram/CLionProjects/MultiThread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pedram/CLionProjects/MultiThread/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MultiThread.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MultiThread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MultiThread.dir/flags.make

CMakeFiles/MultiThread.dir/main.cpp.o: CMakeFiles/MultiThread.dir/flags.make
CMakeFiles/MultiThread.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedram/CLionProjects/MultiThread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MultiThread.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MultiThread.dir/main.cpp.o -c /home/pedram/CLionProjects/MultiThread/main.cpp

CMakeFiles/MultiThread.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MultiThread.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedram/CLionProjects/MultiThread/main.cpp > CMakeFiles/MultiThread.dir/main.cpp.i

CMakeFiles/MultiThread.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MultiThread.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedram/CLionProjects/MultiThread/main.cpp -o CMakeFiles/MultiThread.dir/main.cpp.s

CMakeFiles/MultiThread.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/MultiThread.dir/main.cpp.o.requires

CMakeFiles/MultiThread.dir/main.cpp.o.provides: CMakeFiles/MultiThread.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MultiThread.dir/build.make CMakeFiles/MultiThread.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/MultiThread.dir/main.cpp.o.provides

CMakeFiles/MultiThread.dir/main.cpp.o.provides.build: CMakeFiles/MultiThread.dir/main.cpp.o


# Object files for target MultiThread
MultiThread_OBJECTS = \
"CMakeFiles/MultiThread.dir/main.cpp.o"

# External object files for target MultiThread
MultiThread_EXTERNAL_OBJECTS =

MultiThread: CMakeFiles/MultiThread.dir/main.cpp.o
MultiThread: CMakeFiles/MultiThread.dir/build.make
MultiThread: CMakeFiles/MultiThread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pedram/CLionProjects/MultiThread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MultiThread"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MultiThread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MultiThread.dir/build: MultiThread

.PHONY : CMakeFiles/MultiThread.dir/build

CMakeFiles/MultiThread.dir/requires: CMakeFiles/MultiThread.dir/main.cpp.o.requires

.PHONY : CMakeFiles/MultiThread.dir/requires

CMakeFiles/MultiThread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MultiThread.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MultiThread.dir/clean

CMakeFiles/MultiThread.dir/depend:
	cd /home/pedram/CLionProjects/MultiThread/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pedram/CLionProjects/MultiThread /home/pedram/CLionProjects/MultiThread /home/pedram/CLionProjects/MultiThread/cmake-build-debug /home/pedram/CLionProjects/MultiThread/cmake-build-debug /home/pedram/CLionProjects/MultiThread/cmake-build-debug/CMakeFiles/MultiThread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MultiThread.dir/depend

