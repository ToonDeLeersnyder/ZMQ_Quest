# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Administrator\Documents\Gitkraken\ZMQ_Quest\ZMQ_opdracht

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Administrator\Documents\Gitkraken\ZMQ_Quest\build-ZMQ_opdracht-Imported_Kit-Debug

# Include any dependencies generated for this target.
include CMakeFiles/ZMQ_opdracht.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ZMQ_opdracht.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ZMQ_opdracht.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ZMQ_opdracht.dir/flags.make

CMakeFiles/ZMQ_opdracht.dir/main.cpp.obj: CMakeFiles/ZMQ_opdracht.dir/flags.make
CMakeFiles/ZMQ_opdracht.dir/main.cpp.obj: CMakeFiles/ZMQ_opdracht.dir/includes_CXX.rsp
CMakeFiles/ZMQ_opdracht.dir/main.cpp.obj: C:/Users/Administrator/Documents/Gitkraken/ZMQ_Quest/ZMQ_opdracht/main.cpp
CMakeFiles/ZMQ_opdracht.dir/main.cpp.obj: CMakeFiles/ZMQ_opdracht.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\Documents\Gitkraken\ZMQ_Quest\build-ZMQ_opdracht-Imported_Kit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ZMQ_opdracht.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ZMQ_opdracht.dir/main.cpp.obj -MF CMakeFiles\ZMQ_opdracht.dir\main.cpp.obj.d -o CMakeFiles\ZMQ_opdracht.dir\main.cpp.obj -c C:\Users\Administrator\Documents\Gitkraken\ZMQ_Quest\ZMQ_opdracht\main.cpp

CMakeFiles/ZMQ_opdracht.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZMQ_opdracht.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\Documents\Gitkraken\ZMQ_Quest\ZMQ_opdracht\main.cpp > CMakeFiles\ZMQ_opdracht.dir\main.cpp.i

CMakeFiles/ZMQ_opdracht.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZMQ_opdracht.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\Documents\Gitkraken\ZMQ_Quest\ZMQ_opdracht\main.cpp -o CMakeFiles\ZMQ_opdracht.dir\main.cpp.s

# Object files for target ZMQ_opdracht
ZMQ_opdracht_OBJECTS = \
"CMakeFiles/ZMQ_opdracht.dir/main.cpp.obj"

# External object files for target ZMQ_opdracht
ZMQ_opdracht_EXTERNAL_OBJECTS =

ZMQ_opdracht.exe: CMakeFiles/ZMQ_opdracht.dir/main.cpp.obj
ZMQ_opdracht.exe: CMakeFiles/ZMQ_opdracht.dir/build.make
ZMQ_opdracht.exe: CMakeFiles/ZMQ_opdracht.dir/linklibs.rsp
ZMQ_opdracht.exe: CMakeFiles/ZMQ_opdracht.dir/objects1.rsp
ZMQ_opdracht.exe: CMakeFiles/ZMQ_opdracht.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Administrator\Documents\Gitkraken\ZMQ_Quest\build-ZMQ_opdracht-Imported_Kit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ZMQ_opdracht.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ZMQ_opdracht.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ZMQ_opdracht.dir/build: ZMQ_opdracht.exe
.PHONY : CMakeFiles/ZMQ_opdracht.dir/build

CMakeFiles/ZMQ_opdracht.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ZMQ_opdracht.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ZMQ_opdracht.dir/clean

CMakeFiles/ZMQ_opdracht.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Administrator\Documents\Gitkraken\ZMQ_Quest\ZMQ_opdracht C:\Users\Administrator\Documents\Gitkraken\ZMQ_Quest\ZMQ_opdracht C:\Users\Administrator\Documents\Gitkraken\ZMQ_Quest\build-ZMQ_opdracht-Imported_Kit-Debug C:\Users\Administrator\Documents\Gitkraken\ZMQ_Quest\build-ZMQ_opdracht-Imported_Kit-Debug C:\Users\Administrator\Documents\Gitkraken\ZMQ_Quest\build-ZMQ_opdracht-Imported_Kit-Debug\CMakeFiles\ZMQ_opdracht.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ZMQ_opdracht.dir/depend

