#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "logger/logger.hpp"

constexpr std::uint32_t k_window_width = 800;
constexpr std::uint32_t k_window_height = 600;

constexpr const char* k_window_name = "Hello Triangle";

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main(void)
{
    // Init GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    LOG_INFO("Creating window '{}' x:{} y:{}", k_window_name, k_window_width, k_window_height);
    GLFWwindow* window = glfwCreateWindow(k_window_width, k_window_height, k_window_name, NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Init GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Create OpenGL viewport
    glViewport(0, 0, k_window_width, k_window_height);

    // Set window resize callback to support resizing the window
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Main game loop
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    LOG_INFO("Stopping app...");
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
