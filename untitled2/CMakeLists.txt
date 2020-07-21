cmake_minimum_required(VERSION 3.12)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled2 stack.h stack.cpp undoRedo.cpp undoRedo.h insertUndoRedoCommand.cpp insertUndoRedoCommand.h eraseUndoRedoCommand.h eraseUndoRedoCommand.cpp undoCommand.cpp undoCommand.h redoCommand.h redoCommand.cpp addUpdateCommand.cpp addUpdateCommand.h eraseCommand.cpp eraseCommand.h assignment3.cpp updateUndoRedoCommand.cpp updateUndoRedoCommand.h)