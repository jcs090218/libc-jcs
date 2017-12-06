@echo off
:: ========================================================================
:: $File: build.bat $
:: $Date: 2017-12-04 15:07:42 $
:: $Revision: $
:: $Creator: Jen-Chieh Shen $
:: $Notice: See LICENSE.txt for modification and distribution information
::                   Copyright © 2017 by Shen, Jen-Chieh $
:: ========================================================================


:: Build test program.
echo.
echo.

:: clean before build.
make realclean

echo.
echo.

cd test
:: Build `main.c'
make build

echo.
:: Build `client_main.c'
make buildclient

echo.
:: Build `server_main.c'
make buildserver
cd ..

echo.
echo.
::make build
echo.
echo.

:: Build static library.
echo.
echo.
make libc-jcs.a
echo.
echo.

:: Build dynamic library.
echo.
echo.
make libc-jcs.so
echo.
echo.