#include "platform.hpp"

EntityEngine::Platform EntityEngine::getCurrentPlatform()
{
#if defined(__EMSCRIPTEN__)
    return EntityEngine::Platform::emscripten;
#elif __APPLE__
#include "TargetConditionals.h"
#if TARGET_OS_IPHONE
    return EntityEngine::Platform::ios;
#else
    return EntityEngine::Platform::mac;
#endif
#elif __ANDROID__
    return EntityEngine::Platform::android;
#elif WIN32
    return EntityEngine::Platform::windows;
#else
    return EntityEngine::Platform::windows;
#endif
}
