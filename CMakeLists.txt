cmake_minimum_required(VERSION 3.5.1)
project(Protobuf-Tests)

# Remove Windows-specific hardcoded paths - let CMake find Protobuf automatically
# set(Protobuf_LIBRARIES "c:/Program Files (x86)/protobuf/lib")
# set(Protobuf_INCLUDE_DIR "c:/Program Files (x86)/protobuf/include")


add_subdirectory(app-wo-findprotobuf)
# cmake-protobuf-example directory exists but is empty (no CMakeLists.txt)
# add_subdirectory(cmake-protobuf-example)
add_subdirectory(if-with-target)
add_subdirectory(if-without-findprotobuf)
# Directory 'if' does not exist
# add_subdirectory(if)

