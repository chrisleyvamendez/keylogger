cmake_minimum_required(VERSION 3.28)
project(keylogger)

set(CMAKE_CXX_STANDARD 17)
# include the subdirectory files
set(CMAKE_EXE_LINKER_FLAGS "-static -mwindows")

add_executable(keylogger src/main.cpp
    include/Key.h
    src/Key.cpp
    include/Keylog.h
    src/KeyLog.cpp
    src/FileHandler.cpp
    include/FileHandler.h)
