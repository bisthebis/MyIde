file(GLOB MAIN_SOURCE_FILES . *.cpp)
file(GLOB UIs . *.ui)

add_executable (ide ${MAIN_SOURCE_FILES} ${UIs})

find_package (Qt5Core REQUIRED)
find_package (Qt5Gui REQUIRED)
find_package (Qt5Widgets REQUIRED)

target_link_libraries (ide Qt5::Core)
target_link_libraries (ide Qt5::Gui)
target_link_libraries (ide Qt5::Widgets)
target_link_libraries (ide compiler_processes)


