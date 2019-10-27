cmake_minimum_required(VERSION 3.1)

project(wxwidgets_basic)

## Compile as C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Compile with the highest warning level
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

## System dependencies
find_package(wxWidgets REQUIRED COMPONENTS net core base)

## Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

## Specify additional locations of header files
include_directories(${CMAKE_SOURCE_DIR}/include)

## Declare a C++ executable
add_executable(sample_application src/sample_application.cpp src/main_window.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(sample_application ${wxWidgets_LIBRARIES})
