#================================================
# CMAKE BUILD
# WINDOW BUILD CURRENTLY
#================================================
cmake_minimum_required(VERSION 3.20) # FetchContent is available in 3.11+
#message("CMAKE_BUILD_TYPE >>> "  ${CMAKE_BUILD_TYPE})
#convert checks for debug / release
if(CMAKE_BUILD_TYPE)
string(TOLOWER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "debug")
  set(CMAKE_BUILD_TYPE Debug)
  message("CMAKE_BUILD_TYPE DEBUG")
elseif(CMAKE_BUILD_TYPE STREQUAL "release")
  set(CMAKE_BUILD_TYPE Release)
  message("CMAKE_BUILD_TYPE RELEASE")
else() #DEFAULT TO DEBUG
  set(CMAKE_BUILD_TYPE Debug)
  message("CMAKE_BUILD_TYPE Debug")
endif()

project(eeapp VERSION 0.0.1)

#add_definitions(-DECM_TEST01)
#add_definitions(-DECME_VULKAN)

set(PROJECT_VERSION 0.0.1)
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)

message("START OF CMAKELIST...")
# https://bewagner.net/programming/2020/05/02/cmake-fetchcontent/
set(FETCHCONTENT_FULLY_DISCONNECTED ON) # When this option is enabled, no attempt is made to download or update any content.
#set(FETCHCONTENT_UPDATES_DISCONNECTED ON) # download and skip update

#================================================
# ENTERY POINTS
#================================================
# entry point file.cpp
set(ENTRYPOINT 
  #vulkantriangle01.cpp
  #tests/glfw3glad1_01.cpp
  #tests/glfw3glad1_02.cpp
  #tests/glfw3glad1_03.cpp
  #tests/glfw3glad2.cpp
  #tests/glfwgl3w.cpp #not working
  #tests/vulkantriangle01.cpp #partly working
  #tests/vulkantriangle02.cpp #partly working
  #glfwvulkanimgui01.cpp

  #src/main.cpp
)
#message("ENTRYPOINT: ${ENTRYPOINT}") # console log

#set(FETCHCONTENT_SOURCE_DIR_SDL ON)
#set(FETCHCONTENT_SOURCE_DIR_SDL_IMAGE ON)
#set(FETCHCONTENT_SOURCE_DIR_SDL_MIXER ON)
#set(FETCHCONTENT_SOURCE_DIR_IMGUI ON)
#================================================
# CONFIGS
#================================================
# deal with add ons and checks tests
# WINDOW / INPUT / CPU RENDER
set(ENABLE_SDL OFF)
set(ENABLE_GLFW ON)
# FONT
set(ENABLE_FREETYPE OFF) #needed for sdl image
set(ENABLE_SDL_TTF OFF)
# IMAGE
set(ENABLE_SDL_IMAGE OFF)
# SOUND / AUDIO
set(ENABLE_SDL_MIXER OFF)
# ENTITY COMPONENT SYSTEM
set(ENABLE_FLECS OFF)
# GRAPHIC USER INTERFACE
set(ENABLE_IMGUI ON)
# 3D GRAPHIC API
set(ENABLE_VALKUN ON)
set(ENABLE_GL3W OFF)
set(ENABLE_GLAD OFF)
set(ENABLE_GLAD2 OFF)
# MATH GRAPHIC
set(ENABLE_GLM ON)
# MESH
set(ENABLE_TINYOBJECTLOADER OFF)

#================================================
# NETWORK
#================================================
#https://github.com/ValveSoftware/GameNetworkingSockets/blob/master/BUILDING.md
#set(ENABLE_GAMENETWORKKINGSOCKETS OFF) # not recommend 
# there no CMakeList.txt in third parties.
# REQUIRED openssl
# REQUIRED perl
# REQUIRED ninja
# REQUIRED Protobuf

#================================================
# GIT PACKAGE VERSION
#================================================
set(FREETYPE_GIT_VERSION VER-2-10-4) # GITHUB RELEASE TAG
set(GLM_GIT_VERSION 0.9.9.8)
set(GLFW_GIT_VERSION 3.3.4)

set(SDL_GIT_VERSION release-2.0.14) # SDL GITHUB RELEASE TAG
set(SDL_TTF_GIT_VERSION main) # SDL GITHUB RELEASE TAG
set(SDL_IMAGE_GIT_VERSION main) # SDL GITHUB RELEASE TAG
set(SDL_MIXER_GIT_VERSION master) # SDL GITHUB RELEASE TAG
set(IMGUI_GIT_VERSION 
  #docking
  v1.82
) # GITHUB RELEASE TAG
set(FLECS_GIT_VERSION v2.3.2) # GITHUB RELEASE TAG
set(GAMENETWORKKINGSOCKETS_GIT_VERSION master) # GITHUB RELEASE TAG

# config IDE ext 
#include(CTest)
#enable_testing()
#================================================
# CONFIGS
#================================================
#et(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)
message("CMAKE_SYSTEM_NAME == " ${CMAKE_SYSTEM_NAME})
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  #target_compile_options(myApp PRIVATE /W4)
  #message("WINDOW")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  #target_compile_options(myApp PRIVATE -Wall -Wextra -Wpedantic)
  #message("Linux")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  # other macOS-specific flags for Clang
  #message("Darwin")
endif()
# https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html
#cmake -DCMAKE_BUILD_TYPE=Debug path/to/source
#cmake -DCMAKE_BUILD_TYPE=Release path/to/source

#message("CMAKE_C_FLAGS_RELEASE >>> "  ${CMAKE_C_FLAGS_RELEASE})
#message("CMAKE_C_FLAGS >>> "  ${CMAKE_C_FLAGS})
#message("CMAKE_CXX_FLAGS >>> "  ${CMAKE_CXX_FLAGS})
#message("CMAKE_CONFIGURATION_TYPES >>> "  ${CMAKE_CONFIGURATION_TYPES})
#message("CMAKE_CFG_INTDIR >>> "  ${CMAKE_CFG_INTDIR})
#message("CMAKE_CUDA_FLAGS >>> "  ${CMAKE_CUDA_FLAGS})
#message("CMAKE_Fortran_FLAGS >>> "  ${CMAKE_Fortran_FLAGS})

#message("CMAKE_CURRENT_SOURCE_DIR  >>>  " ${CMAKE_CURRENT_SOURCE_DIR})
#message("CMAKE_CURRENT_BINARY_DIR  >>>  " ${CMAKE_CURRENT_BINARY_DIR})

# must set output build dir by default is none. user must config manual
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#message("CMAKE_ARCHIVE_OUTPUT_DIRECTORY: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}") # workspace/build/Debug
#message("CMAKE_LIBRARY_OUTPUT_DIRECTORY: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
#message("CMAKE_RUNTIME_OUTPUT_DIRECTORY: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# build compiler tool
#set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD 11)
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#if(MSVC)
  #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
#endif(MSVC)

# https://stackoverflow.com/questions/20643370/visual-studio-2013-fatal-error-c1041-fs
ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

# folders, files, libs
set(CPP_INCLUDE_DIRS "")
set(CPP_HEADER_FILES "")
set(CPP_SOURCE_FILES "")
set(CPP_LIBS "")

if(ENABLE_FREETYPE)
  if (NOT freetype_FOUND) # If there's none, fetch and build
    include(FetchContent)
    FetchContent_Declare(
      freetype
      GIT_REPOSITORY https://github.com/freetype/freetype.git
      GIT_TAG ${FREETYPE_GIT_VERSION}
      #GIT_TAG VER-2-10-4
    )
    FetchContent_GetProperties(freetype)
    if (NOT freetype_POPULATED) # Have we downloaded raylib yet?
      set(FETCHCONTENT_QUIET NO)
      FetchContent_Populate(freetype)
      message("freetype_LIBRARY: " ${freetype_LIBRARY}) # fail but define in cmake
      message("freetype_INCLUDE_DIR: " ${freetype_INCLUDE_DIR}) #pass
      message("freetype_SOURCE_DIR: " ${freetype_SOURCE_DIR}) # pass
      message("freetype_BINARY_DIR: " ${freetype_BINARY_DIR}) # pass

      #set(FT_WITH_ZLIB OFF CACHE BOOL "" FORCE)
      #set(FT_WITH_BZIP2 OFF CACHE BOOL "" FORCE)
      #set(FT_WITH_PNG OFF CACHE BOOL "" FORCE)
      #set(FT_WITH_HARFBUZZ OFF CACHE BOOL "" FORCE)
      #set(FT_WITH_BROTLI OFF CACHE BOOL "" FORCE)

      # build freetype
      list(APPEND CPP_INCLUDE_DIRS ${freetype_SOURCE_DIR}/include)
      list(APPEND CPP_INCLUDE_DIRS ${freetype_BINARY_DIR}/include)
      list(APPEND CPP_HEADER_FILES ${freetype_SOURCE_DIR}/include/ft2build.h)
      
      list(APPEND FREETYPE_INCLUDE_DIRS ${freetype_SOURCE_DIR}/include)
      list(APPEND FREETYPE_INCLUDE_DIRS ${freetype_BINARY_DIR}/include)

      set(FREETYPE_LIBRARY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

      #link_directories(${sdl_ttf_BINARY_DIR}/Debug)# this will look for libs files.
      add_subdirectory(${freetype_SOURCE_DIR} ${freetype_BINARY_DIR}) #add to build in sub dir
      add_library(Freetype::Freetype ALIAS freetype)

    endif()
  endif()
endif()

#================================================
# SDL
#================================================
if (ENABLE_SDL)
  message("[[[=== CHECKING SDL2 === ]]]")
  # base on environment system path variable set.
  # find_package(sdl QUIET) # Requires at least version 2.5.0
  message("sdl_FOUND:" ${SDL_FOUND})
  if (NOT sdl_FOUND) # If there's none, fetch and build sdl
    include(FetchContent)
    FetchContent_Declare(
      sdl
      GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
      GIT_TAG ${SDL_GIT_VERSION}
    )
    FetchContent_GetProperties(sdl)
    if (NOT SDL2_POPULATED) # Have we downloaded raylib yet?
      set(FETCHCONTENT_QUIET NO)
      FetchContent_Populate(sdl)
      #message("SDL_LIBRARY: " ${sdl_LIBRARY}) # fail but define in cmake
      #message("SDL_INCLUDE_DIR: " ${sdl_INCLUDE_DIR}) #pass
      #message("sdl_SOURCE_DIR: " ${sdl_SOURCE_DIR}) # pass
      #message("sdl_BINARY_DIR: " ${sdl_BINARY_DIR}) # pass
      # build SDL2
      list(APPEND CPP_INCLUDE_DIRS ${sdl_SOURCE_DIR}/include)
      #include_directories(${sdl2_BINARY_DIR}/include) 

      #link_directories(${PROJECT_BINARY_DIR}/Debug)
      add_subdirectory(${sdl_SOURCE_DIR} ${sdl_BINARY_DIR})
    endif()

    #needed for sub modules
    list(APPEND SDL2_INCLUDE_DIR ${sdl_SOURCE_DIR}/include)

    list(APPEND SDL2_LIBRARIES ${PROJECT_SOURCE_DIR}/build/Debug/SDL2maind.lib)
    list(APPEND SDL2_LIBRARIES ${PROJECT_SOURCE_DIR}/build/Debug/SDL2-staticd.lib)
    list(APPEND SDL2_LIBRARIES ${PROJECT_SOURCE_DIR}/build/Debug/SDL2d.lib)

    #list(APPEND SDL2_LIBRARY ${PROJECT_BINARY_DIR}/Debug/SDL2maind.lib)
    #list(APPEND SDL2_LIBRARY ${PROJECT_BINARY_DIR}/Debug/SDL2-staticd.lib)
    #list(APPEND SDL2_LIBRARY ${PROJECT_BINARY_DIR}/Debug/SDL2d.lib)

    #list(APPEND SDL2_LIB ${PROJECT_SOURCE_DIR}/build/Debug/SDL2maind.lib)
    #list(APPEND SDL2_LIB ${PROJECT_SOURCE_DIR}/build/Debug/SDL2-staticd.lib)
    #list(APPEND SDL2_LIB ${PROJECT_SOURCE_DIR}/build/Debug/SDL2d.lib)

    list(APPEND CPP_LIBS "SDL2main")
    list(APPEND CPP_LIBS "SDL2-static")
    add_library(SDL2::SDL2 ALIAS SDL2)
    add_library(SDL2::SDL2-static ALIAS SDL2-static)
  endif()
endif()
link_directories(${PROJECT_BINARY_DIR}/Debug)
#================================================
# SDL TTF
#================================================
if (ENABLE_SDL_TTF)
  # base on environment system path variable set.
  if (NOT sdl_image_FOUND) # If there's none, fetch and build sdl
    include(FetchContent)
    FetchContent_Declare(
      sdl_ttf
      GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
      GIT_TAG ${SDL_TTF_GIT_VERSION}
    )
    FetchContent_GetProperties(sdl_ttf)
    if (NOT sdl_ttf_POPULATED) # Have we downloaded raylib yet?
      set(FETCHCONTENT_QUIET NO)
      FetchContent_Populate(sdl_ttf)
      #message("sdl_ttf_LIBRARY: " ${sdl_ttf_LIBRARY}) # fail but define in cmake
      #message("sdl_ttf_INCLUDE_DIR: " ${sdl_ttf_INCLUDE_DIR}) #pass
      #message("sdl_ttf_SOURCE_DIR: " ${sdl_ttf_SOURCE_DIR}) # pass
      #message("sdl_ttf_BINARY_DIR: " ${sdl_ttf_BINARY_DIR}) # pass
      # build SDL2
      #list(APPEND CPP_INCLUDE_DIRS ${sdl_image_SOURCE_DIR}/include)
      add_subdirectory(${sdl_ttf_SOURCE_DIR} ${sdl_ttf_BINARY_DIR})
      #list(APPEND CPP_LIBS "sdl_ttf")
    endif()
  endif()
endif()
#================================================
# SDL IMAGE
#================================================
if (ENABLE_SDL_IMAGE)
  # base on environment system path variable set.
  if (NOT sdl_image_FOUND) # If there's none, fetch and build sdl
    include(FetchContent)
    FetchContent_Declare(
      sdl_image
      GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
      GIT_TAG ${SDL_IMAGE_GIT_VERSION}
    )
    FetchContent_GetProperties(sdl_image)
    if (NOT sdl_image_POPULATED) # Have we downloaded raylib yet?
      set(FETCHCONTENT_QUIET NO)
      FetchContent_Populate(sdl_image)
      #message("sdl_image_LIBRARY: " ${sdl_image_LIBRARY}) # fail but define in cmake
      #message("sdl_image_INCLUDE_DIR: " ${sdl_image_INCLUDE_DIR}) #pass
      #message("sdl_image_SOURCE_DIR: " ${sdl_image_SOURCE_DIR}) # pass
      #message("sdl_image_BINARY_DIR: " ${sdl_image_BINARY_DIR}) # pass
      set(SUPPORT_JPG OFF CACHE BOOL "" FORCE)
      set(SUPPORT_PNG ON CACHE BOOL "" FORCE)
      set(BUILD_SHOWIMAGE OFF CACHE BOOL "" FORCE)
      set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
      # BUILD_SHARED_LIBS OFF is LIB

      # build sdl2 image
      list(APPEND CPP_INCLUDE_DIRS ${sdl_image_SOURCE_DIR})
      add_subdirectory(${sdl_image_SOURCE_DIR} ${sdl_image_BINARY_DIR})
      list(APPEND CPP_LIBS "SDL2_image")
    endif()
  endif()
endif()
#================================================
# SDL MIXER
#================================================
if (ENABLE_SDL_MIXER)
  # base on environment system path variable set.
  if (NOT sdl_mixer_FOUND) # If there's none, fetch and build sdl
    include(FetchContent)
    FetchContent_Declare(
      sdl_mixer
      GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer.git
      GIT_TAG ${SDL_MIXER_GIT_VERSION}
    )
    FetchContent_GetProperties(sdl_mixer)
    if (NOT sdl_mixer_POPULATED) # Have we downloaded raylib yet?
      set(FETCHCONTENT_QUIET NO)
      FetchContent_Populate(sdl_mixer)
      #message("sdl_mixer_LIBRARY: " ${sdl_mixer_LIBRARY}) # fail but define in cmake
      #message("sdl_mixer_INCLUDE_DIR: " ${sdl_mixer_INCLUDE_DIR}) #pass
      #message("sdl_mixer_SOURCE_DIR: " ${sdl_mixer_SOURCE_DIR}) # pass
      #message("sdl_mixer_BINARY_DIR: " ${sdl_mixer_BINARY_DIR}) # pass

      set(ANDROID ON)
      set(SUPPORT_OGG ON CACHE BOOL "" FORCE)
      #set(SUPPORT_OGG ON CACHE BOOL "" FORCE)

      # build SDL2 MIXER
      list(APPEND CPP_INCLUDE_DIRS ${sdl_mixer_SOURCE_DIR}/include)
      add_subdirectory(${sdl_mixer_SOURCE_DIR} ${sdl_mixer_BINARY_DIR})
      list(APPEND CPP_LIBS "SDL2_mixer")
    endif()
  endif()
endif()
#================================================
# FLECS
#================================================
if (ENABLE_FLECS)
  message("[[[=== CHECKING FLECS === ]]]")
  #find_package(flecs QUIET) # Requires at least version 2.5.0
  if (NOT flecs_FOUND) # If there's none, fetch and build flecs
    include(FetchContent)
    FetchContent_Declare(
      flecs
      GIT_REPOSITORY https://github.com/SanderMertens/flecs.git
      GIT_TAG ${FLECS_GIT_VERSION}
    )
    FetchContent_GetProperties(flecs)
    if (NOT flecs_POPULATED) # Have we downloaded flecs yet?
      set(FETCHCONTENT_QUIET NO)
      FetchContent_Populate(flecs)
      # build flecs
      add_subdirectory(${flecs_SOURCE_DIR} ${flecs_BINARY_DIR})
    endif()
  endif()
endif()

if (ENABLE_TINYOBJECTLOADER)
  message("[[[=== CHECKING TINY OBJECT LOADER === ]]]")
  #find_package(flecs QUIET) # Requires at least version 2.5.0
  if (NOT tinyobjectloader_FOUND) # If there's none, fetch and build flecs
    include(FetchContent)
    FetchContent_Declare(
      tinyobjectloader
      GIT_REPOSITORY https://github.com/tinyobjloader/tinyobjloader.git
      GIT_TAG v1.0.7
      #GIT_TAG ${FLECS_GIT_VERSION}
    )
    FetchContent_GetProperties(tinyobjectloader)
    if (NOT tinyobjectloader_POPULATED) # Have we downloaded flecs yet?
      set(FETCHCONTENT_QUIET NO)
      FetchContent_Populate(tinyobjectloader)
      # build tinyobjectloader
      list(APPEND CPP_INCLUDE_DIRS ${tinyobjectloader_SOURCE_DIR})
      add_subdirectory(${tinyobjectloader_SOURCE_DIR} ${tinyobjectloader_BINARY_DIR})
      list(APPEND CPP_LIBS "tinyobjloader")
    endif()
  endif()
endif()

if (ENABLE_GLM)
  message("[[[=== CHECKING GLM === ]]]")
  #find_package(flecs QUIET) # Requires at least version 2.5.0
  if (NOT glm_FOUND) # If there's none, fetch and build 
    include(FetchContent)
    FetchContent_Declare(
      glm
      GIT_REPOSITORY https://github.com/g-truc/glm.git
      GIT_TAG ${GLM_GIT_VERSION}
    )
    FetchContent_GetProperties(glm)
    if (NOT glm_POPULATED) # Have we downloaded  yet?
      set(FETCHCONTENT_QUIET NO)
      FetchContent_Populate(glm)

      list(APPEND CPP_INCLUDE_DIRS ${glm_SOURCE_DIR})

      # build glm
      add_subdirectory(${glm_SOURCE_DIR} ${glm_BINARY_DIR})
    endif()
  endif()
endif()

if (ENABLE_GLFW)
  message("[[[=== CHECKING GLFW === ]]]")
  #find_package(flecs QUIET) # Requires at least version 2.5.0
  if (NOT glfw_FOUND) # If there's none, fetch and build 
    include(FetchContent)
    FetchContent_Declare(
      glfw
      GIT_REPOSITORY https://github.com/glfw/glfw.git
      GIT_TAG ${GLFW_GIT_VERSION}
    )
    FetchContent_GetProperties(glfw)
    if (NOT glfw_POPULATED) # Have we downloaded  yet?
      set(FETCHCONTENT_QUIET NO)
      FetchContent_Populate(glfw)
      list(APPEND CPP_INCLUDE_DIRS ${glfw_SOURCE_DIR}/include)

      set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
      set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
      set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
      set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

      # build glm
      add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})

      list(APPEND CPP_LIBS "glfw3")
    endif()
  endif()
endif()

#================================================
# GL3W
#================================================
if(ENABLE_GL3W)
  message("[[[=== CHECKING GL3W === ]]]")
  if (NOT gl3w_FOUND) # If there's none, fetch and build sdl
    include(FetchContent)
    FetchContent_Declare(
      gl3w
      GIT_REPOSITORY https://github.com/skaslev/gl3w.git
      GIT_TAG master
    )
    FetchContent_GetProperties(gl3w)
    if (NOT gl3w_POPULATED) # Have we downloaded raylib yet?
      set(FETCHCONTENT_QUIET NO)
      FetchContent_Populate(gl3w)
      # utility to setup the downloaded library for use
      #FetchContent_MakeAvailable(gl3w)
      message("GL3W GITHUB ====================================   ")
      message("GL3W GITHUB SRC >>> " ${gl3w_SOURCE_DIR})
      message("GL3W GITHUB BIN >>> " ${gl3w_BINARY_DIR})

      list(APPEND CPP_INCLUDE_DIRS ${gl3w_BINARY_DIR}/include)
      #list(APPEND CPP_INCLUDE_DIRS ${gl3w_BINARY_DIR}/src)

      list(APPEND CPP_HEADER_FILES ${gl3w_BINARY_DIR}/include/GL/gl3w.h)
      list(APPEND CPP_HEADER_FILES ${gl3w_BINARY_DIR}/src/gl3w.c)
      
      add_subdirectory(${gl3w_SOURCE_DIR} ${gl3w_BINARY_DIR}) #add to build in sub dir
    endif()
  endif()
endif()
#================================================
# IMGUI
#================================================

if (ENABLE_IMGUI)
  message("[[[=== CHECKING IMGUI === ]]]")
  #find_package(imgui QUIET) # Requires at least version 2.5.0
  if (NOT imgui_FOUND) # If there's none, fetch and build imgui
    include(FetchContent)
    FetchContent_Declare(
      imgui
      GIT_REPOSITORY https://github.com/ocornut/imgui.git
      GIT_TAG ${IMGUI_GIT_VERSION}
    )
    FetchContent_GetProperties(imgui)
    if (NOT imgui_POPULATED) # Have we downloaded imgui yet?
      set(FETCHCONTENT_QUIET NO)
      FetchContent_Populate(imgui)
      #message("imgui_SOURCE_DIR: " ${imgui_SOURCE_DIR})
      list(APPEND CPP_INCLUDE_DIRS ${imgui_SOURCE_DIR})
      list(APPEND CPP_INCLUDE_DIRS ${imgui_SOURCE_DIR}/backends)
      #INCLUDE_HEADERS
      #list(APPEND INCLUDE_HEADERS ${imgui_SOURCE_DIR}/imconfig.h)
      list(APPEND CPP_SOURCE_FILES ${imgui_SOURCE_DIR}/imgui.cpp)
      list(APPEND CPP_HEADER_FILES ${imgui_SOURCE_DIR}/imgui.h)

      list(APPEND CPP_HEADER_FILES ${imgui_SOURCE_DIR}/imgui_internal.h)
      list(APPEND CPP_SOURCE_FILES ${imgui_SOURCE_DIR}/imgui_demo.cpp)
      list(APPEND CPP_SOURCE_FILES ${imgui_SOURCE_DIR}/imgui_draw.cpp)
      list(APPEND CPP_SOURCE_FILES ${imgui_SOURCE_DIR}/imgui_tables.cpp)
      list(APPEND CPP_SOURCE_FILES ${imgui_SOURCE_DIR}/imgui_widgets.cpp)
      #list(APPEND CPP_HEADER_FILES ${imgui_SOURCE_DIR}/imstb_rectpack.h)
      #list(APPEND CPP_HEADER_FILES ${imgui_SOURCE_DIR}/imstb_textedit.h)
      #list(APPEND CPP_HEADER_FILES ${imgui_SOURCE_DIR}/imstb_truetype.h)
      #list(APPEND CPP_SOURCE_FILES ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl.cpp)
      #list(APPEND CPP_HEADER_FILES ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl.h)

      #list(APPEND CPP_SOURCE_FILES ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp)
      #list(APPEND CPP_HEADER_FILES ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.h)

      list(APPEND CPP_SOURCE_FILES ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp)
      list(APPEND CPP_HEADER_FILES ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.h)

      list(APPEND CPP_SOURCE_FILES ${imgui_SOURCE_DIR}/backends/imgui_impl_vulkan.cpp)
      list(APPEND CPP_HEADER_FILES ${imgui_SOURCE_DIR}/backends/imgui_impl_vulkan.h)
    endif()
  endif()
endif()
#================================================
# VULKAN
#================================================
if(ENABLE_VALKUN)
  message("[[[=== CHECKING VULKAN SECTION === ]]]")
  #look for Vulkan SDK location
  find_package(Vulkan)

  if(NOT Vulkan_FOUND)
    message("NOT FOUND VULKAN")
    return()
  endif()

  if(Vulkan_FOUND)
    set(VULKAN_PATH ${Vulkan_INCLUDE_DIRS})
    STRING(REGEX REPLACE "/Include" "" VULKAN_PATH ${VULKAN_PATH})
  endif()

  # vulkan-1 library for build Vulkan application.
  #set(VULKAN_LIB_LIST "vulkan-1")
  list(APPEND CPP_LIBS "vulkan-1")

  if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    message("VULKAN_PATH " ${VULKAN_PATH})
    # Include Vulkan header files from Vulkan SDK
    #include_directories(AFTER ${VULKAN_PATH}/Include)
    list(APPEND CPP_INCLUDE_DIRS ${Vulkan_INCLUDE_DIRS})

    # Link directory for vulkan-1
    link_directories(${VULKAN_PATH}/Bin;${VULKAN_PATH}/Lib;)
  endif()
endif()

#not working required third party libs
if(ENABLE_GAMENETWORKKINGSOCKETS)
  message("[[[=== CHECKING GAMENETWORKKINGSOCKETS === ]]]")
  if (NOT gamenetworkingsockets_FOUND) # If there's none, fetch and build flecs
    include(FetchContent)
    FetchContent_Declare(
      gamenetworkingsockets
      GIT_REPOSITORY https://github.com/ValveSoftware/GameNetworkingSockets.git
      GIT_TAG ${GAMENETWORKKINGSOCKETS_GIT_VERSION}
    )
    FetchContent_GetProperties(flecs)
    if (NOT gamenetworkingsockets_POPULATED) # Have we downloaded flecs yet?
      set(FETCHCONTENT_QUIET NO)
      FetchContent_Populate(gamenetworkingsockets)
      set(GAMENETWORKINGSOCKETS_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
      set(GAMENETWORKINGSOCKETS_BUILD_TESTS OFF CACHE BOOL "" FORCE)
      # build gamenetworkingsockets
      add_subdirectory(${gamenetworkingsockets_SOURCE_DIR} ${gamenetworkingsockets_BINARY_DIR})

    endif()
  endif()
endif()

if(ENABLE_GLAD)
  set(GLAD_DIR ${PROJECT_SOURCE_DIR}/opengl/glad)
  add_library(glad ${GLAD_DIR}/src/glad.c)
  target_include_directories(glad PRIVATE ${GLAD_DIR}/include)
  list(APPEND CPP_INCLUDE_DIRS ${GLAD_DIR}/include)
  #target_include_directories(${PROJECT_NAME} PRIVATE ${GLAD_DIR}/include)
  #target_link_libraries(${PROJECT_NAME} PUBLIC glad ${CMAKE_DL_LIBS} PRIVATE ${glfw3_LIB}) #pass
  #target_link_libraries(${PROJECT_NAME} PRIVATE ${glfw3_LIB} glad ${CMAKE_DL_LIBS})
  list(APPEND CPP_LIBS "glad")
endif()

if(ENABLE_GLAD2)
  set(GLAD2_DIR ${PROJECT_SOURCE_DIR}/opengl/glad2)
  add_library(glad ${GLAD2_DIR}/src/gl.c)
  target_include_directories(glad PRIVATE ${GLAD2_DIR}/include)
  list(APPEND CPP_INCLUDE_DIRS ${GLAD2_DIR}/include)
  #target_include_directories(${PROJECT_NAME} PRIVATE ${GLAD_DIR}/include)
  #target_link_libraries(${PROJECT_NAME} PUBLIC glad ${CMAKE_DL_LIBS} PRIVATE ${glfw3_LIB}) #pass
  #target_link_libraries(${PROJECT_NAME} PRIVATE ${glfw3_LIB} glad ${CMAKE_DL_LIBS})
  list(APPEND CPP_LIBS "glad")
endif()

#find_package(OpenGL REQUIRED)
#================================================
# TARGET SET UP SECTION
#================================================


#================================================
# INCLUDE DIRS
#================================================
include_directories(${CPP_INCLUDE_DIRS})
include_directories(${CPP_INCLUDE_DIRS}/srcee)
#================================================
# EXECUTE APP TEST
#================================================
#add_executable(${PROJECT_NAME} ${ENTRYPOINT})

set(ENTRYPOINT
  srcee/eemain.cpp
)

set(EE01_FILES "")
set(EE01_DIR srcee)

file(GLOB EE01_FILES 
  #"${EE01_DIR}/*.cpp"
  "${EE01_DIR}/core/*.hpp"
  "${EE01_DIR}/core/*.cpp"
  #"${EE01_DIR}/scene/*.hpp"
  #"${EE01_DIR}/scene/*.cpp"
  "${EE01_DIR}/application/*.hpp"
  "${EE01_DIR}/application/*.cpp"
  "${EE01_DIR}/application/vulkan/*.hpp"
  "${EE01_DIR}/application/vulkan/*.cpp"
)

add_executable(${PROJECT_NAME} 
  ${CPP_HEADER_FILES}
  ${CPP_SOURCE_FILES}
  ${EE01_FILES}
  ${ENTRYPOINT} 
)
#================================================
# LIBRARIES
#================================================
#message("OPENGL_LIBRARIES >>> " ${OPENGL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} 
  ${CPP_LIBS}
  #${OPENGL_LIBRARIES} #opengl32
  #glad
)
#[[

]]

set(GLSLC "${VULKAN_PATH}/Bin/glslc.exe")

add_custom_command(TARGET ${PROJECT_NAME} 
	PRE_BUILD 
	COMMAND ${GLSLC} ${CMAKE_CURRENT_SOURCE_DIR}/shaders/shader.vert -o ${CMAKE_BINARY_DIR}/Debug/shaders/vert.spv
	COMMAND ${GLSLC} ${CMAKE_CURRENT_SOURCE_DIR}/shaders/shader.frag -o ${CMAKE_BINARY_DIR}/Debug/shaders/frag.spv
	COMMENT "BUILD SHADERS OUTPUT!"
)

#================================================
# EXECUTE APP ECME CPP
#================================================
# https://stackoverflow.com/questions/15550777/how-do-i-exclude-a-single-file-from-a-cmake-fileglob-pattern/15551302
set(CPP_ECME01_FILES "")
set(ECME01_DIR src02)

file(GLOB CPP_ECME01_FILES 
  "${ECME01_DIR}/*.cpp"
  "${ECME01_DIR}/core/*.hpp"
  "${ECME01_DIR}/core/*.cpp"
  "${ECME01_DIR}/scene/*.hpp"
  "${ECME01_DIR}/scene/*.cpp"
  "${ECME01_DIR}/application/*.hpp"
  "${ECME01_DIR}/application/*.cpp"
  "${ECME01_DIR}/application/vulkan/*.hpp"
  "${ECME01_DIR}/application/vulkan/*.cpp"
)

#message("CPP_ECME01_FILES >>> "  ${CPP_ECME01_FILES})
#[[
add_executable(ecme 
  ${CPP_HEADER_FILES}
  ${CPP_SOURCE_FILES}
  ${CPP_ECME01_FILES}
)

target_link_libraries(ecme
  ${CPP_LIBS}
  #opengl32
)
]]

#================================================
# INCLUDE DIRS
#================================================
#target_include_directories(${PROJECT_NAME} 
  #PRIVATE 
  #${INCLUDE_PATHS}
#)
#target_link_libraries(${PROJECT_NAME} SDL2main SDL2-static)
#target_link_libraries(${PROJECT_NAME} PRIVATE SDL2main SDL2-static flecs_static ${VULKAN_LIB_LIST})
#================================================
# COMPILER
#================================================
#target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
message("END OF CMAKELIST...")