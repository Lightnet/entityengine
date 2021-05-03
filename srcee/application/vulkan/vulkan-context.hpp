#pragma once

#include "../../core/internal-ptr.hpp"

namespace EntityEngine
{
    struct VulkanContext
    {
        VulkanContext();

    private:
        struct Internal;
        EntityEngine::internal_ptr<Internal> internal;
    };
} // namespace ast
