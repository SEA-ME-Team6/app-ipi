cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(instrument_cluster)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

option(BUILD_COMMONAPI "Build the CommonAPI" OFF)
option(BUILD_SOMEIP_LIB "Build the SomeIP libraries" ON)

if(BUILD_COMMONAPI)
    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)
    find_package(CommonAPI REQUIRED)

    include_directories(
        src-gen/core/common/battery
        src-gen/core/proxy/battery
        src-gen/core/common/gear
        src-gen/core/proxy/gear
        src-gen/core/common/speed
        src-gen/core/proxy/speed
        ${COMMONAPI_INCLUDE_DIRS}
    )

    add_executable(instrument_cluster
        src/main.cpp
        src/qml.qrc
        src/VehicleStatusClient.cpp
    )

    target_link_libraries(instrument_cluster
        PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Network
        CommonAPI)
endif()

if(BUILD_SOMEIP_LIB)
    find_package(CommonAPI-SomeIP REQUIRED)
    find_package(vsomeip3 REQUIRED)

    include_directories(
        src-gen/someip/common/battery
        src-gen/someip/proxy/battery
        src-gen/someip/common/gear
        src-gen/someip/proxy/gear
        src-gen/someip/common/speed
        src-gen/someip/proxy/speed
        ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
        ${VSOMEIP3_INCLUDE_DIRS}
    )

    # battery proxy
    FILE(GLOB_RECURSE BATTERY_SOMEIP_STUB_LIB_SRCS 
        src-gen/someip/proxy/battery/*.cpp
    )
    add_library(battery-someipstub  SHARED
        ${BATTERY_SOMEIP_STUB_LIB_SRCS}
    )
    target_link_libraries(battery-someipstub
        CommonAPI-SomeIP
        vsomeip3
    )

    # gear proxy
    FILE(GLOB_RECURSE GEAR_SOMEIP_STUB_LIB_SRCS 
        src-gen/someip/proxy/gear/*.cpp
    )
    add_library(gear-someipstub  SHARED
        ${GEAR_SOMEIP_STUB_LIB_SRCS}
    )
    target_link_libraries(gear-someipstub
        CommonAPI-SomeIP
        vsomeip3
    )

    # speed proxy
    FILE(GLOB_RECURSE SPEED_SOMEIP_STUB_LIB_SRCS 
        src-gen/someip/proxy/gear/*.cpp
    )
    add_library(speed-someipstub  SHARED
        ${SPEED_SOMEIP_STUB_LIB_SRCS}
    )
    target_link_libraries(speed-someipstub
        CommonAPI-SomeIP
        vsomeip3
    )


endif()