#include <iostream>
#include <string>
#include <cstdlib>

#include <SDL3/SDL_init.h>  // Import SDL3 Library Initialization
#include <SDL3/SDL_main.h>

int main(int argc, const char * argv[]) {
    // Declare our video variables
    std::string title = "Matrix3d Renderer";
    const int WIDTH = 640;
    const int HEIGHT = 720;
    
    SDL_Window *window;
    bool done = false;
    
    // Initialize SDL with flag video
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "SDL Video Initialization Failed!\n";
        return EXIT_FAILURE;
    }
    std::cout << "SDL Video Initialization Success!\n";
    
    // Creating a variable window and store the returned pointer
    window = SDL_CreateWindow(
                        title.c_str(),
                        WIDTH,
                        HEIGHT,
                        SDL_WINDOW_ALWAYS_ON_TOP
                    );
    
    // Check whether window creation succeeded
    if (window == nullptr) {
        std::cout << "Window creation failed! " << SDL_GetError() << std::endl;
        SDL_Quit();
        return EXIT_FAILURE;
    }
    
    std::cout << "Window Successfully Created!\n";
    std::cout << "Initialzing the window..." << std::endl;
    
    // Keep the window running
    while (!done) {
        SDL_Event event;
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
        }
    }
    
    // Cleanup and end
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
