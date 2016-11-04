file(GLOB PROJECT_SOURCE . *.cpp)

add_library (project ${PROJECT_SOURCE})

find_package (Qt5Core REQUIRED)
find_package (Qt5Widgets REQUIRED)

target_link_libraries (project Qt5::Core)
target_include_directories (project PUBLIC ${CMAKE_SOURCE_DIR})

