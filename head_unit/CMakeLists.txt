cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -Wl,--no-as-needed")

project(head_unit)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if (NOT TOP_CMAKE_FOUND)
    find_package(CommonAPI REQUIRED)

    include_directories(
        ${COMMONAPI_INCLUDE_DIRS}
    )
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

include_directories(
    ../src-gen/gear/core/common
    ../src-gen/gear/core/proxy
    ../src-gen/rpm/core/common
    ../src-gen/rpm/core/proxy
    ../src-gen/light/core/common
    ../src-gen/light/core/proxy
)

add_executable(head_unit
    src/main.cpp
    src/qml.qrc
    src/husystem.cpp
)

target_link_libraries(head_unit
    PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Network
    CommonAPI
)

install(TARGETS       head_unit 
        DESTINATION   /usr/bin/DES3/head_unit
)
