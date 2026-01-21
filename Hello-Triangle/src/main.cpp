#include <iostream>

#include "glad/glad.h"
#include "logger/logger.hpp"

int main(void) {
    LOG_DEBUG("Hello Triangle!");
    LOG_INFO("This is an info message.");
    LOG_WARNING("This is a warning message.");
    LOG_ERROR("This is an error message.");
    LOG_FATAL("This is a fatal message.");
    return 0;
}