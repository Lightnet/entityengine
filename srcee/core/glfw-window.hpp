#pragma once

#include "internal-ptr.hpp"
#include "glfw-wrapper.hpp"

namespace EntityEngine
{
  struct GLFWWindow
  {
    GLFWWindow(const uint32_t& windowFlags);

    GLFWwindow* getWindow() const;

  private:
    struct Internal;
    EntityEngine::internal_ptr<Internal> internal;
  };
}