cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(dummy-interface-with-static-target)


function(list_print liItems)
    message(STATUS "#############################################")
  foreach(f ${${liItems}})
    message(STATUS ${f})
  endforeach()
    message(STATUS "#############################################\n")
endfunction()


function(concat_path iLiItems oLiItems cVal) 
  foreach(pfile ${${iLiItems}})
    string(CONCAT l ${${cVal}} ${pfile})
    #message(STATUS ${pfile} " ################################### " ${l})
    set(oLiItems ${oLiItems} ${l} PARENT_SCOPE)
  endforeach()
endfunction()


set(Protobuf_PROTOC_EXECUTABLE "C:/Users/praka/workspace/cpp/third_party/install/bin/protoc.exe")
set(Protobuf_LIBRARIES "C:/Users/praka/workspace/cpp/third_party/install/lib")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

set(PROTO_SRCS base.proto dht.proto)


foreach(pfile ${PROTO_SRCS}) 
  string(REPLACE ".proto" ".pb" fname ${pfile})
  string(CONCAT cc ${fname} ".cc")
  string(CONCAT h ${fname} ".h")
  set(PROTO_CPP_SRCS ${PROTO_CPP_SRCS} ${cc} ${h})
endforeach()


#set(PROTO_SRCS_PATH ${PROTO_SRCS})
#set(PROTO_CPP_SRCS_PATH ${PROTO_CPP_SRCS})
string(CONCAT path_prefix ${CMAKE_CURRENT_SOURCE_DIR} "/")
string(CONCAT gen_path_prefix ${CMAKE_CURRENT_SOURCE_DIR} "/gen/")
concat_path(PROTO_SRCS PROTO_SRCS_PATH path_prefix)
concat_path(PROTO_CPP_SRCS PROTO_CPP_SRCS_PATH gen_path_prefix)
#list_print(PROTO_SRCS_PATH)
#list_print(PROTO_CPP_SRCS_PATH)


set (GEN_DEST_DIR ${CMAKE_CURRENT_BINARY_DIR}/gen)
file(MAKE_DIRECTORY ${GEN_DEST_DIR})


add_custom_command(OUTPUT ${PROTO_CPP_SRCS_PATH}
  COMMAND ${Protobuf_PROTOC_EXECUTABLE} --cpp_out=${GEN_DEST_DIR} --proto_path=${CMAKE_CURRENT_SOURCE_DIR} ${PROTO_SRCS_PATH}
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  COMMENT "################## Runnning the protobuf compiler"
  VERBATIM
)

add_custom_target(dummy_target ALL DEPENDS ${PROTO_CPP_SRCS_PATH})

add_executable(testApp test.cpp ${PROTO_CPP_SRCS_PATH})
target_link_libraries(testApp ${Protobuf_LIBRARIES}/libprotobuf.lib)


