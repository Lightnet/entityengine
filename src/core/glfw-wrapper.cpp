//#include "platform.hpp"
#include "glfw-wrapper.hpp"
#include "log.hpp"

namespace
{
  /*
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
  */
}

GLFWwindow* EntityEngine::glfw::createWindow(const uint32_t& windowFlags)
{
  static const std::string logTag{"glfw-wrapper"};
  
  //EntityEngine::WindowSize windowSize{EntityEngine::glfw::getInitialWindowSize()};
  if (!glfwInit()){
    EntityEngine::log(logTag, "Error init ...\n");
  }else{
    EntityEngine::log(logTag, "glfwInit\n");
  }
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  GLFWwindow* window{glfwCreateWindow(800,480,"glfw3 vulkan",NULL,NULL)};
  if (!glfwVulkanSupported()){
    //printf("GLFW: Vulkan Not Supported\n");
    EntityEngine::log(logTag, "GLFW: Vulkan Not Supported\n");
  }else{
    EntityEngine::log(logTag, "GLFW: Vulkan Supported!\n");
  }
  //uint32_t extensionCount = 0;
  //const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&extensionCount);
  //printf("extensionCount>>: %i\n", extensionCount);
  //if (::shouldDisplayFullScreen())
  //{
    //SDL_SetWindowFullscreen(window, SDL_TRUE);
  //}
  return window;
}