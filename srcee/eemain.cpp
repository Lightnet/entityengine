#include <iostream>
#include <stdlib.h>
#include <stdio.h>

//#include "core/config.hpp"
#include "./core/engine.hpp"
//#include "./core/glfw-wrapper.hpp"
//#include "./core/sdl-wrapper.hpp"

int main() {

    std::cout << "Hello World!\n";
    //std::cout << intTest << "\n";

    EntityEngine::Engine().run();

    system("pause");
    return 0;
}