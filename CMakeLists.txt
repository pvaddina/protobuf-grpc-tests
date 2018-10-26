cmake_minimum_required(VERSION 3.5.1)
project(Protobuf-Tests)

set(Protobuf_LIBRARIES "c:/Program Files (x86)/protobuf/lib")
set(Protobuf_INCLUDE_DIR "c:/Program Files (x86)/protobuf/include")


add_subdirectory(app-wo-findprotobuf)
add_subdirectory(cmake-protobuf-example)
add_subdirectory(if-with-target)
add_subdirectory(if-without-protobuf)
add_subdirectory(if)

