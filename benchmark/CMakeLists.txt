file(GLOB benchmark_files ./bm_*.cpp)
add_executable(appbenchmark  ${benchmark_files})
target_link_libraries(
    appbenchmark
    benchmark_main
    benchmark
  )
