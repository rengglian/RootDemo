# CMakeLists.txt for event package. It creates a library with dictionary and a main program
cmake_minimum_required(VERSION 3.15.1)
set(TARGET_NAME RootDemo)
set(TARGET_VERSION 0.1)
project(${TARGET_NAME} VERSION ${TARGET_VERSION})


set(CMAKE_CXX_STANDARD 17)
# You need to tell CMake where to find the ROOT installation. This can be done in a number of ways:
#   - ROOT built with classic configure/make use the provided $ROOTSYS/etc/cmake/FindROOT.cmake
#   - ROOT built with CMake. Add in CMAKE_PREFIX_PATH the installation prefix for ROOT
#list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED COMPONENTS RIO Net)

add_executable(${TARGET_NAME}   src/main.cpp)

target_include_directories(${TARGET_NAME} PRIVATE ${ROOT_USE_FILE})

#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
#include(${ROOT_USE_FILE})

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#ROOT_GENERATE_DICTIONARY(G__Event Event.h LINKDEF EventLinkDef.h)

#---Create a shared library with geneated dictionary
#add_library(Event SHARED Event.cxx G__Event.cxx)
#target_link_libraries(Event ${ROOT_LIBRARIES})

target_link_libraries(${TARGET_NAME} ${ROOT_LIBRARIES})

#---Create  a main program using the library

#target_link_libraries(Main Event)