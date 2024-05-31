project(lns)

cmake_minimum_required (VERSION 3.16)
set (CMAKE_CXX_STANDARD 20)

IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE "RELEASE")
ENDIF()

include_directories("inc" "inc/CBS" "inc/PIBT")
file(GLOB SOURCES "src/*.cpp" "src/CBS/*.cpp" "src/PIBT/*.cpp")

add_executable(lns ${SOURCES})

#set(Boost_INCLUDE_DIR D:/user_install_tool_software/boost_1_80_0)
#set(Boost_LIBRARIES D:/user_install_tool_software/boost_1_80_0/lib64-msvc-14.3)

# Find Boost
set(BOOST_ROOT D:/user_install_tool_software/boost_1_80_0)
find_package(boost REQUIRED COMPONENTS program_options system filesystem)
set(Boost_LIBRARIES D:/user_install_tool_software/boost_1_80_0/lib64-msvc-14.3)
set(Boost_PROGRAM_OPTIONS_LIBRARY D:/user_install_tool_software/boost_1_80_0/lib64-msvc-14.3/libboost_program_options-vc143-mt-gd-x64-1_80.lib)
set(Boost_SYSTEM_LIBRARY D:/user_install_tool_software/boost_1_80_0/lib64-msvc-14.3/libboost_system-vc143-mt-gd-x64-1_80.lib)
set(Boost_FILESYSTEM_LIBRARY D:/user_install_tool_software/boost_1_80_0/lib64-msvc-14.3/libboost_filesystem-vc143-mt-gd-x64-1_80.lib)

if (Boost_FOUND)
    include_directories( ${Boost_INCLUDE_DIR} )
    MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
    MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")
    MESSAGE( STATUS "Boost_FILESYSTEM_LIBRARY = ${Boost_FILESYSTEM_LIBRARY}")
endif ()

include_directories( D:/user_install_tool_software/c_depandce/Eigen3/include )

#include_directories( ${Boost_INCLUDE_DIR} )
#link_libraries(D:/user_install_tool_software/boost_1_80_0/lib64-msvc-14.3)


#set(Eigen3_INCLUDE_DIR C:/Program Files (x86)/Eigen3/include/eigen3)
# Find Eigen3 for PIBT
find_package (Eigen3 3.3 REQUIRED )

#target_link_libraries(lns D:/user_install_tool_software/boost_1_85_0/lib64-msvc-14.3/boost_filesystem-vc143-mt-gd-x64-1_85.dll D:/user_install_tool_software/boost_1_85_0/lib64-msvc-14.3/boost_program_options-vc143-mt-gd-x64-1_85.dll D:/user_install_tool_software/boost_1_85_0/lib64-msvc-14.3/boost_system-vc143-mt-gd-x64-1_85.dll Eigen3::Eigen)
target_link_libraries(lns D:/user_install_tool_software/boost_1_80_0/lib64-msvc-14.3/boost_filesystem-vc143-mt-gd-x64-1_80.dll D:/user_install_tool_software/boost_1_80_0/lib64-msvc-14.3/boost_program_options-vc143-mt-gd-x64-1_80.dll D:/user_install_tool_software/boost_1_80_0/lib64-msvc-14.3/boost_system-vc143-mt-gd-x64-1_80.dll Eigen3::Eigen)
#target_link_libraries(lns PRIVATE D:/user_install_tool_software/boost_1_85_0/lib64-msvc-14.3/program_options.lib)
#target_link_libraries(lns PRIVATE D:/user_install_tool_software/boost_1_85_0/lib64-msvc-14.3/boost_system-vc143-mt-gd-x64-1_85.dll)
#target_link_libraries(lns PRIVATE D:/user_install_tool_software/boost_1_85_0/lib64-msvc-14.3/boost_filesystem-vc143-mt-gd-x64-1_85.dll)
