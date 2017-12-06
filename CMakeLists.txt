# ========================================================================
# $File: CMakeLists.txt $
# $Date: 2017-12-06 16:32:29 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#					Copyright © 2017 by Shen, Jen-Chieh $
# ========================================================================


CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# project settings
PROJECT(libc-jcs)
SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")
SET(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# environment settings
ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

# include directories
INCLUDE_DIRECTORIES(include)

LINK_DIRECTORIES(lib/alib)


# subdir settings
MESSAGE("Porject Directory Tree: ${PROJECT_BINARY_DIR}")
ADD_SUBDIRECTORY(include)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(test)
