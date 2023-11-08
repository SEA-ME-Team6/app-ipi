cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(racer)

set(BUILD_COMMONAPI true) #for single compile
set(BUILD_SOMEIP_LIB true) #for single compile

if(BUILD_COMMONAPI)
    if (NOT COMMON_API_FOUND)
        find_package(CommonAPI REQUIRED)

        include_directories(
            ${COMMONAPI_INCLUDE_DIRS}
        )
    endif()

    find_package(PythonLibs REQUIRED)

    include_directories(
        src
        src-gen/core/common/battery
        src-gen/core/stub/battery
        src-gen/core/skel/battery
        src-gen/core/common/gear
        src-gen/core/stub/gear
        src-gen/core/skel/gear
        src-gen/core/common/moving
        src-gen/core/proxy/moving
        ${PYTHON_INCLUDE_DIRS}
    )

    add_executable(racer
        src/main.cpp
        src/racer.cpp
        src/racersystem.cpp
        src/batterystubImpl.cpp
        src/gearstubImpl.cpp
    )

    target_link_libraries(racer
        PRIVATE           CommonAPI
        ${PYTHON_LIBRARIES}
    )

    install(TARGETS       racer 
            DESTINATION   /usr/bin/DES3
    )

endif()

if(BUILD_SOMEIP_LIB)
    if (NOT TOP_CMAKE_FOUND)
        find_package(CommonAPI-SomeIP REQUIRED)
        find_package(vsomeip3 REQUIRED)

        include_directories(
            ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
            ${VSOMEIP3_INCLUDE_DIRS}
        )
    endif()

    include_directories(
        src-gen/someip/common/battery
        src-gen/someip/stub/battery
        src-gen/someip/common/gear
        src-gen/someip/stub/gear
        src-gen/someip/common/moving
        src-gen/someip/proxy/moving
    )

    # battery stub
    FILE(GLOB_RECURSE     BATTERY_SOMEIP_STUB_LIB_SRCS 
        src-gen/someip/stub/battery/*.cpp
    )
    add_library(rc-batterysomeipstub  SHARED
        ${BATTERY_SOMEIP_STUB_LIB_SRCS}
    )
    target_link_libraries(rc-batterysomeipstub
        CommonAPI-SomeIP
        vsomeip3
    )

    # gear stub
    FILE(GLOB_RECURSE     GEAR_SOMEIP_STUB_LIB_SRCS 
    src-gen/someip/stub/gear/*.cpp
    )
    add_library(rc-gearsomeipstub  SHARED
        ${GEAR_SOMEIP_STUB_LIB_SRCS}
    )
    target_link_libraries(rc-gearsomeipstub
        CommonAPI-SomeIP
        vsomeip3
    )

    # battery proxy
    FILE(GLOB_RECURSE MOVING_SOMEIP_PROXY_LIB_SRCS 
    src-gen/someip/proxy/moving/*.cpp
    )
    add_library(rc-movingsomeipproxy  SHARED
        ${MOVING_SOMEIP_PROXY_LIB_SRCS}
    )
    target_link_libraries(rc-movingsomeipproxy
        CommonAPI-SomeIP
        vsomeip3
    )


endif()