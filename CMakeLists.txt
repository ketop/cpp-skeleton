cmake_minimum_required(VERSION 3.11)
project(skeleton)

set(NLOHMANNJSON_INCLUDE  ${CMAKE_CURRENT_LIST_DIR}/third_party/nlohmann_json/include)
set(SPDLOG_INCLUDE        ${CMAKE_CURRENT_LIST_DIR}/third_party/spdlog/include)
set(SPDLOG_LIB            ${CMAKE_CURRENT_LIST_DIR}/third_party/spdlog/lib)
set(BENCHMARK_INCLUDE     ${CMAKE_CURRENT_LIST_DIR}/third_party/benchmark/include)
set(BENCHMARK_LIB         ${CMAKE_CURRENT_LIST_DIR}/third_party/benchmark/lib)
set(GOOGLETEST_INCLUDE    ${CMAKE_CURRENT_LIST_DIR}/third_party/googletest/include)
set(GOOGLETEST_LIB        ${CMAKE_CURRENT_LIST_DIR}/third_party/googletest/lib)
link_directories(
    ${GOOGLETEST_LIB}
    ${BENCHMARK_LIB}
    ${SPDLOG_LIB}
  )
set(CMAKE_CXX_STANDARD  14)
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_CURRENT_LIST_DIR}/bin)
set(LIBRARY_OUTPUT_PATH     ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)
file(GLOB app_src_files  ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
include_directories(
    include
    ${GOOGLETEST_INCLUDE}
    ${BENCHMARK_INCLUDE}
    ${SPDLOG_INCLUDE}
    ${NLOHMANNJSON_INCLUDE}
  )

add_executable(app ${app_src_files})
add_subdirectory(benchmark)
add_subdirectory(test)
find_program(MEMORYCHECK_COMMAND NAMES valgrind)
set(MEMORYCHECK_COMMAND_OPTIONS  "--trace-children=yes --leak-check=full")
include(CTest)
enable_testing()
add_test(
    NAME  app_test
    COMMAND $<TARGET_FILE:apptest>
  )




