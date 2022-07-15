// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

/*
g++ main.cpp -o test -lSDL2
SDL: https://wiki.libsdl.org/, https://wiki.libsdl.org/Installation, https://wiki.libsdl.org/SDL_CreateWindow
*/

int main (int argc, char* argv[]) {

    // Create window data type
    SDL_Window* window=nullptr;

    // SDL initialization with basic error output 
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Cannot initialize SDL" << SDL_GetError();
        return 1;
    } else {
        std::cout << "Initialized SDL" << std::endl;
    }

    // Create a window
    window = SDL_CreateWindow(
        "Window Title",
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_SHOWN                   // flags
    );

    // Check that the window was successfully created
    if (window == nullptr) {
        // In the case that the window could not be made...
        std::cout << "Could not create window" << SDL_GetError();
        return 1;
    }

    // Pause SDL execution
    SDL_Delay(6000);

    // Destroy/close window
    SDL_DestroyWindow(window);

    // SDL quit
    SDL_Quit(); 
    return 0;
}
