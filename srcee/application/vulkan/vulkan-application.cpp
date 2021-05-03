#include "vulkan-application.hpp"
#include "../../core/graphics-wrapper.hpp"
//#include "../../core/sdl-wrapper.hpp"
#include "../../core/glfw-wrapper.hpp"
#include "vulkan-context.hpp"
#include "../../core/log.hpp"

using EntityEngine::VulkanApplication;

struct VulkanApplication::Internal
{
  const EntityEngine::VulkanContext context;
  GLFWwindow* window;
                
  Internal() : context(EntityEngine::VulkanContext()),
                window(EntityEngine::glfw::createWindow(GLFW_RESIZABLE)) {};

  void update(const float& delta) {}

  void render() {}

  bool runMainLoop(){};

  void startApplication() {}

  ~Internal()
  {
    static const std::string logTag{"VULKAN CLOSE"};
    EntityEngine::log(logTag, "stopping engine ...");
    
    if (window)
    {
      glfwDestroyWindow(window);
      glfwTerminate();
    }
  }
};

VulkanApplication::VulkanApplication() : internal(EntityEngine::make_internal_ptr<Internal>()) {}

bool VulkanApplication::runMainLoop()
{  

  render();
  return true;
}

void VulkanApplication::startApplication()
{
  static const std::string logTag{"VULKANApplication"};
  EntityEngine::log(logTag, "WHILE ...");
  //internal->window = EntityEngine::glfw::createWindow(GLFW_RESIZABLE);
  //internal->window 
  
  //if (!glfwInit()){EntityEngine::log(logTag, "ERROR ...");}
  //glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  //GLFWwindow* window = glfwCreateWindow(
  //internal->window = glfwCreateWindow(
    //800, 600, "glfw3 vulkan", NULL, NULL);
  //GLFWwindow* window = EntityEngine::glfw::createWindow(GLFW_RESIZABLE);
  
  //while (runMainLoop())
  while (!glfwWindowShouldClose(internal->window))
  //while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();

    //render();
    //EntityEngine::log(logTag, "LOOP? ...");
  }

  glfwDestroyWindow(internal->window);
  //glfwDestroyWindow(window);
  glfwTerminate();
}

void VulkanApplication::update(const float& delta)
{  
  //internal->update(delta);
  //static const std::string logTag{"VULKAN"};
  //EntityEngine::log(logTag, "update ...");
}

void VulkanApplication::render()
{
  //internal->render();
  static const std::string logTag{"VULKAN"};
  EntityEngine::log(logTag, " rendering ...");
}
