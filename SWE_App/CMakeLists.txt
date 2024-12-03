cmake_minimum_required(VERSION 3.10)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(wxWidgets REQUIRED COMPONENTS core)

include(${wxWidgets_USE_FILE})

file(GLOB_RECURSE SOURCES "./*.cpp" "./*.h")

include_directories(include)

add_executable(Calculator ${SOURCES})

target_link_libraries(Calculator PRIVATE ${wxWidgets_LIBRARIES})
