// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char* argv[]){
    // Window data type: Point to the window that's allocated from SDL_CreateWindow
    SDL_Window* window=nullptr;

    // Initialize the SDL video subsystem
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not be initialized: " <<
                  SDL_GetError();
    } else {
        std::cout << "SDL has been initialized \n";
    }

    // Create window
    window = SDL_CreateWindow(
        "Window Title",
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_SHOWN                   // flag
    );

    if (window == nullptr) {
        std::cout << "Could not create window" << SDL_GetError();
        return 1;
    }

    SDL_Renderer* renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);  // -1 choose window driver for us
    
    // Create a rectangle
    SDL_Rect rectangle;
    rectangle.x = 320, rectangle.y = 240;  // position in window, in px
    rectangle.w = 50;  // rect a * b
    rectangle.h = 50;  // rect a * b (size, in px)

    // Infinite loop for our application
    bool gameloop = true;
    while(gameloop){
        SDL_Event event;

        // Event loop
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                gameloop = false;
            }
        }

        // Clear
        SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);  // black
        SDL_RenderClear(renderer);

        // Render
        SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);  // white

        SDL_RenderDrawLine(renderer,25,25,200,200);  // x, y, angles
        SDL_RenderDrawRect(renderer,&rectangle);

        // Display rendered things
        SDL_RenderPresent(renderer);
    }

    // Destroy window, pass pointer to memory allocated by SDL_CreateWindow
    SDL_DestroyWindow(window);
    
    SDL_Quit();
    return 0;
}
