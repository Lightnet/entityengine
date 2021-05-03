// https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library
// https://learnopengl.com/Getting-started/Hello-Window
// https://paroj.github.io/gltut/Getting%20Started%20with%20OpenGL.html
#include <cstdio>
#include <fstream>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

static void error_callback(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(int argc, char** argv){
  GLFWwindow* window;

  glfwSetErrorCallback(error_callback);
  if (!glfwInit()) {
    printf("failed to initialize GLFW.\n");
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  window = glfwCreateWindow(800, 600, "GLFW+OpenGL3", nullptr, nullptr);
  glfwMakeContextCurrent(window);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  if (gl3wInit()) {
    printf("failed to initialize OpenGL\n");
    //return -1;
  }

  if (!gl3wIsSupported(3, 2))
  {
    //std::fprintf(stderr, "Context doesn't support OpenGL 3.2\n");
    printf("Context doesn't support OpenGL 3.2\n");
    //return -1;
  }


  /*
  glfwSetKeyCallback(window, key_callback);
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);
  printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));
  */
  while (!glfwWindowShouldClose(window))
  {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}