#pragma once

#include "glfw-window.hpp"

using EntityEngine::GLFWWindow;

struct GLFWWindow::Internal
{
  GLFWwindow* window;

  Internal(const uint32_t& windowFlags) : window(EntityEngine::glfw::createWindow(windowFlags)) {}

  ~Internal()
  {
    glfwDestroyWindow(window);
    glfwTerminate();
  }
};

GLFWWindow::GLFWWindow(const uint32_t& windowFlags) : internal(EntityEngine::make_internal_ptr<Internal>(windowFlags)) {}

GLFWwindow* GLFWWindow::getWindow() const
{
  return internal->window;
}