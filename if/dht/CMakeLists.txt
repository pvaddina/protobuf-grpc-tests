cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

message( "########### In dht cmake file and before adding local files: ${SOURCES} and ${CMAKE_CURRENT_SOURCE_DIR}")
set(SOURCES ${SOURCES} PROTOFILES dht.proto OUTPATH ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

set(SOURCES ${SOURCES} dht.proto PARENT_SCOPE)
message( "########### In dht cmake file and after adding local files: ${SOURCES} and ${CMAKE_CURRENT_SOURCE_DIR}")


