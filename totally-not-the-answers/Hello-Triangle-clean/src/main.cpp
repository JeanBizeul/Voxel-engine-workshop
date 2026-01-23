#include <iostream>

#include "OpenGLUtils/Window.hpp"

#include "logger/logger.hpp"

constexpr std::uint32_t k_window_width = 800;
constexpr std::uint32_t k_window_height = 600;

constexpr const char* k_window_name = "Hello Triangle";

int main(void)
{
    LOG_INFO("Creating window '{}' x:{} y:{}", k_window_name, k_window_width, k_window_height);
    OpenGLUtils::Window window(k_window_width, k_window_height, k_window_name);

    while (!window.shouldClose()) {
        window.pollEvents();

        window.beginFrame();
        window.beginImGuiFrame();
        window.endFrame();
    }
    LOG_INFO("Stopping app...");
    return 0;
}
