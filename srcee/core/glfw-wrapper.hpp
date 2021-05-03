
#include <GLFW/glfw3.h>
#include "window-size.hpp"
#include <utility>

namespace EntityEngine::glfw
{
  EntityEngine::WindowSize getInitialWindowSize();

  EntityEngine::WindowSize getWindowSize(GLFWwindow* window);

  GLFWwindow* createWindow(const uint32_t& windowFlags);
} // namespace EntityEngine::glfw

