cmake_minimum_required(VERSION 3.21)
project(TPTEST)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TPTEST
        db.cpp
        db.h
        main.cpp
        mainwindow.cpp
        mainwindow.h)
