cmake_minimum_required(VERSION 3.6)

project(EosTransactionMemos)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(eos_tracker
               src/eostracker.cpp
               src/eosflare.cpp
               src/utils.cpp
               src/main.cpp)
target_link_libraries(eos_tracker jsoncpp ${CONAN_LIBS})
target_compile_definitions(eos_tracker PRIVATE)
