cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(speed_sender)

option(BUILD_COMMONAPI "Build the CommonAPI" ON)
option(BUILD_SOMEIP_LIB "Build the SomeIP libraries" ON)

if(BUILD_COMMONAPI)
    find_package(CommonAPI REQUIRED)

    include_directories(
        src-gen/core/common/speed
        src-gen/core/stub/speed
        src-gen/core/skel/speed
        ${COMMONAPI_INCLUDE_DIRS}
    )

    add_executable(speed_sender
        src/main.cpp
        src/CanReceive.cpp
        src/SpeedServer.cpp
        src/SpeedStubImpl.cpp
    )

    target_link_libraries(speed_sender
        PRIVATE CommonAPI
    )

    install(TARGETS       speed_sender 
            DESTINATION   /usr/bin/DES3
    )

endif()

if(BUILD_SOMEIP_LIB)
    find_package(CommonAPI-SomeIP REQUIRED)
    find_package(vsomeip3 REQUIRED)

    include_directories(
        src-gen/someip/common/speed
        src-gen/someip/stub/speed
        ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
        ${VSOMEIP3_INCLUDE_DIRS}
    )

    # speed stub
    FILE(GLOB_RECURSE SPEED_SOMEIP_STUB_LIB_SRCS 
        src-gen/someip/stub/speed/*.cpp
    )
    add_library(speed-someipstub  SHARED
        ${SPEED_SOMEIP_STUB_LIB_SRCS}
    )
    target_link_libraries(speed-someipstub
        CommonAPI-SomeIP
        vsomeip3
    )


endif()