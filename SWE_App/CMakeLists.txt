cmake_minimum_required(VERSION 3.10)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(wxWidgets CONFIG REQUIRED)

if(WIN32)
    add_executable(Calculator WIN32 App.cpp ButtonFactory.cpp Calculator.cpp CalculatorProcessor.cpp)
else()
    add_executable(Calculator App.cpp ButtonFactory.cpp Calculator.cpp CalculatorProcessor.cpp)
endif()

target_link_libraries(Calculator PRIVATE wx::core wx::base wx::net)
