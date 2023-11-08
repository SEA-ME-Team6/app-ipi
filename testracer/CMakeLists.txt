cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")


find_package(PythonLibs REQUIRED)

include_directories(
    src
    ${PYTHON_INCLUDE_DIRS}
)

add_executable(testracer
        src/main.cpp
        src/racer.cpp
        src/gamepad.cpp
        src/pythonmanager.cpp
)
target_link_libraries(testracer ${PYTHON_LIBRARIES})