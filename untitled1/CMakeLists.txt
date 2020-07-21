cmake_minimum_required(VERSION 3.12)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 testmenu.cpp menuList.h menuList.cpp command.h incrementCommand.h decrementCommand.h phoneBookEntry.h phoneBookEntry.cpp phoneBook.cpp phoneBook.h bookCommand.cpp bookCommand.h printCommand.cpp printCommand.h addUpdateCommand.cpp addUpdateCommand.h eraseCommand.cpp eraseCommand.h assignment2.cpp)