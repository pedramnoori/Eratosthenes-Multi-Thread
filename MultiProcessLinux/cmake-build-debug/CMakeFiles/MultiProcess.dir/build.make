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
CMAKE_SOURCE_DIR = /home/pedram/CLionProjects/MultiProcess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pedram/CLionProjects/MultiProcess/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MultiProcess.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MultiProcess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MultiProcess.dir/flags.make

CMakeFiles/MultiProcess.dir/main.cpp.o: CMakeFiles/MultiProcess.dir/flags.make
CMakeFiles/MultiProcess.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedram/CLionProjects/MultiProcess/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MultiProcess.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MultiProcess.dir/main.cpp.o -c /home/pedram/CLionProjects/MultiProcess/main.cpp

CMakeFiles/MultiProcess.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MultiProcess.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedram/CLionProjects/MultiProcess/main.cpp > CMakeFiles/MultiProcess.dir/main.cpp.i

CMakeFiles/MultiProcess.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MultiProcess.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedram/CLionProjects/MultiProcess/main.cpp -o CMakeFiles/MultiProcess.dir/main.cpp.s

CMakeFiles/MultiProcess.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/MultiProcess.dir/main.cpp.o.requires

CMakeFiles/MultiProcess.dir/main.cpp.o.provides: CMakeFiles/MultiProcess.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MultiProcess.dir/build.make CMakeFiles/MultiProcess.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/MultiProcess.dir/main.cpp.o.provides

CMakeFiles/MultiProcess.dir/main.cpp.o.provides.build: CMakeFiles/MultiProcess.dir/main.cpp.o


# Object files for target MultiProcess
MultiProcess_OBJECTS = \
"CMakeFiles/MultiProcess.dir/main.cpp.o"

# External object files for target MultiProcess
MultiProcess_EXTERNAL_OBJECTS =

MultiProcess: CMakeFiles/MultiProcess.dir/main.cpp.o
MultiProcess: CMakeFiles/MultiProcess.dir/build.make
MultiProcess: CMakeFiles/MultiProcess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pedram/CLionProjects/MultiProcess/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MultiProcess"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MultiProcess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MultiProcess.dir/build: MultiProcess

.PHONY : CMakeFiles/MultiProcess.dir/build

CMakeFiles/MultiProcess.dir/requires: CMakeFiles/MultiProcess.dir/main.cpp.o.requires

.PHONY : CMakeFiles/MultiProcess.dir/requires

CMakeFiles/MultiProcess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MultiProcess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MultiProcess.dir/clean

CMakeFiles/MultiProcess.dir/depend:
	cd /home/pedram/CLionProjects/MultiProcess/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pedram/CLionProjects/MultiProcess /home/pedram/CLionProjects/MultiProcess /home/pedram/CLionProjects/MultiProcess/cmake-build-debug /home/pedram/CLionProjects/MultiProcess/cmake-build-debug /home/pedram/CLionProjects/MultiProcess/cmake-build-debug/CMakeFiles/MultiProcess.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MultiProcess.dir/depend
