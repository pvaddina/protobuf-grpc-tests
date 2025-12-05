cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

# Check if proto sources are defined
if(NOT DEFINED CALCULATOR_PROTO_SRCS)
  message(FATAL_ERROR "CALCULATOR_PROTO_SRCS not defined. Make sure interface subdirectory is processed first.")
endif()

# Mark generated files as GENERATED before using them
foreach(PROTO_SRC ${CALCULATOR_PROTO_SRCS})
  set_source_files_properties(${PROTO_SRC} PROPERTIES GENERATED TRUE)
endforeach()

# Client executable - add generated sources separately to avoid CMake checking them
add_executable(calculator_client client.cpp)

# Add generated proto sources
target_sources(calculator_client PRIVATE ${CALCULATOR_PROTO_SRCS})

# Include directories
target_include_directories(calculator_client PRIVATE
  ${CALCULATOR_PROTO_INCLUDE_DIR}
  ${Protobuf_INCLUDE_DIRS}
  ${GRPC_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(calculator_client
  ${Protobuf_LIBRARIES}
  ${GRPC_LIBRARIES}
)

# Dependencies
add_dependencies(calculator_client calculator_proto_target)

