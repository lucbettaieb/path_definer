cmake_minimum_required(VERSION 2.8.3)
project(path_definer)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
)
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES controller
#  CATKIN_DEPENDS roscpp geometry_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(path_definer src/path_definer.cpp)

target_link_libraries(path_definer
   ${catkin_LIBRARIES}
)