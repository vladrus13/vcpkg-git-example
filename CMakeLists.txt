cmake_minimum_required(VERSION 3.21)
project(vcpkg_git_example)

set(CMAKE_CXX_STANDARD 14)

add_executable(vcpkg_git_example main.cpp)

find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(vcpkg_git_example PRIVATE unofficial::sqlite3::sqlite3)