include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})
add_library(perception human_tracker.cpp camera.cpp detector.cpp tracker.cpp person.cpp ${CMAKE_SOURCE_DIR}/include/detector.hpp ${CMAKE_SOURCE_DIR}/include/camera.hpp ${CMAKE_SOURCE_DIR}/include/tracker.hpp ${CMAKE_SOURCE_DIR}/include/human_tracker.hpp ${CMAKE_SOURCE_DIR}/include/person.hpp)
target_include_directories(perception PUBLIC ${CMAKE_SOURCE_DIR}/include ${OpenCV_LIBS})
find_package( OpenCV REQUIRED)


