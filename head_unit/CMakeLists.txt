cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(head_unit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

option(BUILD_HEAD_UNIT "Build the head_unit project" ON)
option(BUILD_SOMEIP_LIB "Build the helloworldsomeip libraries" ON)

if(BUILD_HEAD_UNIT)
    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)
    find_package(CommonAPI REQUIRED)

    include_directories(
        src-gen-gear/core/common
        src-gen-gear/core/stub
        src-gen-gear/core/skel
        ${COMMONAPI_INCLUDE_DIRS}
    )

    add_executable(head_unit
        src/main.cpp
        src/qml.qrc
        src/GearSelectionServer.cpp
        src/GearSelectionStubImpl.cpp
    )

    target_link_libraries(head_unit
        PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Network
        CommonAPI)
endif()

if(BUILD_SOMEIP_LIB)
    find_package(CommonAPI-SomeIP REQUIRED)
    find_package(vsomeip3 REQUIRED)

    include_directories(
        src-gen-gear/someip/common
        src-gen-gear/someip/stub
        ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
        ${VSOMEIP3_INCLUDE_DIRS}
    )

    # common
    FILE(GLOB_RECURSE HEAD_UNIT_SOMEIP_COMMON_LIB_SRCS 
        src-gen-gear/someip/common/*.cpp
    )
    add_library(headunitsomeipcommon  SHARED
        ${HEAD_UNIT_SOMEIP_COMMON_LIB_SRCS}
    )
    target_link_libraries(headunitsomeipcommon
        CommonAPI-SomeIP
        vsomeip3
    )
    install(TARGETS       headunitsomeipcommon
            DESTINATION   ${CMAKE_INSTALL_PREFIX}/lib/commonapi
    )

    # stub
    FILE(GLOB_RECURSE HEAD_UNIT_SOMEIP_STUB_LIB_SRCS 
        src-gen-gear/someip/stub/*.cpp
    )
    add_library(headunitsomeipstub  SHARED
        ${HEAD_UNIT_SOMEIP_STUB_LIB_SRCS}
    )
    target_link_libraries(headunitsomeipstub
        CommonAPI-SomeIP
        vsomeip3
    )
    install(TARGETS       headunitsomeipstub
            DESTINATION   ${CMAKE_INSTALL_PREFIX}/lib/commonapi
    )


endif()