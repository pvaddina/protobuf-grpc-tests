cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

# Proto files
set(PROTO_FILES calculator.proto)

# Generated output directory
set(GEN_DIR ${CMAKE_CURRENT_BINARY_DIR}/gen)
file(MAKE_DIRECTORY ${GEN_DIR})

# Generate protobuf files
set(PROTO_SRCS "")
set(PROTO_HDRS "")
set(GRPC_SRCS "")
set(GRPC_HDRS "")

foreach(PROTO_FILE ${PROTO_FILES})
  get_filename_component(PROTO_NAME ${PROTO_FILE} NAME_WE)
  get_filename_component(PROTO_PATH ${PROTO_FILE} ABSOLUTE)
  
  # Protobuf generated files
  list(APPEND PROTO_SRCS "${GEN_DIR}/${PROTO_NAME}.pb.cc")
  list(APPEND PROTO_HDRS "${GEN_DIR}/${PROTO_NAME}.pb.h")
  
  # gRPC generated files
  list(APPEND GRPC_SRCS "${GEN_DIR}/${PROTO_NAME}.grpc.pb.cc")
  list(APPEND GRPC_HDRS "${GEN_DIR}/${PROTO_NAME}.grpc.pb.h")
endforeach()

# Generate protobuf C++ files
add_custom_command(
  OUTPUT ${PROTO_SRCS} ${PROTO_HDRS}
  COMMAND ${Protobuf_PROTOC_EXECUTABLE}
  ARGS --cpp_out=${GEN_DIR}
       --proto_path=${CMAKE_CURRENT_SOURCE_DIR}
       ${PROTO_FILES}
  DEPENDS ${PROTO_FILES}
  COMMENT "Running protoc compiler on ${PROTO_FILES}"
)

# Generate gRPC C++ files
if(Protobuf_GRPC_PLUGIN_EXECUTABLE)
  add_custom_command(
    OUTPUT ${GRPC_SRCS} ${GRPC_HDRS}
    COMMAND ${Protobuf_PROTOC_EXECUTABLE}
    ARGS --grpc_out=${GEN_DIR}
         --plugin=protoc-gen-grpc=${Protobuf_GRPC_PLUGIN_EXECUTABLE}
         --proto_path=${CMAKE_CURRENT_SOURCE_DIR}
         ${PROTO_FILES}
    DEPENDS ${PROTO_FILES} ${PROTO_SRCS} ${PROTO_HDRS}
    COMMENT "Running gRPC protoc plugin on ${PROTO_FILES}"
  )
else()
  # Try to find grpc_cpp_plugin
  find_program(GRPC_CPP_PLUGIN grpc_cpp_plugin)
  if(GRPC_CPP_PLUGIN)
    add_custom_command(
      OUTPUT ${GRPC_SRCS} ${GRPC_HDRS}
      COMMAND ${Protobuf_PROTOC_EXECUTABLE}
      ARGS --grpc_out=${GEN_DIR}
           --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN}
           --proto_path=${CMAKE_CURRENT_SOURCE_DIR}
           ${PROTO_FILES}
      DEPENDS ${PROTO_FILES} ${PROTO_SRCS} ${PROTO_HDRS}
      COMMENT "Running gRPC protoc plugin on ${PROTO_FILES}"
    )
  else()
    message(FATAL_ERROR "gRPC plugin not found. Please install grpc-dev or set Protobuf_GRPC_PLUGIN_EXECUTABLE")
  endif()
endif()

# Mark generated files as GENERATED so CMake knows they don't exist yet
set_source_files_properties(${PROTO_SRCS} ${PROTO_HDRS} ${GRPC_SRCS} ${GRPC_HDRS}
  PROPERTIES GENERATED TRUE
)

# Create a target for the generated files
add_custom_target(calculator_proto_target
  DEPENDS ${PROTO_SRCS} ${PROTO_HDRS} ${GRPC_SRCS} ${GRPC_HDRS}
)

# Make the generated directory available to other targets
set(CALCULATOR_PROTO_INCLUDE_DIR ${GEN_DIR} PARENT_SCOPE)
set(CALCULATOR_PROTO_SRCS ${PROTO_SRCS} ${GRPC_SRCS} PARENT_SCOPE)
set(CALCULATOR_PROTO_HDRS ${PROTO_HDRS} ${GRPC_HDRS} PARENT_SCOPE)

