#pragma once

namespace EntityEngine
{
    enum class Platform
    {
        mac,
        ios,
        android,
        emscripten,
        windows
    };

    Platform getCurrentPlatform();
} // namespace EntityEngine
