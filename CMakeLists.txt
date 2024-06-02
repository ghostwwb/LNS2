project(lns)

cmake_minimum_required (VERSION 3.16)
set (CMAKE_CXX_STANDARD 20)

IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE "RELEASE")
ENDIF()

include_directories("inc" "inc/CBS" "inc/PIBT")
file(GLOB SOURCES "src/*.cpp" "src/CBS/*.cpp" "src/PIBT/*.cpp")

add_executable(lns ${SOURCES})

#set(Boost_INCLUDE_DIR D:/tool/c_dependences/boost_1_80_0)
#set(Boost_LIBRARIES D:/tool/c_dependences/boost_1_80_0/lib64-msvc-14.3)

## Find Boost
#set(BOOST_ROOT D:/tool/c_dependences/boost_1_80_0)
#find_package(boost REQUIRED COMPONENTS program_options system filesystem)
#set(Boost_LIBRARIES D:/tool/c_dependences/boost_1_80_0/lib64-msvc-14.3)
#set(Boost_PROGRAM_OPTIONS_LIBRARY D:/tool/c_dependences/boost_1_80_0/lib64-msvc-14.3/libboost_program_options-vc143-mt-gd-x64-1_80.lib)
#set(Boost_SYSTEM_LIBRARY D:/tool/c_dependences/boost_1_80_0/lib64-msvc-14.3/libboost_system-vc143-mt-gd-x64-1_80.lib)
#set(Boost_FILESYSTEM_LIBRARY D:/tool/c_dependences/boost_1_80_0/lib64-msvc-14.3/libboost_filesystem-vc143-mt-gd-x64-1_80.lib)
#
#if (Boost_FOUND)
#    include_directories( ${Boost_INCLUDE_DIR} )
#    MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
#    MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
#    MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")
#    MESSAGE( STATUS "Boost_FILESYSTEM_LIBRARY = ${Boost_FILESYSTEM_LIBRARY}")
#endif ()


set (BOOST_ROOT D:/tool/c_dependences/boost_1_80_0)
set (Boost_LIBRARY_DIRS D:/tool/c_dependences/boost_1_80_0/lib64-msvc-14.3)
set(Boost_NO_SYSTEM_PATHS ON)
find_package (boost  1.80  REQUIRED COMPONENTS program_options system filesystem)
link_directories (${Boost_LIBRARY_DIRS})
include_directories (${Boost_INCLUDE_DIRS})
message (Boost version: ${Boost_VERSION_STRING})
message (Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS})
message (Boost_LIBRARY_DIRS: ${Boost_LIBRARIES})
message (Boost_LIBRARIES: ${Boost_LIBRARY_DIRS})
message ("Found Boost Libraries:")
foreach (boost_lib IN LISTS Boost_LIBRARIES)
    message (${boost_lib})
    string (REGEX MATCH ".+/.*boost_([^-]+)-.+\.(lib|a)" boost_lib_name ${boost_lib})
    set (boost_lib_name ${CMAKE_MATCH_1})
    set (boost_target Boost::${boost_lib_name})
    if (TARGET ${boost_target})
        message (STATUS "Boost target found: " ${boost_target})
    endif (TARGET ${boost_target})
endforeach (boost_lib)
add_executable (filesystem system program_options driver.cpp)

include_directories( D:/tool/c_dependences/eigen-3.3.8/installdir/include )

#include_directories( ${Boost_INCLUDE_DIR} )
#link_libraries(D:/tool/c_dependences/boost_1_80_0/lib64-msvc-14.3)


#set(Eigen3_INCLUDE_DIR C:/Program Files (x86)/Eigen3/include/eigen3)
# Find Eigen3 for PIBT
find_package (Eigen3 3.3 REQUIRED )

#target_link_libraries(lns D:/tool/c_dependences/boost_1_85_0/lib64-msvc-14.3/boost_filesystem-vc143-mt-gd-x64-1_85.dll D:/tool/c_dependences/boost_1_85_0/lib64-msvc-14.3/boost_program_options-vc143-mt-gd-x64-1_85.dll D:/tool/c_dependences/boost_1_85_0/lib64-msvc-14.3/boost_system-vc143-mt-gd-x64-1_85.dll Eigen3::Eigen)
target_link_libraries(lns D:/tool/c_dependences/boost_1_80_0/lib64-msvc-14.3/boost_filesystem-vc143-mt-gd-x64-1_80.dll D:/tool/c_dependences/boost_1_80_0/lib64-msvc-14.3/boost_program_options-vc143-mt-gd-x64-1_80.dll D:/tool/c_dependences/boost_1_80_0/lib64-msvc-14.3/boost_system-vc143-mt-gd-x64-1_80.dll Eigen3::Eigen)
#target_link_libraries(lns PRIVATE D:/tool/c_dependences/boost_1_85_0/lib64-msvc-14.3/program_options.lib)
#target_link_libraries(lns PRIVATE D:/tool/c_dependences/boost_1_85_0/lib64-msvc-14.3/boost_system-vc143-mt-gd-x64-1_85.dll)
#target_link_libraries(lns PRIVATE D:/tool/c_dependences/boost_1_85_0/lib64-msvc-14.3/boost_filesystem-vc143-mt-gd-x64-1_85.dll)

target_link_libraries(lns Eigen3::Eigen)

