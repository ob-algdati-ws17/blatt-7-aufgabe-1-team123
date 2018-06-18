# Install script for directory: /cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/googletest-src/googletest

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/googletest-build/googlemock/gtest/libgtestd.a")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/googletest-build/googlemock/gtest/libgtest_maind.a")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/googletest-src/googletest/include/gtest")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES
    "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/gtest.pc"
    "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/gtest_main.pc"
    )
endif()

