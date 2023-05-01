file(GLOB test_files  ./test_*.cpp)
add_executable(apptest "")
target_sources(apptest
    PRIVATE
    ${test_files}
  )
target_link_libraries(apptest
    PRIVATE
    gtest_main
    gtest
  )

