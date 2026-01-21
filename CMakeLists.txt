cmake_minimum_required(VERSION 3.16) # 3.16 is required for glfw
project(deps)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

add_subfolder(vendor)

add_library(deps STATIC)

target_link_libraries(deps
    PRIVATE
        glad
        glfw
        imgui
        glm::glm
        OpenGL::GL
)

target_include_directories(deps
    PUBLIC
        vendor/glad/include
        vendor/glm
        vendor/
        vendor/glfw/include
        vendor/logger
)
