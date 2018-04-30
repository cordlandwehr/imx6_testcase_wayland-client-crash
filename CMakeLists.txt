project(testcase C CXX)

cmake_minimum_required(VERSION 3.4)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)

include(FeatureSummary)
include(GenerateExportHeader)
include(GNUInstallDirs)
include(CTest)

add_definitions(-DQT_QML_DEBUG)

find_package(Qt5 5.6 REQUIRED COMPONENTS
    Core
    Concurrent
    Qml
    Quick
    QuickTest
    WaylandCompositor
)

add_subdirectory(compositor)
add_subdirectory(client)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
