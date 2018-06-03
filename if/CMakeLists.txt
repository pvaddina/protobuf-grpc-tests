cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(dummy_interface_definitions)

set(Protobuf_LIBRARIES "c:/Program Files (x86)/protobuf/lib")
set(Protobuf_INCLUDE_DIR "c:/Program Files (x86)/protobuf/include")
#message("Current module path before setting=${CMAKE_MODULE_PATH}")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "c:/Program Files (x86)/protobuf/lib/cmake/protobuf")
#message("Current module path=${CMAKE_MODULE_PATH}")

set(SOURCES base.proto)

message( "########### In root cmake file and before adding subdirec: ${SOURCES} and ${CMAKE_CURRENT_SOURCE_DIR}")
add_subdirectory(dht)
message( "########### In root cmake file and after adding subdirec: ${SOURCES} and ${CMAKE_CURRENT_SOURCE_DIR}")

find_package(Protobuf REQUIRED)
if (NOT Protobuf_FOUND)
  message(FATAL_ERROR "Package Protobuf is not found")
endif()

SET_SOURCE_FILES_PROPERTIES(${PROTO_SRCS} ${PROTO_HDRS} PROPERTIES GENERATED TRUE)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${SOURCES})
