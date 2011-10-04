cmake_minimum_required(VERSION 2.6)
project(NANOGEAR)

# Set CMake module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/Modules")


# Find Libmagic library
find_package(Libmagic REQUIRED)

# Find and setup Qt4 library
find_package(Qt4 REQUIRED)
set(QT_USE_QTNETWORK 1)
set(QT_DONT_USE_QTGUI 1)
include(${QT_USE_FILE})


# Include the version and print the welcome message
include(NanogerVersion)
message(STATUS "ODIS - Nanogear ${NANOGEAR_MAJOR}.${NANOGEAR_MINOR}.${NANOGEAR_PATCH}")

# Set the pedantic mode for compiler
set(PEDANTIC 1)
include(Pedantic)

# Build the documentation
set(DOCUMENTATION 1)
include(Documentation)


# Project directories
set(NANOGEAR_SOURCE_DIR "Source/")
set(NANOGEAR_DOCUMENTATION_DIR "Documentation/")
set(NANOGEAR_TESTS_DIR "Tests/")
set(NANOGEAR_EXAMPLES_DIR "Examples/")

# Default installation path
set(NANOGEAR_LIBRARY_DIR "lib/Nanogear")
set(NANOGEAR_INCLUDE_DIR "include/Nanogear")

# Source files patterns
set(NANOGEAR_SOURCE_PATTERN "*.c" "*.c++")
set(NANOGEAR_HEADER_PATTERN "*.h" "*.h++")


# Pass the processing to the sub-directories
add_subdirectory(${NANOGEAR_SOURCE_DIR})
add_subdirectory(${NANOGEAR_DOCUMENTATION_DIR})
add_subdirectory(${NANOGEAR_TESTS_DIR})
add_subdirectory(${NANOGEAR_EXAMPLES_DIR})

