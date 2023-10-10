cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")


find_package(PythonLibs REQUIRED)

include_directories(
    src
    ../common
    ../../src-gen-cluster
    ~/build-commonapi/capicxx-core-runtime/include
    ~/build-commonapi/capicxx-someip-runtime/include
    ~/build-commonapi/vsomeip/interface
    ${PYTHON_INCLUDE_DIRS}
)

link_directories(
    ~/build-commonapi/capicxx-core-runtime/build
    ~/build-commonapi/capicxx-someip-runtime/build
    ~/build-commonapi/vsomeip/build
)

add_executable(Battery
        src/main.cpp
        src/BatteryServer.cpp
        src/BatteryStubImpl.cpp
        ../common/piracer.cpp
        ../common/PythonManager.cpp
        ../../src-gen-cluster/v1/commonapi/BatteryStatusSomeIPStubAdapter.cpp
        ../../src-gen-cluster/v1/commonapi/BatteryStatusSomeIPDeployment.cpp
)
target_link_libraries(Battery CommonAPI CommonAPI-SomeIP vsomeip3 ${PYTHON_LIBRARIES})



