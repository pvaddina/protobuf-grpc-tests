cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(client-server-grpc-test)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(Protobuf REQUIRED)

# Find gRPC plugin
find_program(GRPC_CPP_PLUGIN grpc_cpp_plugin)
if(NOT GRPC_CPP_PLUGIN)
  message(FATAL_ERROR "grpc_cpp_plugin not found. Please install libgrpc++-dev or grpc-dev")
endif()

# Find gRPC libraries
find_library(GRPC_LIBRARY grpc++ PATHS /usr/lib /usr/local/lib)
find_library(GRPC_REFLECTION_LIBRARY grpc++_reflection PATHS /usr/lib /usr/local/lib)
find_path(GRPC_INCLUDE_DIR grpcpp/grpcpp.h PATHS /usr/include /usr/local/include)

if(NOT GRPC_LIBRARY OR NOT GRPC_INCLUDE_DIR)
  message(FATAL_ERROR "gRPC libraries not found. Please install libgrpc++-dev")
endif()

set(GRPC_LIBRARIES ${GRPC_LIBRARY})
set(GRPC_INCLUDE_DIRS ${GRPC_INCLUDE_DIR})
if(GRPC_REFLECTION_LIBRARY)
  set(GRPC_REFLECTION_LIBRARIES ${GRPC_REFLECTION_LIBRARY})
else()
  set(GRPC_REFLECTION_LIBRARIES "")
endif()

# Set gRPC plugin executable for interface CMakeLists.txt
set(Protobuf_GRPC_PLUGIN_EXECUTABLE ${GRPC_CPP_PLUGIN})

# Add subdirectories
add_subdirectory(interface)
add_subdirectory(server)
add_subdirectory(client)

