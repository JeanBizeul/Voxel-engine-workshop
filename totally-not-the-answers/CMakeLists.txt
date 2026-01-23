add_library(opengl-utils STATIC)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/OpenGLUtils/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/OpenGLUtils/*.hpp"
)

target_sources(opengl-utils
    PRIVATE
        ${SOURCE_FILES}
)

target_include_directories(opengl-utils
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/logger/
        ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/
        ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/imgui
        ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/imgui/backends
)

target_link_libraries(opengl-utils
    PUBLIC
        imgui
        glfw
        glad
        glm
)

# Add answers folders
add_subdirectory(Hello-Triangle)
