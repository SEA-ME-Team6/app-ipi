cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(battery_sender)

option(BUILD_COMMONAPI "Build the CommonAPI" ON)
option(BUILD_SOMEIP_LIB "Build the SomeIP libraries" ON)

if(BUILD_COMMONAPI)
    find_package(CommonAPI REQUIRED)
    find_package(PythonLibs REQUIRED)

    include_directories(
        src/piracer
        src-gen/core/common/battery
        src-gen/core/stub/battery
        src-gen/core/skel/battery
        ${COMMONAPI_INCLUDE_DIRS}
        ${PYTHON_INCLUDE_DIRS}
    )

    add_executable(battery_sender
        src/main.cpp
        src/BatteryServer.cpp
        src/BatteryStubImpl.cpp
        src/piracer/piracer.cpp
        src/piracer/PythonManager.cpp
    )

    target_link_libraries(battery_sender
        PRIVATE           CommonAPI
        ${PYTHON_LIBRARIES}
    )

    install(TARGETS       battery_sender 
            DESTINATION   /usr/bin
    )

endif()

if(BUILD_SOMEIP_LIB)
    find_package(CommonAPI-SomeIP REQUIRED)
    find_package(vsomeip3 REQUIRED)

    include_directories(
        src-gen/someip/common/battery
        src-gen/someip/stub/battery
        ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
        ${VSOMEIP3_INCLUDE_DIRS}
    )

    # battery stub
    FILE(GLOB_RECURSE     BATTERY_SOMEIP_STUB_LIB_SRCS 
        src-gen/someip/stub/battery/*.cpp
    )
    add_library(battery-someipstub  SHARED
        ${BATTERY_SOMEIP_STUB_LIB_SRCS}
    )
    target_link_libraries(battery-someipstub
        CommonAPI-SomeIP
        vsomeip3
    )


endif()