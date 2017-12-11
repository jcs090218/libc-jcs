#!/bin/bash
# ========================================================================
# $File: build.sh $
# $Date: 2017-12-04 15:07:57 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#                   Copyright © 2017 by Shen, Jen-Chieh $
# ========================================================================


# clean before build.
make realclean

# Build test program.
cd test
echo
make build

echo
make buildclient

echo
make buildserver
cd ..


echo
echo
# Build static library.
make libc-jcs.a

echo
echo
# Build dynamic library.
make libc-jcs.so


# Build tar file.
cho.
echo "Start building the .zip file."
echo.

SET PROJECT_NAME=lib-jcs
SET ZIP_EXT=.tar.gz
SET ALIB_NAME=libc-jcs.a
SET SOLIB_NAME=libc-jcs.so

mkdir "build/%PROJECT_NAME%"
mkdir "build/%PROJECT_NAME%/include"
mkdir "build/%PROJECT_NAME%/lib"

echo "Copying library files..."
cp "./build/alib/%ALIB_NAME%" "./build/%PROJECT_NAME%/lib"
cp "./build/solib/%SOLIB_NAME%" "./build/%PROJECT_NAME%/lib"
echo "Done copying library files."

echo "Copying header file..."
cp "./libc_jcs.h" "./build/%PROJECT_NAME%/include/"
echo "Done copying header file."

echo "Copying include files..."
mkdir "./build/%PROJECT_NAME%/include/include"
cp -r "./include" "./build/%PROJECT_NAME%/include"
echo "Done copying include files."


cd build
echo "Compressing folder..."
tar -czvf "./%PROJECT_NAME%%ZIP_EXT%" "%PROJECT_NAME%"
echo "Target files compressed."

echo "Remove temporary files..."
rm -r "./%PROJECT_NAME%"
echo "Temporary files removed."
cd ..

echo.
echo "Done build .zip file."
echo.
