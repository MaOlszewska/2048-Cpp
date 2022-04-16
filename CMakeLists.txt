cmake_minimum_required(VERSION 3.7)
project(Your_Project_Name)

set(CMAKE_CXX_STANDARD 11)

set(wxWidgets_ROOT_DIR </usr/include/wx-3.0>)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES main.cpp GameWindow.cpp GameWindow.h Board.cpp Board.h ScoreBoard.cpp ScoreBoard.h)
add_executable(FirstC ${SOURCE_FILES})

target_link_libraries(FirstC ${wxWidgets_LIBRARIES})