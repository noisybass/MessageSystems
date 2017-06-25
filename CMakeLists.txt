cmake_minimum_required(VERSION 2.8)
project(MessageSystems)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT messageImpl)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(MessageImpl)