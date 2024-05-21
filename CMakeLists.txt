cmake_minimum_required(VERSION 3.28)
project(keylogger)

set(CMAKE_CXX_STANDARD 17)

add_executable(keylogger main.cpp
    Key.h
    Key.cpp
    Keylog.h
    KeyLog.cpp)
