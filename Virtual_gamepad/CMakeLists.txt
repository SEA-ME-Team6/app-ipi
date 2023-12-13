cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(Virtual_gamepad)

if (NOT TOP_CMAKE_FOUND)
    find_package(CommonAPI REQUIRED)

    include_directories(
        ${COMMONAPI_INCLUDE_DIRS}
    )
endif()

find_package(PythonLibs REQUIRED)

include_directories(
    ../src-gen/light/core/common
    ../src-gen/light/core/stub
    ../src-gen/light/core/skel
)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/gamepadsystem.cpp
    src/lightstubImpl.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE           CommonAPI
    ${PYTHON_LIBRARIES}
)

install(TARGETS       ${PROJECT_NAME} 
        DESTINATION   /usr/bin/DES3/gamepad
)
