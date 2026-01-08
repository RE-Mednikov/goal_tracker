cmake_minimum_required(VERSION 4.1)
project(goal_tracker)

set(CMAKE_CXX_STANDARD 20)

add_executable(goal_tracker src/main.cpp
        include/goaltracker/data.h
        include/goaltracker/types.h
        include/goaltracker/storage.h
        include/goaltracker/logic.h
        include/goaltracker/commands.h
        src/storage.cpp
        src/logic.cpp
        src/commands.cpp)

target_include_directories(goal_tracker PRIVATE ${CMAKE_SOURCE_DIR}/include)
