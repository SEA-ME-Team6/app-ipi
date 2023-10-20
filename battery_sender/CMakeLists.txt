cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(battery_sender)

# set(BUILD_COMMONAPI true)
# set(BUILD_SOMEIP_LIB true)

if(BUILD_COMMONAPI)
    if (NOT COMMON_API_FOUND)
        find_package(CommonAPI REQUIRED)

        include_directories(
            ${COMMONAPI_INCLUDE_DIRS}
        )
    endif()

    find_package(PythonLibs REQUIRED)

    include_directories(
        src/piracer
        src-gen/core/common/battery
        src-gen/core/stub/battery
        src-gen/core/skel/battery
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
    )

    # battery stub
    FILE(GLOB_RECURSE     BATTERY_SOMEIP_STUB_LIB_SRCS 
        src-gen/someip/stub/battery/*.cpp
    )
    add_library(bs-battery-someipstub  SHARED
        ${BATTERY_SOMEIP_STUB_LIB_SRCS}
    )
    target_link_libraries(bs-battery-someipstub
        CommonAPI-SomeIP
        vsomeip3
    )


endif()