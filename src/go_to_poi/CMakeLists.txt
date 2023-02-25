cmake_minimum_required(VERSION 3.0.2)
project(go_to_poi)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  trajectory_msgs
  message_generation
)

## Generate messages in the 'msg' folder
add_message_files(
    FILES
    poi.msg
)

## Generate added messages and services with any dependencies listed here
generate_messages(
    DEPENDENCIES
    geometry_msgs#   trajectory_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES go_to_poi
   CATKIN_DEPENDS geometry_msgs roscpp rospy trajectory_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/go_to_poi.cpp
# )

# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(go_to_poi
        src/go_to_poi.cpp
)
target_link_libraries(go_to_poi
        ${catkin_LIBRARIES}
)
add_executable(talker_poi
        src/talker_poi.cpp
)
target_link_libraries(talker_poi
        ${catkin_LIBRARIES}
)
add_executable(talker_pose
        src/talker_pose.cpp
)
target_link_libraries(talker_pose
        ${catkin_LIBRARIES}
)