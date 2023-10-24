cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(head_unit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(BUILD_COMMONAPI true)
set(BUILD_SOMEIP_LIB true)

if(BUILD_COMMONAPI)
    if (NOT COMMON_API_FOUND)
        find_package(CommonAPI REQUIRED)

        include_directories(
            ${COMMONAPI_INCLUDE_DIRS}
        )
    endif()

    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

    include_directories(
        src-gen/core/common/gear
        src-gen/core/stub/gear
        src-gen/core/skel/gear
    )

    add_executable(head_unit
        src/main.cpp
        src/qml.qrc
        src/GearSelectionServer.cpp
        src/GearSelectionStubImpl.cpp
    )

    target_link_libraries(head_unit
        PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Network
        CommonAPI
    )

    install(TARGETS       head_unit 
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
        src-gen/someip/common/gear
        src-gen/someip/stub/gear
    )

    # stub
    FILE(GLOB_RECURSE GEAR_SOMEIP_STUB_LIB_SRCS 
        src-gen/someip/stub/gear/*.cpp
    )
    add_library(hu-gear-someipstub  SHARED
        ${GEAR_SOMEIP_STUB_LIB_SRCS}
    )
    target_link_libraries(hu-gear-someipstub
        CommonAPI-SomeIP
        vsomeip3
    )


endif()