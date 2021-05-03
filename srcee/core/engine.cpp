#include "engine.hpp"
//#include "../application/application.hpp"
//#include "../application/opengl/opengl-application.hpp"

//#ifndef __EMSCRIPTEN__
#include "../application/vulkan/vulkan-application.hpp"
//#include "../application/vulkan/vulkan-common.hpp"
//#endif

#include "log.hpp"
//#include "sdl-wrapper.hpp"
#include "glfw-wrapper.hpp"
//#include <SDL_image.h>
#include <stdexcept>
#include <string>

using EntityEngine::Engine;

struct Engine::Internal
{
    const std::string classLogTag;

    Internal() : classLogTag("EntityEngine::Engine::") {}

    void run()
    {
      static const std::string logTag{classLogTag + "run"};

      EntityEngine::log(logTag, "Starting engine ...");

      resolveApplication()->startApplication();

      //std::unique_ptr<EntityEngine::VulkanApplication> App;
      //App->startApplication();
      
    }
  
  std::unique_ptr<EntityEngine::VulkanApplication> resolveApplication()
  {
    static const std::string logTag{classLogTag + "resolveApplication"};
    //#ifndef __EMSCRIPTEN__
      //if (EntityEngine::vulkan::isVulkanAvailable())
      //{
        try
        {
          EntityEngine::log(logTag, "Creating Vulkan application ...");
          return std::make_unique<EntityEngine::VulkanApplication>();
        }
        catch (const std::exception& error)
        {
          EntityEngine::log(logTag, "Vulkan application failed to initialize.", error);
          throw std::runtime_error(logTag + " No applications can run in the current environment");
        }
      //}
      
    //#endif
    throw std::runtime_error(logTag + " No applications can run in the current environment");
  }
  
  
  ~Internal()
  {
    static const std::string logTag{"engine::"};

      EntityEngine::log(logTag, "STOP engine ...");
    //SDL_Quit();
  }
};

Engine::Engine() : internal(EntityEngine::make_internal_ptr<Internal>()) {}

void Engine::run()
{
  internal->run();
}
