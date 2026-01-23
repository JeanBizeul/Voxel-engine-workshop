#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "logger/logger.hpp"

constexpr std::uint32_t k_window_width = 800;
constexpr std::uint32_t k_window_height = 600;

constexpr const char* k_window_name = "Hello Triangle";

int main(void) {
    // Init OpenGL context
    LOG_DEBUG("Initializing GLFW");
    glfwInit();
    // Set some params for the context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    LOG_DEBUG("Creating GLFW window");
    // Create GLFW window
    GLFWwindow *window = glfwCreateWindow(k_window_width, k_window_height, k_window_name, nullptr, nullptr);
    if (window == nullptr) {
        LOG_FATAL("Failed to create GLFW window");
        glfwTerminate();
        return 84;
    }

    // Init GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LOG_FATAL("Failed to initialize GLAD");
        glfwTerminate();
        return 84;
    }

    // Tell OpenGL viewport size
    glViewport(0, 0, k_window_width, k_window_height);
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
