cmake_minimum_required(VERSION 3.14)
project(DES3_HEAD_UNIT)

set(BUILD_COMMONAPI true CACHE BOOL "Build the CommonAPI")
set(BUILD_SOMEIP_LIB true CACHE BOOL "Build the SOMEIP")
set(TOP_CMAKE_FOUND true CACHE BOOL "Found Top of CMakeFIle")


if(BUILD_COMMONAPI)
    find_package(CommonAPI REQUIRED)

    include_directories(
        ${COMMONAPI_INCLUDE_DIRS}
    )
endif()

if(BUILD_SOMEIP_LIB)
    find_package(CommonAPI-SomeIP REQUIRED)
    find_package(vsomeip3 REQUIRED)

    include_directories(
        ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
        ${VSOMEIP3_INCLUDE_DIRS}
    )
endif()

add_subdirectory(gamepad)
add_subdirectory(head_unit)
add_subdirectory(instrument_cluster)
add_subdirectory(racer)
add_subdirectory(speed_sender)