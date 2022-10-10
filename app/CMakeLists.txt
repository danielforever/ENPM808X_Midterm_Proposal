add_executable(shell-app main.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)


add_library(perception perception.cpp)
