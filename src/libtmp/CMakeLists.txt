file(GLOB LIBTMP_FILES . *.cpp)
add_library (libtmp ${LIBTMP_FILES})

find_package (Qt5Core REQUIRED)

target_link_libraries (libtmp Qt5::Core)
target_include_directories (libtmp PUBLIC ${CMAKE_SOURCE_DIR})
