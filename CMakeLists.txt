set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(ipv4calc CXX)
cmake_minimum_required(VERSION 3.10)
find_package(PkgConfig REQUIRED)
pkg_check_modules(gtkmm REQUIRED IMPORTED_TARGET gtkmm-4.0)

add_executable(ipv4calc main.cpp ipv4calc.cpp ipv4calc.h ipv4utils.cpp)
target_link_libraries(ipv4calc PkgConfig::gtkmm)