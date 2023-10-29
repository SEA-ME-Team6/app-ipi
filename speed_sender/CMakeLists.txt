cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(speed_sender)

set(BUILD_COMMONAPI true)
set(BUILD_SOMEIP_LIB true)

if(BUILD_COMMONAPI)
    if (NOT COMMON_API_FOUND)
        find_package(CommonAPI REQUIRED)

        include_directories(
            ${COMMONAPI_INCLUDE_DIRS}
        )
    endif()

    include_directories(
        src-gen/core/common/speed
        src-gen/core/stub/speed
        src-gen/core/skel/speed
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
    if (NOT TOP_CMAKE_FOUND)
        find_package(CommonAPI-SomeIP REQUIRED)
        find_package(vsomeip3 REQUIRED)

        include_directories(
            ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
            ${VSOMEIP3_INCLUDE_DIRS}
        )
    endif()

    include_directories(
        src-gen/someip/common/speed
        src-gen/someip/stub/speed
    )

    # speed stub
    FILE(GLOB_RECURSE SPEED_SOMEIP_STUB_LIB_SRCS 
        src-gen/someip/stub/speed/*.cpp
    )
    add_library(ss-speedsomeipstub  SHARED
        ${SPEED_SOMEIP_STUB_LIB_SRCS}
    )
    target_link_libraries(ss-speedsomeipstub
        CommonAPI-SomeIP
        vsomeip3
    )


endif()