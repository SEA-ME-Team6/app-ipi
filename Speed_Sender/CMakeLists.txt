cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
include_directories(
    src
    ../src-gen-cluster
    ~/build-commonapi/capicxx-core-runtime/include
    ~/build-commonapi/capicxx-someip-runtime/include
    ~/build-commonapi/vsomeip/interface
)
link_directories(
    ~/build-commonapi/capicxx-core-runtime/build
    ~/build-commonapi/capicxx-someip-runtime/build
    ~/build-commonapi/vsomeip/build
)

add_executable(Speed_Sender
        src/CanReceive.cpp
        src/main.cpp
        src/SpeedServer.cpp
        src/SpeedStubImpl.cpp
        ../src-gen-cluster/v1/commonapi/SpeedStatusSomeIPStubAdapter.cpp
        ../src-gen-cluster/v1/commonapi/SpeedStatusSomeIPDeployment.cpp
)
target_link_libraries(Speed_Sender CommonAPI CommonAPI-SomeIP vsomeip3)



