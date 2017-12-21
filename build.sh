#!/bin/bash
# ========================================================================
# $File: build.sh $
# $Date: 2017-12-04 15:07:57 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#                   Copyright © 2017 by Shen, Jen-Chieh $
# ========================================================================


# Include all JCSSH files.
DIR="${BASH_SOURCE%/*}"
if [[ ! -d "$DIR" ]]; then DIR="$PWD"; fi
. "$DIR/scripts/JCSSH/JCSSH.sh"


# clean before build.
jcs_progress_bar_5p 0 "Clean compile status.."
make realclean

# Build test program.
jcs_progress_bar_5p 10 "Building executable files.."
cd test
echo
make build

echo
make buildclient

echo
make buildserver
cd ..


jcs_progress_bar_5p 30 "Building static libraries.."
echo
echo
# Build static library.
make libc-jcs.a

jcs_progress_bar_5p 40 "Building dynamic libraries.."
echo
echo
# Build dynamic library.
make libc-jcs.so


# Build tar file.
jcs_progress_bar_5p 50 "Start building zip file.."

echo
echo "Start building the .zip file."
echo

PROJECT_NAME=lib-jcs
ZIP_EXT=.tar.gz
ALIB_NAME=libc-jcs.a
SOLIB_NAME=libc-jcs.so

mkdir "build/$PROJECT_NAME"
mkdir "build/$PROJECT_NAME/include"
mkdir "build/$PROJECT_NAME/lib"

echo "Copying library files..."
cp "./build/alib/$ALIB_NAME" "./build/$PROJECT_NAME/lib"
cp "./build/solib/$SOLIB_NAME" "./build/$PROJECT_NAME/lib"
echo "Done copying library files."

echo "Copying header file..."
cp "./libc_jcs.h" "./build/$PROJECT_NAME/include/"
echo "Done copying header file."

echo "Copying include files..."
mkdir "./build/$PROJECT_NAME/include/include"
cp -r "./include" "./build/$PROJECT_NAME/include"
echo "Done copying include files."

echo "Copy license file.."
cp "./LICENSE" "./build/$PROJECT_NAME"

echo "Copy readme file.."
cp "./README" "./build/$PROJECT_NAME"

jcs_progress_bar_5p 70 "Copying library files..."


jcs_progress_bar_5p 80 "Compressing folder...."
cd build
echo "Compressing folder..."
tar -czvf "./$PROJECT_NAME$ZIP_EXT" "$PROJECT_NAME"
echo "Target files compressed."

jcs_progress_bar_5p 90 "Remove temporary files..."
echo "Remove temporary files..."
rm -r "./$PROJECT_NAME"
echo "Temporary files removed."
cd ..

jcs_progress_bar_5p 100 "Done."
echo
echo "Done build .zip file."
echo
