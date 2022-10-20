
add_executable(shell-app main.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS}
)
add_library(perception perception.cpp ${CMAKE_SOURCE_DIR}/include/perception.hpp)


target_include_directories(perception PUBLIC ${CMAKE_SOURCE_DIR}/include)



