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
CMAKE_COMMAND = /cygdrive/c/Users/Kristin/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Kristin/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Main.dir/flags.make

CMakeFiles/Main.dir/Main.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/Main.cpp.o: ../Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Main.dir/Main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/Main.cpp.o -c "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/Main.cpp"

CMakeFiles/Main.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/Main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/Main.cpp" > CMakeFiles/Main.dir/Main.cpp.i

CMakeFiles/Main.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/Main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/Main.cpp" -o CMakeFiles/Main.dir/Main.cpp.s

CMakeFiles/Main.dir/Main.cpp.o.requires:

.PHONY : CMakeFiles/Main.dir/Main.cpp.o.requires

CMakeFiles/Main.dir/Main.cpp.o.provides: CMakeFiles/Main.dir/Main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/Main.cpp.o.provides.build
.PHONY : CMakeFiles/Main.dir/Main.cpp.o.provides

CMakeFiles/Main.dir/Main.cpp.o.provides.build: CMakeFiles/Main.dir/Main.cpp.o


# Object files for target Main
Main_OBJECTS = \
"CMakeFiles/Main.dir/Main.cpp.o"

# External object files for target Main
Main_EXTERNAL_OBJECTS =

Main.exe: CMakeFiles/Main.dir/Main.cpp.o
Main.exe: CMakeFiles/Main.dir/build.make
Main.exe: avltree/libavltreed.a
Main.exe: CMakeFiles/Main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Main.dir/build: Main.exe

.PHONY : CMakeFiles/Main.dir/build

CMakeFiles/Main.dir/requires: CMakeFiles/Main.dir/Main.cpp.o.requires

.PHONY : CMakeFiles/Main.dir/requires

CMakeFiles/Main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Main.dir/clean

CMakeFiles/Main.dir/depend:
	cd "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final" "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final" "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug" "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug" "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/CMakeFiles/Main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Main.dir/depend

