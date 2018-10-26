cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(dummy_interface_definitions)

set(Protobuf_LIBRARIES "C:/Users/praka/workspace/third_party/protobuf/install/Release/lib")
set(Protobuf_INCLUDE_DIR "C:/Users/praka/workspace/third_party/protobuf/install/Release/include")
set(Protobuf_PROTOC_EXECUTABLE "C:/Users/praka/workspace/third_party/protobuf/install/Release/bin/protoc.exe")
set(Protobuf_USE_STATIC_LIBS ON)
#message("Current module path before setting=${CMAKE_MODULE_PATH}")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "c:/Program Files (x86)/protobuf/lib/cmake/protobuf")
#message("Current module path=${CMAKE_MODULE_PATH}")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

find_package(Protobuf REQUIRED)
if (NOT Protobuf_FOUND)
  message(FATAL_ERROR "######################### Package Protobuf is not found")
endif()

set(SOURCES base.proto dht.proto)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
SET_SOURCE_FILES_PROPERTIES(${PROTO_SRCS} ${PROTO_HDRS} PROPERTIES GENERATED TRUE)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${SOURCES})
#protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS EXPORT_MACRO DLL_EXPORT ${SOURCES})
#protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS DESCRIPTORS PROTO_DESCS ${SOURCES})

message("Protobuf include dirs=${PROTOBUF_INCLUDE_DIRS}")
message("Protobuf lib=${PROTOBUF_LIBRARY}")
message("Protobuf_PROTOC_LIBRARIES=${PROTOBUF_PROTOC_LIBRARIES}")
message("Protobuf_LIBRARY=${PROTOBUF_LIBRARY}")
message("Protobuf_PROTOC_LIBRARY=${PROTOBUF_PROTOC_LIBRARY}")
message("Protobuf_LIBRARY_DEBUG=${PROTOBUF_LIBRARY_DEBUG}")
message("Protobuf_PROTOC_LIBRARY_DEBUG=${PROTOBUF_PROTOC_LIBRARY_DEBUG}")
message("Protobuf_LIBRARIES=${PROTOBUF_LIBRARIES}")
message("Protobuf_INCLUDE_DIR=${PROTOBUF_INCLUDE_DIR}")
message("Protobuf_PROTOC_EXECUTABLE=${PROTOBUF_PROTOC_EXECUTABLE}")

if (BUILD_STATIC_LIBRARY_ONLY)
  add_library(if STATIC ${PROTO_SRCS} ${PROTO_HDRS})
else()
  add_executable(testApp test.cpp ${PROTO_SRCS} ${PROTO_HDRS})
  target_link_libraries(testApp ${Protobuf_LIBRARIES}/libprotobuf.lib)
endif()


