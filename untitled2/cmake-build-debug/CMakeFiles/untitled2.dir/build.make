# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/aidan/Desktop/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/aidan/Desktop/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aidan/CLionProjects/untitled2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aidan/CLionProjects/untitled2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled2.dir/flags.make

CMakeFiles/untitled2.dir/stack.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/stack.cpp.o: ../stack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aidan/CLionProjects/untitled2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled2.dir/stack.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/stack.cpp.o -c /home/aidan/CLionProjects/untitled2/stack.cpp

CMakeFiles/untitled2.dir/stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/stack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aidan/CLionProjects/untitled2/stack.cpp > CMakeFiles/untitled2.dir/stack.cpp.i

CMakeFiles/untitled2.dir/stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/stack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aidan/CLionProjects/untitled2/stack.cpp -o CMakeFiles/untitled2.dir/stack.cpp.s

CMakeFiles/untitled2.dir/undoRedo.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/undoRedo.cpp.o: ../undoRedo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aidan/CLionProjects/untitled2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/untitled2.dir/undoRedo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/undoRedo.cpp.o -c /home/aidan/CLionProjects/untitled2/undoRedo.cpp

CMakeFiles/untitled2.dir/undoRedo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/undoRedo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aidan/CLionProjects/untitled2/undoRedo.cpp > CMakeFiles/untitled2.dir/undoRedo.cpp.i

CMakeFiles/untitled2.dir/undoRedo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/undoRedo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aidan/CLionProjects/untitled2/undoRedo.cpp -o CMakeFiles/untitled2.dir/undoRedo.cpp.s

CMakeFiles/untitled2.dir/insertUndoRedoCommand.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/insertUndoRedoCommand.cpp.o: ../insertUndoRedoCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aidan/CLionProjects/untitled2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/untitled2.dir/insertUndoRedoCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/insertUndoRedoCommand.cpp.o -c /home/aidan/CLionProjects/untitled2/insertUndoRedoCommand.cpp

CMakeFiles/untitled2.dir/insertUndoRedoCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/insertUndoRedoCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aidan/CLionProjects/untitled2/insertUndoRedoCommand.cpp > CMakeFiles/untitled2.dir/insertUndoRedoCommand.cpp.i

CMakeFiles/untitled2.dir/insertUndoRedoCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/insertUndoRedoCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aidan/CLionProjects/untitled2/insertUndoRedoCommand.cpp -o CMakeFiles/untitled2.dir/insertUndoRedoCommand.cpp.s

CMakeFiles/untitled2.dir/eraseUndoRedoCommand.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/eraseUndoRedoCommand.cpp.o: ../eraseUndoRedoCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aidan/CLionProjects/untitled2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/untitled2.dir/eraseUndoRedoCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/eraseUndoRedoCommand.cpp.o -c /home/aidan/CLionProjects/untitled2/eraseUndoRedoCommand.cpp

CMakeFiles/untitled2.dir/eraseUndoRedoCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/eraseUndoRedoCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aidan/CLionProjects/untitled2/eraseUndoRedoCommand.cpp > CMakeFiles/untitled2.dir/eraseUndoRedoCommand.cpp.i

CMakeFiles/untitled2.dir/eraseUndoRedoCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/eraseUndoRedoCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aidan/CLionProjects/untitled2/eraseUndoRedoCommand.cpp -o CMakeFiles/untitled2.dir/eraseUndoRedoCommand.cpp.s

CMakeFiles/untitled2.dir/undoCommand.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/undoCommand.cpp.o: ../undoCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aidan/CLionProjects/untitled2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/untitled2.dir/undoCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/undoCommand.cpp.o -c /home/aidan/CLionProjects/untitled2/undoCommand.cpp

CMakeFiles/untitled2.dir/undoCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/undoCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aidan/CLionProjects/untitled2/undoCommand.cpp > CMakeFiles/untitled2.dir/undoCommand.cpp.i

CMakeFiles/untitled2.dir/undoCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/undoCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aidan/CLionProjects/untitled2/undoCommand.cpp -o CMakeFiles/untitled2.dir/undoCommand.cpp.s

CMakeFiles/untitled2.dir/redoCommand.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/redoCommand.cpp.o: ../redoCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aidan/CLionProjects/untitled2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/untitled2.dir/redoCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/redoCommand.cpp.o -c /home/aidan/CLionProjects/untitled2/redoCommand.cpp

CMakeFiles/untitled2.dir/redoCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/redoCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aidan/CLionProjects/untitled2/redoCommand.cpp > CMakeFiles/untitled2.dir/redoCommand.cpp.i

CMakeFiles/untitled2.dir/redoCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/redoCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aidan/CLionProjects/untitled2/redoCommand.cpp -o CMakeFiles/untitled2.dir/redoCommand.cpp.s

CMakeFiles/untitled2.dir/addUpdateCommand.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/addUpdateCommand.cpp.o: ../addUpdateCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aidan/CLionProjects/untitled2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/untitled2.dir/addUpdateCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/addUpdateCommand.cpp.o -c /home/aidan/CLionProjects/untitled2/addUpdateCommand.cpp

CMakeFiles/untitled2.dir/addUpdateCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/addUpdateCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aidan/CLionProjects/untitled2/addUpdateCommand.cpp > CMakeFiles/untitled2.dir/addUpdateCommand.cpp.i

CMakeFiles/untitled2.dir/addUpdateCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/addUpdateCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aidan/CLionProjects/untitled2/addUpdateCommand.cpp -o CMakeFiles/untitled2.dir/addUpdateCommand.cpp.s

CMakeFiles/untitled2.dir/eraseCommand.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/eraseCommand.cpp.o: ../eraseCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aidan/CLionProjects/untitled2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/untitled2.dir/eraseCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/eraseCommand.cpp.o -c /home/aidan/CLionProjects/untitled2/eraseCommand.cpp

CMakeFiles/untitled2.dir/eraseCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/eraseCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aidan/CLionProjects/untitled2/eraseCommand.cpp > CMakeFiles/untitled2.dir/eraseCommand.cpp.i

CMakeFiles/untitled2.dir/eraseCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/eraseCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aidan/CLionProjects/untitled2/eraseCommand.cpp -o CMakeFiles/untitled2.dir/eraseCommand.cpp.s

CMakeFiles/untitled2.dir/assignment3.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/assignment3.cpp.o: ../assignment3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aidan/CLionProjects/untitled2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/untitled2.dir/assignment3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/assignment3.cpp.o -c /home/aidan/CLionProjects/untitled2/assignment3.cpp

CMakeFiles/untitled2.dir/assignment3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/assignment3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aidan/CLionProjects/untitled2/assignment3.cpp > CMakeFiles/untitled2.dir/assignment3.cpp.i

CMakeFiles/untitled2.dir/assignment3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/assignment3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aidan/CLionProjects/untitled2/assignment3.cpp -o CMakeFiles/untitled2.dir/assignment3.cpp.s

CMakeFiles/untitled2.dir/updateUndoRedoCommand.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/updateUndoRedoCommand.cpp.o: ../updateUndoRedoCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aidan/CLionProjects/untitled2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/untitled2.dir/updateUndoRedoCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/updateUndoRedoCommand.cpp.o -c /home/aidan/CLionProjects/untitled2/updateUndoRedoCommand.cpp

CMakeFiles/untitled2.dir/updateUndoRedoCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/updateUndoRedoCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aidan/CLionProjects/untitled2/updateUndoRedoCommand.cpp > CMakeFiles/untitled2.dir/updateUndoRedoCommand.cpp.i

CMakeFiles/untitled2.dir/updateUndoRedoCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/updateUndoRedoCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aidan/CLionProjects/untitled2/updateUndoRedoCommand.cpp -o CMakeFiles/untitled2.dir/updateUndoRedoCommand.cpp.s

# Object files for target untitled2
untitled2_OBJECTS = \
"CMakeFiles/untitled2.dir/stack.cpp.o" \
"CMakeFiles/untitled2.dir/undoRedo.cpp.o" \
"CMakeFiles/untitled2.dir/insertUndoRedoCommand.cpp.o" \
"CMakeFiles/untitled2.dir/eraseUndoRedoCommand.cpp.o" \
"CMakeFiles/untitled2.dir/undoCommand.cpp.o" \
"CMakeFiles/untitled2.dir/redoCommand.cpp.o" \
"CMakeFiles/untitled2.dir/addUpdateCommand.cpp.o" \
"CMakeFiles/untitled2.dir/eraseCommand.cpp.o" \
"CMakeFiles/untitled2.dir/assignment3.cpp.o" \
"CMakeFiles/untitled2.dir/updateUndoRedoCommand.cpp.o"

# External object files for target untitled2
untitled2_EXTERNAL_OBJECTS =

untitled2: CMakeFiles/untitled2.dir/stack.cpp.o
untitled2: CMakeFiles/untitled2.dir/undoRedo.cpp.o
untitled2: CMakeFiles/untitled2.dir/insertUndoRedoCommand.cpp.o
untitled2: CMakeFiles/untitled2.dir/eraseUndoRedoCommand.cpp.o
untitled2: CMakeFiles/untitled2.dir/undoCommand.cpp.o
untitled2: CMakeFiles/untitled2.dir/redoCommand.cpp.o
untitled2: CMakeFiles/untitled2.dir/addUpdateCommand.cpp.o
untitled2: CMakeFiles/untitled2.dir/eraseCommand.cpp.o
untitled2: CMakeFiles/untitled2.dir/assignment3.cpp.o
untitled2: CMakeFiles/untitled2.dir/updateUndoRedoCommand.cpp.o
untitled2: CMakeFiles/untitled2.dir/build.make
untitled2: CMakeFiles/untitled2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aidan/CLionProjects/untitled2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable untitled2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled2.dir/build: untitled2

.PHONY : CMakeFiles/untitled2.dir/build

CMakeFiles/untitled2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled2.dir/clean

CMakeFiles/untitled2.dir/depend:
	cd /home/aidan/CLionProjects/untitled2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aidan/CLionProjects/untitled2 /home/aidan/CLionProjects/untitled2 /home/aidan/CLionProjects/untitled2/cmake-build-debug /home/aidan/CLionProjects/untitled2/cmake-build-debug /home/aidan/CLionProjects/untitled2/cmake-build-debug/CMakeFiles/untitled2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled2.dir/depend

