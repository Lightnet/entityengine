#pragma once

#include "internal-ptr.hpp"

#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
namespace EntityEngine::glfw
{
  //EntityEngine::WindowSize getInitialWindowSize();

  //EntityEngine::WindowSize getWindowSize(GLFWwindow* window);

  GLFWwindow* createWindow(const uint32_t& windowFlags);
} // namespace EntityEngine::glfw
