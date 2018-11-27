#!/bin/bash
# ========================================================================
# $File: pack.sh $
# $Date: 2017-12-22 12:46:42 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#                   Copyright © 2017 by Shen, Jen-Chieh $
# ========================================================================


# Back to project root directory.
cd ..


# Include all JCSSH files.
DIR="${BASH_SOURCE%/*}"
if [[ ! -d "$DIR" ]]; then DIR="$PWD"; fi
. "$DIR/scripts/JCSSH/JCSSH.sh"


# Build tar file.
jcs_progress_bar_5p 10 "Start building zip file.."

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

jcs_progress_bar_5p 50 "Copying library files..."


jcs_progress_bar_5p 70 "Compressing folder...."
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
