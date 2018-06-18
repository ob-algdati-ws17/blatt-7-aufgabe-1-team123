cmake_minimum_required(VERSION 2.8.2)

project(googletest-download NONE)

include(ExternalProject)
 ExternalProject_Add(googletest
   GIT_REPOSITORY    https://github.com/google/googletest.git
   GIT_TAG           master
   SOURCE_DIR        "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/googletest-src"
   BINARY_DIR        "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/googletest-build"
   CONFIGURE_COMMAND ""
   BUILD_COMMAND     ""
   INSTALL_COMMAND   ""
   TEST_COMMAND      ""
 )
