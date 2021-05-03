#pragma once

#include "../core/internal-ptr.hpp"

namespace EntityEngine
{
  struct Application
  {
    Application();

    virtual ~Application() = default;

    void startApplication();

    bool runMainLoop();

    virtual void update(const float& delta) = 0;

    virtual void render() = 0;

    virtual void onWindowResized() = 0;

    private:
      struct Internal;
      EntityEngine::internal_ptr<Internal> internal;
    };
} // namespace EntityEngine