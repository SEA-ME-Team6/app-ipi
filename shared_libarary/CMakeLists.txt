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
    ../rpm_sender/src-gen/someip/stub/rpm
)

# rpm stub
FILE(GLOB_RECURSE RPM_SOMEIP_STUB_LIB_SRCS 
    ../rpm_sender/src-gen/someip/stub/rpm/*.cpp
)
add_library(ss-rpmsomeipstub  SHARED
    ${RPM_SOMEIP_STUB_LIB_SRCS}
)
target_link_libraries(ss-rpmsomeipstub
    CommonAPI-SomeIP
    vsomeip3
)
