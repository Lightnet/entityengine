#pragma once

#include <string>
#include <vector>

namespace EntityEngine::vulkan
{
    std::vector<std::string> getRequiredVulkanExtensionNames();

    bool isVulkanAvailable();
} // namespace EntityEngine::vulkan
