cmake_minimum_required(VERSION 3.16)

project(VideoPlayer)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui Multimedia MultimediaWidgets)

set(PROJECT_SOURCES
  main.cpp
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui
)

qt_add_executable(VideoPlayer ${PROJECT_SOURCES})

target_link_libraries(VideoPlayer PRIVATE
  Qt6::Widgets
  Qt6::Core
  Qt6::Gui
  Qt6::Widgets
  Qt6::Multimedia
  Qt6::MultimediaWidgets
)
