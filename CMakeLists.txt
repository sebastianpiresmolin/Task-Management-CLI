cmake_minimum_required(VERSION 3.31)
project(Task-Management-CLI)

set(CMAKE_CXX_STANDARD 20)

if(MINGW)
    add_compile_options(-static-libgcc -static-libstdc++ -static)
    add_link_options(-static -static-libgcc -static-libstdc++)
endif()

add_executable(testing
        main.cpp
        greeting.cpp
        greeting.h
        menu.cpp
        menu.h
        Models/task.h
        listFiles.h
        addTask.h
        markDone.h
        exportTasks.cpp
        exportTasks.h
        importTasks.cpp
        importTasks.h
)

find_package(nlohmann_json 3.11.2 REQUIRED)
target_link_libraries(testing PRIVATE nlohmann_json::nlohmann_json)