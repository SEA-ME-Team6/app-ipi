cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(shared_libarary)

find_package(CommonAPI REQUIRED)
find_package(CommonAPI-SomeIP REQUIRED)
find_package(vsomeip3 REQUIRED)

include_directories(
    ${COMMONAPI_INCLUDE_DIRS}
    ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
    ${VSOMEIP3_INCLUDE_DIRS}
)

include_directories(
    ../rpm_sender/src-gen/core/common/rpm
    ../rpm_sender/src-gen/core/stub/rpm
    ../rpm_sender/src-gen/someip/common/rpm
    ../rpm_sender/src-gen/someip/proxy/rpm
    ../rpm_sender/src-gen/someip/stub/rpm

    ../gamepad/src-gen/core/common/moving
    ../gamepad/src-gen/core/stub/moving
    ../gamepad/src-gen/someip/common/moving
    ../gamepad/src-gen/someip/stub/moving

    ../gamepad/src-gen/core/common/light
    ../gamepad/src-gen/core/stub/light
    ../gamepad/src-gen/someip/common/light
    ../gamepad/src-gen/someip/stub/light

    ../gamepad/src-gen/core/common/light
    ../gamepad/src-gen/core/stub/light
    ../gamepad/src-gen/someip/common/light
    ../head_unit/src-gen/someip/proxy/light
    ../gamepad/src-gen/someip/stub/light

    ../head_unit/src-gen/someip/common/gear
    ../head_unit/src-gen/someip/proxy/gear
)

# rpm stub
FILE(GLOB_RECURSE RPM_SOMEIP_STUB_LIB_SRCS 
    ../rpm_sender/src-gen/someip/stub/rpm/*.cpp
)
add_library(rpmsomeipstub  SHARED
    ${RPM_SOMEIP_STUB_LIB_SRCS}
)

# moving stub
FILE(GLOB_RECURSE MOVING_SOMEIP_STUB_LIB_SRCS 
    src-gen/someip/stub/moving/*.cpp
)
add_library(movingsomeipstub  SHARED
    ${MOVING_SOMEIP_STUB_LIB_SRCS}
)

# light stub
FILE(GLOB_RECURSE LIGHT_SOMEIP_STUB_LIB_SRCS 
    src-gen/someip/stub/light/*.cpp
)
add_library(lightsomeipstub  SHARED
    ${LIGHT_SOMEIP_STUB_LIB_SRCS}
)







target_link_libraries(
    rpmsomeipstub
    movingsomeipstub
    lightsomeipstub
    CommonAPI-SomeIP
    vsomeip3
)
