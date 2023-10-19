cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(gamepad)

option(BUILD_COMMONAPI "Build the CommonAPI" ON)
option(BUILD_SOMEIP_LIB "Build the SomeIP libraries" ON)

if(BUILD_COMMONAPI)
    find_package(CommonAPI REQUIRED)
    find_package(PythonLibs REQUIRED)

    include_directories(
        src/piracer
        src-gen/core/common/gear
        src-gen/core/proxy/gear
        ${COMMONAPI_INCLUDE_DIRS}
        ${PYTHON_INCLUDE_DIRS}
    )

    add_executable(gamepad
        src/main.cpp
        src/Gamepad.cpp
        src/GearSelectionClient.cpp
        src/piracer/piracer.cpp
        src/piracer/PythonManager.cpp
    )

    target_link_libraries(gamepad
        PRIVATE           CommonAPI
        ${PYTHON_LIBRARIES}
    )

    install(TARGETS       gamepad 
            DESTINATION   /usr/bin/DES3
    )

endif()

if(BUILD_SOMEIP_LIB)
    find_package(CommonAPI-SomeIP REQUIRED)
    find_package(vsomeip3 REQUIRED)

    include_directories(
        src-gen/someip/common/gear
        src-gen/someip/proxy/gear
        ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
        ${VSOMEIP3_INCLUDE_DIRS}
    )

    #gear stub
    FILE(GLOB_RECURSE    GEAR_SOMEIP_PROXY_LIB_SRCS 
        src-gen/someip/proxy/gear/*.cpp
    )
    add_library(gear-someipproxy  SHARED
        ${GEAR_SOMEIP_PROXY_LIB_SRCS}
    )
    target_link_libraries(gear-someipproxy
        CommonAPI-SomeIP
        vsomeip3
    )


endif()