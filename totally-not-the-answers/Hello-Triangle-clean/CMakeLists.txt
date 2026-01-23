cmake_minimum_required(VERSION 3.16) # 3.16 is required for glfw
project(hello-triangle-answer-clean)

add_executable(hello-triangle-answer-clean)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

# deps library is now available from parent CMakeLists.txt

target_link_libraries(hello-triangle-answer-clean PRIVATE deps opengl-utils)

target_include_directories(hello-triangle-answer-clean
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../
)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)

target_sources(hello-triangle-answer-clean
    PRIVATE
        ${SOURCE_FILES}
)
