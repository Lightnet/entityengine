
//#include "../core/sdl-wrapper.hpp"
#include "../core/glfw-wrapper.hpp"
#include "application.hpp"
#include "../core/log.hpp"

#include <stdexcept>
#include <iostream>

using namespace std;

using EntityEngine::Application;

namespace
{
#ifdef EMSCRIPTEN
  void emscriptenMainLoop(EntityEngine::Application* application)
  {
    application->runMainLoop();
  }
#endif
}

struct Application::Internal
{
  const double performanceFrequency;
  double  currentTime;
  double  previousTime;
  //error on internal if not set
  Internal() : performanceFrequency(static_cast<double>(1)),
                currentTime(),
                previousTime(currentTime) {}

  double timeStep()
  {
      previousTime = currentTime;
      currentTime = glfwGetTime();

      double elapsed{(currentTime - previousTime) * 1000.0};
      return (elapsed / performanceFrequency) * 0.001;
  }
  
};

bool Application::runMainLoop()
{
  //glfwPollEvents();

  //static const std::string logTag{"runMainLoop"};
  //EntityEngine::log(logTag, "LOOP? ...");

  // Perform our updating for this frame.
  //update(internal->timeStep());
  // Perform our rendering for this frame.
  //render();

  return true;
}

void Application::startApplication()
{
#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop_arg((em_arg_callback_func)::emscriptenMainLoop, this, 0, 1);
#else
  static const std::string logTag{"startApplication"};

  EntityEngine::log(logTag, "HELLO? ...");
  //while (this->runMainLoop())
  //using EntityEngine::Application;
  //while (EntityEngine::Application::runMainLoop())
  //while (true)
  while (runMainLoop())
  {
    //Application::runMainLoop();

    // Perform our updating for this frame.
    //update(internal->timeStep());
    // Perform our rendering for this frame.
    //this->render();
    

    // Just waiting for the main loop to end.
    //glfwPollEvents();

    static const std::string logTag{"runMainLoop"};
    EntityEngine::log(logTag, "LOOP? ...");
    // https://docs.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-160
    // https://isocpp.org/wiki/faq/exceptions
    try 
    {
      render();
    }catch(std::exception& e){
      cerr << e.what() << endl;
      //cout << "Special exception\n";
    }
  }
#endif
}

Application::Application() : internal(EntityEngine::make_internal_ptr<Internal>()) {}