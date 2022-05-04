cmake_minimum_required(VERSION 3.21)
project(vcpkg_git_example)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 14)
set(VCPKG_NAME vcpkggitexample)

add_library(vcpkggitexample src/example.cpp include/example.h)
add_library(Vcpkggitexample::vcpkggitexample ALIAS vcpkggitexample)

configure_package_config_file(cmake/config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/${VCPKG_NAME}-config.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/${VCPKG_NAME}
        NO_SET_AND_CHECK_MACRO)
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/${VCPKG_NAME}-config-version.cmake
        VERSION 1.0.0
        COMPATIBILITY SameMajorVersion)
install(
        FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${VCPKG_NAME}-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${VCPKG_NAME}-config-version.cmake
        DESTINATION
        ${CMAKE_INSTALL_DATADIR}/${VCPKG_NAME})

install(TARGETS ${VCPKG_NAME} EXPORT ${VCPKG_NAME}-targets)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT ${VCPKG_NAME}-targets
        NAMESPACE ${VCPKG_NAME}::
        DESTINATION ${CMAKE_INSTALL_DATADIR}/${VCPKG_NAME})

add_executable(vcpkg_git_example main.cpp)

find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(vcpkg_git_example PRIVATE unofficial::sqlite3::sqlite3)