#!/bin/bash
# ========================================================================
# $File: build.sh $
# $Date: 2017-12-04 15:07:57 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#                   Copyright © 2017 by Shen, Jen-Chieh $
# ========================================================================


# Back to project root directory.
cd ..

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
