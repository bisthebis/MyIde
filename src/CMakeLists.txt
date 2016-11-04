file(GLOB MAIN_FILES . *.cpp)
add_executable (ide ${MAIN_FILES} )

find_package (Qt5Core REQUIRED)
find_package (Qt5Gui REQUIRED)
find_package (Qt5Widgets REQUIRED)

target_link_libraries (ide Qt5::Core)
target_link_libraries (ide Qt5::Gui)
target_link_libraries (ide Qt5::Widgets)
target_link_libraries (ide compiler_processes)

add_subdirectory(compiler_processes)
add_subdirectory(tests)
