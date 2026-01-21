cmake_minimum_required(VERSION 3.16) # 3.16 is required for glfw
project(hello-triangle)

add_executable(hello-triangle)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

# deps library is now available from parent CMakeLists.txt

target_link_libraries(hello-triangle PRIVATE deps)

target_include_directories(hello-triangle
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)

target_sources(hello-triangle
    PRIVATE
        ${SOURCE_FILES}
)
