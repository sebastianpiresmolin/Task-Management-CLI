cmake_minimum_required(VERSION 3.31)
project(Task-Management-CLI)

set(CMAKE_CXX_STANDARD 26)

add_executable(testing main.cpp
        greeting.cpp
        greeting.h
        menu.cpp
        menu.h
        Models/task.h
        listFiles.h
        addTask.h
        seedTask.h
        markDone.h
)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(testing PRIVATE nlohmann_json::nlohmann_json)
