cmake_minimum_required(VERSION 3.16)
project(nesnes C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0)
pkg_check_modules(ADWAITA REQUIRED libadwaita-1)

add_executable(nesnes main.c)

target_include_directories(nesnes PRIVATE
    ${GLIB_INCLUDE_DIRS}
    ${ADWAITA_INCLUDE_DIRS}
)

target_link_libraries(nesnes PRIVATE
    ${GLIB_LIBRARIES}
    ${ADWAITA_LIBRARIES}
)

target_compile_options(nesnes PRIVATE
    ${GLIB_CFLAGS_OTHER}
    ${ADWAITA_CFLAGS_OTHER}
)
