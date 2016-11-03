file(GLOB MAIN_FILES . *.cpp)
add_executable (ide ${MAIN_FILES} )

find_package (Qt5Core REQUIRED)

target_link_libraries (ide Qt5::Core)
target_link_libraries (ide libtmp)

add_subdirectory(libtmp)
add_subdirectory(tests)
