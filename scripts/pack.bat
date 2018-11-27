@echo off
:: ========================================================================
:: $File: pack.bat $
:: $Date: 2017-12-22 12:46:09 $
:: $Revision: $
:: $Creator: Jen-Chieh Shen $
:: $Notice: See LICENSE.txt for modification and distribution information
::                   Copyright © 2017 by Shen, Jen-Chieh $
:: ========================================================================


:: Back to project root directory.
cd ..


:: Build tar file.
echo.
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

echo "Copy license file.."
cp "./LICENSE" "./build/%PROJECT_NAME%"

echo "Copy readme file.."
cp "./README" "./build/%PROJECT_NAME%"

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
