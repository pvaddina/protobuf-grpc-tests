cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(dummy-interface-with-static-target)

include("../cmake_include/common.txt")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

set(PROTO_SUORCES 
  ${CMAKE_CURRENT_SOURCE_DIR}/base.proto 
  ${CMAKE_CURRENT_SOURCE_DIR}/dht.proto)

set (GEN_DEST_DIR ${CMAKE_CURRENT_BINARY_DIR}/gen)
file(MAKE_DIRECTORY ${GEN_DEST_DIR})

foreach(pfile ${PROTO_SUORCES}) 
  string(REPLACE ".proto" ".pb" fname ${pfile})
  string(CONCAT cc ${CMAKE_CURRENT_BINARY_DIR} "/" ${fname} ".cc")
  string(CONCAT h ${CMAKE_CURRENT_BINARY_DIR} "/" ${fname} ".h")
  #  message(${cc} " - " ${h})
  set(GEN_CPP_SOURCES ${GEN_CPP_SOURCES} ${cc} ${h})
endforeach()

add_custom_command(OUTPUT ${GEN_CPP_SOURCES}
  COMMAND ${Protobuf_PROTOC_EXECUTABLE} --cpp_out=${GEN_DEST_DIR} --proto_path=${CMAKE_CURRENT_SOURCE_DIR} ${PROTO_SUORCES}
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  COMMENT "Runnning the protobuf compiler"
  VERBATIM
)

add_custom_target(echo_target ALL DEPENDS ${GEN_CPP_SOURCES})



