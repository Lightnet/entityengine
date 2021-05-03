#pragma once

#include "internal-ptr.hpp"

namespace EntityEngine
{
  struct Engine
  {
    Engine();

    void run();

  private:
    struct Internal;
    EntityEngine::internal_ptr<Internal> internal;
  };
} // namespace ast