// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

/*
g++ FILE.cpp -o NAME -lSDL2
SDL: https://wiki.libsdl.org/, https://wiki.libsdl.org/Installation, https://wiki.libsdl.org/SDL_CreateWindow
*/

int main (int argc, char* argv[]) {

    // Create window data type
    SDL_Window* window=nullptr;

    // SDL initialization with basic error output 
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Cannot initialize SDL" << SDL_GetError();
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
        SDL_WINDOW_SHOWN                   // flag
    );

    // Check successful window creation
    if (window == nullptr) {
        std::cerr << "Could not create window" << SDL_GetError() << std::endl;
        return 1;
    }

    //Create and init the renderer
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);
    if(render == nullptr)
    {
        std::cerr << "SDL_CreateRenderer() Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        return 1;
    }

    const Uint32 startMs = SDL_GetTicks();
    while(SDL_GetTicks() - startMs < 10000)
    {
        SDL_PumpEvents();

        //Render something
        SDL_RenderSetLogicalSize(render, 640, 480);

        //Set colour of renderer
        SDL_SetRenderDrawColor(render, 255, 255, 255, 255);

        //Clear the screen to the set colour
        SDL_RenderClear(render);

        //Show all that has been done behind the scenes
        SDL_RenderPresent(render);
    }

    // Destroy/close window, render
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    SDL_Quit(); 
    return 0;
}
