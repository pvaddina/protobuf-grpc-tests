cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(dummy-interface-with-static-target)


function(list_print liItems)
    message(STATUS "#############################################")
  foreach(f ${${liItems}})
    message(STATUS ${f})
  endforeach()
    message(STATUS "#############################################\n")
endfunction()


function(concat_path iL oL cVal) 
  foreach(pfile ${${iL}})
    string(CONCAT l ${${cVal}} ${pfile})
    #message(STATUS ${pfile} " ################################### " ${l})
    set(p ${p} ${l})
  endforeach()
  set(${oL} ${p} PARENT_SCOPE)
endfunction()


set(Protobuf_LIBRARIES "C:/Users/praka/workspace/third-party/protobuf/install/Release/lib")
set(Protobuf_INCLUDE_DIR "C:/Users/praka/workspace/third-party/protobuf/install/Release/include")
set(Protobuf_PROTOC_EXECUTABLE "C:/Users/praka/workspace/third-party/protobuf/install/Release/bin/protoc.exe")
set(Protobuf_USE_STATIC_LIBS ON)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

find_package(Protobuf REQUIRED)
if (NOT Protobuf_FOUND)
  message(FATAL_ERROR "######################### Package Protobuf is not found")
endif()

set(PROTO_SRCS base.proto)


foreach(pfile ${PROTO_SRCS}) 
  string(REPLACE ".proto" ".pb" fname ${pfile})
  string(CONCAT cc ${fname} ".cc")
  string(CONCAT h ${fname} ".h")
  set(PROTO_CPP_SRCS ${PROTO_CPP_SRCS} ${cc} ${h})
endforeach()


string(CONCAT path_prefix ${CMAKE_CURRENT_SOURCE_DIR} "/")
string(CONCAT gen_path_prefix ${CMAKE_CURRENT_SOURCE_DIR} "/gen/")
concat_path(PROTO_SRCS PROTO_SRCS_PATH path_prefix)
concat_path(PROTO_CPP_SRCS PROTO_CPP_SRCS_PATH gen_path_prefix)
list_print(PROTO_SRCS_PATH)
list_print(PROTO_CPP_SRCS_PATH)


set (GEN_DEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/gen)
file(MAKE_DIRECTORY ${GEN_DEST_DIR})
message("GEN_DEST_DIR = " ${GEN_DEST_DIR})

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${GEN_DEST_DIR})

add_custom_command(OUTPUT ${PROTO_CPP_SRCS_PATH}
  COMMAND ${Protobuf_PROTOC_EXECUTABLE} --cpp_out=${GEN_DEST_DIR} --proto_path=${CMAKE_CURRENT_SOURCE_DIR} ${PROTO_SRCS_PATH}
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  COMMENT "################## Runnning the protobuf compiler"
  VERBATIM
)

add_custom_target(dummy_target ALL DEPENDS ${PROTO_CPP_SRCS_PATH})

add_executable(testApp test.cpp ${PROTO_CPP_SRCS_PATH})
target_link_libraries(testApp ${Protobuf_LIBRARIES}/libprotobuf.lib)


