#pragma once

#include "../../core/internal-ptr.hpp"
#include "../application.hpp"

namespace EntityEngine
{
  struct VulkanApplication //: public EntityEngine::Application
  {
    VulkanApplication();

    //void update(const float& delta) override;
    //void render() override;

    bool runMainLoop();
    void startApplication();
    
    void update(const float& delta);
    void render();
    void onWindowResized();

  private:
    struct Internal;
    EntityEngine::internal_ptr<Internal> internal;
  };
} // namespace EntityEngine
