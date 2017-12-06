# ========================================================================
# $File: CMakeLists.txt $
# $Date: 2017-12-06 16:42:12 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#					Copyright © 2017 by Shen, Jen-Chieh $
# ========================================================================


# project version
PROJECT(libc-jcs-test)

# set public header list
SET(${PROJECT_NAME}_headers "")
SET(${PROJECT_NAME}_sources main.cpp)

# create binaries
ADD_EXECUTABLE(${PROJECT_NAME} ${${PROJECT_NAME}_headers} ${${PROJECT_NAME}_sources})

# link
TARGET_LINK_LIBRARIES(${PROJECT_NAME} dll1)

# configure install
INSTALL(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib/static)
