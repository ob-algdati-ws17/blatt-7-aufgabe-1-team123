# Install script for directory: /cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/avltree/cmake_install.cmake")
  include("/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/googletest-build/cmake_install.cmake")
  include("/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/test/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/cygdrive/c/Users/Kristin/Documents/00FH/3. Semester/01 Algorithmen und Datenstruckturen/blatt-7-aufgabe-1-team123final/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
