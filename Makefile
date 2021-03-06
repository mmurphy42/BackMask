# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.11.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.11.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mmurphy/vm-spotmarket/repositories/BackMask

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mmurphy/vm-spotmarket/repositories/BackMask

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.11.4/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.11.4/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.11.4/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.11.4/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.11.4/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.11.4/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.11.4/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/mmurphy/vm-spotmarket/repositories/BackMask/CMakeFiles /Users/mmurphy/vm-spotmarket/repositories/BackMask/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/mmurphy/vm-spotmarket/repositories/BackMask/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named BackMask

# Build rule for target.
BackMask: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 BackMask
.PHONY : BackMask

# fast build rule for target.
BackMask/fast:
	$(MAKE) -f CMakeFiles/BackMask.dir/build.make CMakeFiles/BackMask.dir/build
.PHONY : BackMask/fast

src/GlobalWorker.o: src/GlobalWorker.cpp.o

.PHONY : src/GlobalWorker.o

# target to build an object file
src/GlobalWorker.cpp.o:
	$(MAKE) -f CMakeFiles/BackMask.dir/build.make CMakeFiles/BackMask.dir/src/GlobalWorker.cpp.o
.PHONY : src/GlobalWorker.cpp.o

src/GlobalWorker.i: src/GlobalWorker.cpp.i

.PHONY : src/GlobalWorker.i

# target to preprocess a source file
src/GlobalWorker.cpp.i:
	$(MAKE) -f CMakeFiles/BackMask.dir/build.make CMakeFiles/BackMask.dir/src/GlobalWorker.cpp.i
.PHONY : src/GlobalWorker.cpp.i

src/GlobalWorker.s: src/GlobalWorker.cpp.s

.PHONY : src/GlobalWorker.s

# target to generate assembly for a file
src/GlobalWorker.cpp.s:
	$(MAKE) -f CMakeFiles/BackMask.dir/build.make CMakeFiles/BackMask.dir/src/GlobalWorker.cpp.s
.PHONY : src/GlobalWorker.cpp.s

src/StringViewMaskTrie.o: src/StringViewMaskTrie.cpp.o

.PHONY : src/StringViewMaskTrie.o

# target to build an object file
src/StringViewMaskTrie.cpp.o:
	$(MAKE) -f CMakeFiles/BackMask.dir/build.make CMakeFiles/BackMask.dir/src/StringViewMaskTrie.cpp.o
.PHONY : src/StringViewMaskTrie.cpp.o

src/StringViewMaskTrie.i: src/StringViewMaskTrie.cpp.i

.PHONY : src/StringViewMaskTrie.i

# target to preprocess a source file
src/StringViewMaskTrie.cpp.i:
	$(MAKE) -f CMakeFiles/BackMask.dir/build.make CMakeFiles/BackMask.dir/src/StringViewMaskTrie.cpp.i
.PHONY : src/StringViewMaskTrie.cpp.i

src/StringViewMaskTrie.s: src/StringViewMaskTrie.cpp.s

.PHONY : src/StringViewMaskTrie.s

# target to generate assembly for a file
src/StringViewMaskTrie.cpp.s:
	$(MAKE) -f CMakeFiles/BackMask.dir/build.make CMakeFiles/BackMask.dir/src/StringViewMaskTrie.cpp.s
.PHONY : src/StringViewMaskTrie.cpp.s

src/ThreadWorker.o: src/ThreadWorker.cpp.o

.PHONY : src/ThreadWorker.o

# target to build an object file
src/ThreadWorker.cpp.o:
	$(MAKE) -f CMakeFiles/BackMask.dir/build.make CMakeFiles/BackMask.dir/src/ThreadWorker.cpp.o
.PHONY : src/ThreadWorker.cpp.o

src/ThreadWorker.i: src/ThreadWorker.cpp.i

.PHONY : src/ThreadWorker.i

# target to preprocess a source file
src/ThreadWorker.cpp.i:
	$(MAKE) -f CMakeFiles/BackMask.dir/build.make CMakeFiles/BackMask.dir/src/ThreadWorker.cpp.i
.PHONY : src/ThreadWorker.cpp.i

src/ThreadWorker.s: src/ThreadWorker.cpp.s

.PHONY : src/ThreadWorker.s

# target to generate assembly for a file
src/ThreadWorker.cpp.s:
	$(MAKE) -f CMakeFiles/BackMask.dir/build.make CMakeFiles/BackMask.dir/src/ThreadWorker.cpp.s
.PHONY : src/ThreadWorker.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/BackMask.dir/build.make CMakeFiles/BackMask.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/BackMask.dir/build.make CMakeFiles/BackMask.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/BackMask.dir/build.make CMakeFiles/BackMask.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... BackMask"
	@echo "... src/GlobalWorker.o"
	@echo "... src/GlobalWorker.i"
	@echo "... src/GlobalWorker.s"
	@echo "... src/StringViewMaskTrie.o"
	@echo "... src/StringViewMaskTrie.i"
	@echo "... src/StringViewMaskTrie.s"
	@echo "... src/ThreadWorker.o"
	@echo "... src/ThreadWorker.i"
	@echo "... src/ThreadWorker.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

