file(GLOB LIBTMP_FILES . *.cpp)
add_library (compiler_processes ${LIBTMP_FILES})

find_package (Qt5Core REQUIRED)

target_link_libraries (compiler_processes Qt5::Core)
target_include_directories (compiler_processes PUBLIC ${CMAKE_SOURCE_DIR})
