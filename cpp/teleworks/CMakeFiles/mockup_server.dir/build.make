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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/work/zipsa_tst_func

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/work/zipsa_tst_func

# Include any dependencies generated for this target.
include cpp/teleworks/CMakeFiles/mockup_server.dir/depend.make

# Include the progress variables for this target.
include cpp/teleworks/CMakeFiles/mockup_server.dir/progress.make

# Include the compile flags for this target's objects.
include cpp/teleworks/CMakeFiles/mockup_server.dir/flags.make

cpp/teleworks/CMakeFiles/mockup_server.dir/ServerSocket.cpp.o: cpp/teleworks/CMakeFiles/mockup_server.dir/flags.make
cpp/teleworks/CMakeFiles/mockup_server.dir/ServerSocket.cpp.o: cpp/teleworks/ServerSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/zipsa_tst_func/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object cpp/teleworks/CMakeFiles/mockup_server.dir/ServerSocket.cpp.o"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mockup_server.dir/ServerSocket.cpp.o -c /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/ServerSocket.cpp

cpp/teleworks/CMakeFiles/mockup_server.dir/ServerSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mockup_server.dir/ServerSocket.cpp.i"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/ServerSocket.cpp > CMakeFiles/mockup_server.dir/ServerSocket.cpp.i

cpp/teleworks/CMakeFiles/mockup_server.dir/ServerSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mockup_server.dir/ServerSocket.cpp.s"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/ServerSocket.cpp -o CMakeFiles/mockup_server.dir/ServerSocket.cpp.s

cpp/teleworks/CMakeFiles/mockup_server.dir/ClientSocket.cpp.o: cpp/teleworks/CMakeFiles/mockup_server.dir/flags.make
cpp/teleworks/CMakeFiles/mockup_server.dir/ClientSocket.cpp.o: cpp/teleworks/ClientSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/zipsa_tst_func/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object cpp/teleworks/CMakeFiles/mockup_server.dir/ClientSocket.cpp.o"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mockup_server.dir/ClientSocket.cpp.o -c /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/ClientSocket.cpp

cpp/teleworks/CMakeFiles/mockup_server.dir/ClientSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mockup_server.dir/ClientSocket.cpp.i"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/ClientSocket.cpp > CMakeFiles/mockup_server.dir/ClientSocket.cpp.i

cpp/teleworks/CMakeFiles/mockup_server.dir/ClientSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mockup_server.dir/ClientSocket.cpp.s"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/ClientSocket.cpp -o CMakeFiles/mockup_server.dir/ClientSocket.cpp.s

cpp/teleworks/CMakeFiles/mockup_server.dir/Socket.cpp.o: cpp/teleworks/CMakeFiles/mockup_server.dir/flags.make
cpp/teleworks/CMakeFiles/mockup_server.dir/Socket.cpp.o: cpp/teleworks/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/zipsa_tst_func/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object cpp/teleworks/CMakeFiles/mockup_server.dir/Socket.cpp.o"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mockup_server.dir/Socket.cpp.o -c /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/Socket.cpp

cpp/teleworks/CMakeFiles/mockup_server.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mockup_server.dir/Socket.cpp.i"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/Socket.cpp > CMakeFiles/mockup_server.dir/Socket.cpp.i

cpp/teleworks/CMakeFiles/mockup_server.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mockup_server.dir/Socket.cpp.s"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/Socket.cpp -o CMakeFiles/mockup_server.dir/Socket.cpp.s

cpp/teleworks/CMakeFiles/mockup_server.dir/Node.cpp.o: cpp/teleworks/CMakeFiles/mockup_server.dir/flags.make
cpp/teleworks/CMakeFiles/mockup_server.dir/Node.cpp.o: cpp/teleworks/Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/zipsa_tst_func/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object cpp/teleworks/CMakeFiles/mockup_server.dir/Node.cpp.o"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mockup_server.dir/Node.cpp.o -c /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/Node.cpp

cpp/teleworks/CMakeFiles/mockup_server.dir/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mockup_server.dir/Node.cpp.i"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/Node.cpp > CMakeFiles/mockup_server.dir/Node.cpp.i

cpp/teleworks/CMakeFiles/mockup_server.dir/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mockup_server.dir/Node.cpp.s"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/Node.cpp -o CMakeFiles/mockup_server.dir/Node.cpp.s

cpp/teleworks/CMakeFiles/mockup_server.dir/Queue.cpp.o: cpp/teleworks/CMakeFiles/mockup_server.dir/flags.make
cpp/teleworks/CMakeFiles/mockup_server.dir/Queue.cpp.o: cpp/teleworks/Queue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/zipsa_tst_func/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object cpp/teleworks/CMakeFiles/mockup_server.dir/Queue.cpp.o"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mockup_server.dir/Queue.cpp.o -c /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/Queue.cpp

cpp/teleworks/CMakeFiles/mockup_server.dir/Queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mockup_server.dir/Queue.cpp.i"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/Queue.cpp > CMakeFiles/mockup_server.dir/Queue.cpp.i

cpp/teleworks/CMakeFiles/mockup_server.dir/Queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mockup_server.dir/Queue.cpp.s"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/Queue.cpp -o CMakeFiles/mockup_server.dir/Queue.cpp.s

cpp/teleworks/CMakeFiles/mockup_server.dir/utils.cpp.o: cpp/teleworks/CMakeFiles/mockup_server.dir/flags.make
cpp/teleworks/CMakeFiles/mockup_server.dir/utils.cpp.o: cpp/teleworks/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/zipsa_tst_func/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object cpp/teleworks/CMakeFiles/mockup_server.dir/utils.cpp.o"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mockup_server.dir/utils.cpp.o -c /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/utils.cpp

cpp/teleworks/CMakeFiles/mockup_server.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mockup_server.dir/utils.cpp.i"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/utils.cpp > CMakeFiles/mockup_server.dir/utils.cpp.i

cpp/teleworks/CMakeFiles/mockup_server.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mockup_server.dir/utils.cpp.s"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/utils.cpp -o CMakeFiles/mockup_server.dir/utils.cpp.s

cpp/teleworks/CMakeFiles/mockup_server.dir/CmdExecutor.cpp.o: cpp/teleworks/CMakeFiles/mockup_server.dir/flags.make
cpp/teleworks/CMakeFiles/mockup_server.dir/CmdExecutor.cpp.o: cpp/teleworks/CmdExecutor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/zipsa_tst_func/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object cpp/teleworks/CMakeFiles/mockup_server.dir/CmdExecutor.cpp.o"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mockup_server.dir/CmdExecutor.cpp.o -c /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/CmdExecutor.cpp

cpp/teleworks/CMakeFiles/mockup_server.dir/CmdExecutor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mockup_server.dir/CmdExecutor.cpp.i"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/CmdExecutor.cpp > CMakeFiles/mockup_server.dir/CmdExecutor.cpp.i

cpp/teleworks/CMakeFiles/mockup_server.dir/CmdExecutor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mockup_server.dir/CmdExecutor.cpp.s"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/CmdExecutor.cpp -o CMakeFiles/mockup_server.dir/CmdExecutor.cpp.s

cpp/teleworks/CMakeFiles/mockup_server.dir/mockup_server_main.cpp.o: cpp/teleworks/CMakeFiles/mockup_server.dir/flags.make
cpp/teleworks/CMakeFiles/mockup_server.dir/mockup_server_main.cpp.o: cpp/teleworks/mockup_server_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/zipsa_tst_func/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object cpp/teleworks/CMakeFiles/mockup_server.dir/mockup_server_main.cpp.o"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mockup_server.dir/mockup_server_main.cpp.o -c /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/mockup_server_main.cpp

cpp/teleworks/CMakeFiles/mockup_server.dir/mockup_server_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mockup_server.dir/mockup_server_main.cpp.i"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/mockup_server_main.cpp > CMakeFiles/mockup_server.dir/mockup_server_main.cpp.i

cpp/teleworks/CMakeFiles/mockup_server.dir/mockup_server_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mockup_server.dir/mockup_server_main.cpp.s"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/mockup_server_main.cpp -o CMakeFiles/mockup_server.dir/mockup_server_main.cpp.s

# Object files for target mockup_server
mockup_server_OBJECTS = \
"CMakeFiles/mockup_server.dir/ServerSocket.cpp.o" \
"CMakeFiles/mockup_server.dir/ClientSocket.cpp.o" \
"CMakeFiles/mockup_server.dir/Socket.cpp.o" \
"CMakeFiles/mockup_server.dir/Node.cpp.o" \
"CMakeFiles/mockup_server.dir/Queue.cpp.o" \
"CMakeFiles/mockup_server.dir/utils.cpp.o" \
"CMakeFiles/mockup_server.dir/CmdExecutor.cpp.o" \
"CMakeFiles/mockup_server.dir/mockup_server_main.cpp.o"

# External object files for target mockup_server
mockup_server_EXTERNAL_OBJECTS =

bin/mockup_server: cpp/teleworks/CMakeFiles/mockup_server.dir/ServerSocket.cpp.o
bin/mockup_server: cpp/teleworks/CMakeFiles/mockup_server.dir/ClientSocket.cpp.o
bin/mockup_server: cpp/teleworks/CMakeFiles/mockup_server.dir/Socket.cpp.o
bin/mockup_server: cpp/teleworks/CMakeFiles/mockup_server.dir/Node.cpp.o
bin/mockup_server: cpp/teleworks/CMakeFiles/mockup_server.dir/Queue.cpp.o
bin/mockup_server: cpp/teleworks/CMakeFiles/mockup_server.dir/utils.cpp.o
bin/mockup_server: cpp/teleworks/CMakeFiles/mockup_server.dir/CmdExecutor.cpp.o
bin/mockup_server: cpp/teleworks/CMakeFiles/mockup_server.dir/mockup_server_main.cpp.o
bin/mockup_server: cpp/teleworks/CMakeFiles/mockup_server.dir/build.make
bin/mockup_server: cpp/teleworks/CMakeFiles/mockup_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/work/zipsa_tst_func/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable ../../bin/mockup_server"
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mockup_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cpp/teleworks/CMakeFiles/mockup_server.dir/build: bin/mockup_server

.PHONY : cpp/teleworks/CMakeFiles/mockup_server.dir/build

cpp/teleworks/CMakeFiles/mockup_server.dir/clean:
	cd /home/ubuntu/work/zipsa_tst_func/cpp/teleworks && $(CMAKE_COMMAND) -P CMakeFiles/mockup_server.dir/cmake_clean.cmake
.PHONY : cpp/teleworks/CMakeFiles/mockup_server.dir/clean

cpp/teleworks/CMakeFiles/mockup_server.dir/depend:
	cd /home/ubuntu/work/zipsa_tst_func && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/work/zipsa_tst_func /home/ubuntu/work/zipsa_tst_func/cpp/teleworks /home/ubuntu/work/zipsa_tst_func /home/ubuntu/work/zipsa_tst_func/cpp/teleworks /home/ubuntu/work/zipsa_tst_func/cpp/teleworks/CMakeFiles/mockup_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cpp/teleworks/CMakeFiles/mockup_server.dir/depend

