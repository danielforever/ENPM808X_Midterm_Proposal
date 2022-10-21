include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})
add_library(perception perception.cpp ${CMAKE_SOURCE_DIR}/include/perception.hpp)
target_include_directories(perception PUBLIC ${CMAKE_SOURCE_DIR}/include ${OpenCV_LIBS})
find_package( OpenCV REQUIRED)


