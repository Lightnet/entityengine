#include "vulkan-common.hpp"
#include "../../core/graphics-wrapper.hpp"
#include "../../core/log.hpp"
//#include "../../core/sdl-wrapper.hpp"
#include "../../core/glfw-wrapper.hpp"
#include <set>

std::vector<std::string> EntityEngine::vulkan::getRequiredVulkanExtensionNames()
{
    uint32_t extensionCount = 0;
    //SDL_Vulkan_GetInstanceExtensions(nullptr, &extensionCount, nullptr);
    const char** extensions = glfwGetRequiredInstanceExtensions(&extensionCount);

    auto extensionNames{std::make_unique<const char**>(new const char*[extensionCount])};
    //SetupVulkan(extensionNames, extensionCount);
    //SDL_Vulkan_GetInstanceExtensions(nullptr, &extensionCount, *extensionNames);
    std::vector<std::string> result(*extensionNames, *extensionNames + extensionCount);

    return result;
}

bool EntityEngine::vulkan::isVulkanAvailable()
{
    static const std::string logTag{"EntityEngine::vulkan::isVulkanAvailable"};

    // Check if SDL itself can load Vulkan.
    /*
    if (SDL_Vulkan_LoadLibrary(nullptr) != 0)
    {
        EntityEngine::log(logTag, "No SDL Vulkan support found.");
        return false;
    }
    */

    // Determine what Vulkan extensions are required by SDL to be able to run Vulkan then pump
    // them into a 'set' so we can evaluate them easily.
    std::vector<std::string> requiredExtensionNamesSource{
        EntityEngine::vulkan::getRequiredVulkanExtensionNames()};

    std::set<std::string> requiredExtensionNames(
        requiredExtensionNamesSource.begin(),
        requiredExtensionNamesSource.end());

    // There should always be required extensions so we should never get 0.
    if (requiredExtensionNames.empty())
    {
        EntityEngine::log(logTag, "No Vulkan required extensions found.");
        return false;
    }

    // Iterate all the available Vulkan extensions on the current device, draining
    // each one from the required extensions set along the way.
    for (auto const& availableExtension : vk::enumerateInstanceExtensionProperties())
    {
        requiredExtensionNames.erase(availableExtension.extensionName);
    }

    // If our required extensions set isn't empty it means that one or more of
    // them were not found in the available extensions, so we don't have what
    // we require to successfully create a Vulkan instance.
    if (!requiredExtensionNames.empty())
    {
        EntityEngine::log(logTag, "Missing one or more required Vulkan extensions.");
        return false;
    }

    EntityEngine::log(logTag, "Vulkan is available.");
    return true;
}
