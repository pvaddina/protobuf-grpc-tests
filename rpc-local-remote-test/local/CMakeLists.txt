cmake_minimum_required(VERSION 3.5.1)
project(Local-Connection)

set (SRCS local.cpp)

add_library(local STATIC ${SRCS})
target_include_directories(local PUBLIC ../gen "c:/Users/praka/workspace/third-party/protobuf/install/Release/include" "c:/Users/praka/workspace/third-party/grpc/include")


