# CMake generated Testfile for 
# Source directory: /cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final
# Build directory: /cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(AVLTree "test/testAVLTree" "--gtest_output=xml:report.xml")
subdirs("avltree")
subdirs("googletest-build")
subdirs("test")
