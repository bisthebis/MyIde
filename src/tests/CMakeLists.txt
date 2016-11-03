file(GLOB TEST_FILES . *.cpp)

add_executable (tests ${TEST_FILES})

target_link_libraries (tests libtmp)
target_include_directories (libtmp  PUBLIC "${CMAKE_SOURCE_DIR}/src")
