file(GLOB TEST_FILES . *.cpp)

add_executable (tests ${TEST_FILES})

target_link_libraries (tests compiler_processes)
target_include_directories (compiler_processes  PUBLIC "${CMAKE_SOURCE_DIR}/src")
