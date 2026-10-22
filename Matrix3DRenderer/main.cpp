#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstdint>

#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>

int main(int argc, const char * argv[]) {
    // Declare our video variables
    const std::string title = "Matrix3D Renderer";
    constexpr int WIDTH = 1920;
    constexpr int HEIGHT = 1080;
    bool done = false;
    constexpr int totalPixels = WIDTH * HEIGHT;
    std::vector<std::uint32_t> pixelBuffer(totalPixels);
    
    // SDL necessary variables to instantiate our video
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;
    
    // Initialization
    // Initialize SDL with flag video
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "SDL Video Initialization Failed! " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "SDL Video Initialization Successfully!\n";
    
    // Create application window
    window = SDL_CreateWindow(title.c_str(), WIDTH, HEIGHT, SDL_WINDOW_ALWAYS_ON_TOP);
    if (window == nullptr) {
        std::cout << "Window creation failed! " << SDL_GetError() << std::endl;
        SDL_Quit();
        return EXIT_FAILURE;
    }
    std::cout << "Window Successfully Created!\n";
    
    // Create renderer
    renderer = SDL_CreateRenderer(window, nullptr);
    if (renderer == nullptr) {
        std::cout << "Renderer failed! " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }
    std::cout << "Renderer Successfully Created!\n";
    
    // Create texture
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
    if (texture == nullptr) {
        std::cout << "Texture creation failed! " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }
    std::cout << "Texture Successfully Created...\n";
    
    // Have window running
    while (!done) {
        SDL_Event event;
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
                std::cout << "\n\nUser has requested to be shutdown.\nShutting down...";
            }
        }
    }
    
    // Cleanup and end program
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
