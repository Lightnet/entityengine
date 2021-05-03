


#include "platform.hpp"
#include "glfw-wrapper.hpp"
#include "log.hpp"

namespace
{
  bool shouldDisplayFullScreen()
  {
    switch (EntityEngine::getCurrentPlatform())
    {
      case EntityEngine::Platform::ios:
      case EntityEngine::Platform::android:
        return true;

      default:
        return false;
    }
  }
}

EntityEngine::WindowSize EntityEngine::glfw::getInitialWindowSize()
{
  const EntityEngine::Platform platform{EntityEngine::getCurrentPlatform()};

  // For other platforms we'll just show a fixed size window.
  return EntityEngine::WindowSize{640, 480};
}

EntityEngine::WindowSize EntityEngine::glfw::getWindowSize(GLFWwindow* window){
  int width{0};
  int height{0};
  glfwGetWindowSize(window, &width, &height);
  return EntityEngine::WindowSize{static_cast<uint32_t>(width), static_cast<uint32_t>(height)};  
}

GLFWwindow* EntityEngine::glfw::createWindow(const uint32_t& windowFlags)
{
  static const std::string logTag{"glfw-wrapper"};
  
  EntityEngine::WindowSize windowSize{EntityEngine::glfw::getInitialWindowSize()};
  if (!glfwInit()){
    EntityEngine::log(logTag, "Error init ...");
  }
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  GLFWwindow* window{glfwCreateWindow(
    windowSize.width,
    windowSize.height,
    "glfw3 vulkan",
    NULL,
    NULL)};

    //if (::shouldDisplayFullScreen())
    //{
      //SDL_SetWindowFullscreen(window, SDL_TRUE);
    //}

  return window;
}