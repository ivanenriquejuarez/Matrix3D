#include <iostream>
#include <cstdint>
#include <array>

constexpr std::uint32_t BLACK {0x000000};
constexpr std::uint32_t RED   {0xFF0000};
constexpr std::uint32_t BLUE  {0x0000FF};

//1. Define pixel buffer dimensions (3 columns x 2 rows)
constexpr int WIDTH {3};
constexpr int HEIGHT {2};

void clearPixelBuffer(auto& pixelBuffer, std::uint32_t color)
{
    for (auto& pixel: pixelBuffer){
        pixel = color;
    }
}

void printPixelBuffer(const auto& pixelBuffer){
    for (const auto& pixel: pixelBuffer) {
        std::cout << pixel << std::endl;
    }
}

// 2. Set a pixel's color if its coordinates are within bounds
void setPixel(auto& pixelBuffer, int x, int y, std::uint32_t color)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT){
        int index = (y * WIDTH) + x;    // Convert (x, y) into cooresponding array index
        pixelBuffer[index] = color;
    } else {
        std::cout << "Pixel coordinates out of bounds.\n";
    }
    
}

int main() {
    // Idea of a pixel buffer
    /*
        PIXEL BUFFER — 3 columns x 2 rows

                     X (columns)
                     0    1    2
                   +----+----+----+
        Y = 0      | 0  | 1  | 2  |
                   +----+----+----+
        Y = 1      | 3  | 4  | 5  |
                   +----+----+----+

        width  = 3  // Total columns
        height = 2  // Total rows
        x = 1       // Target column (horizontal)
        y = 1       // Target row (vertical)

        Each array element stores one color value.

        Formula: index = (y * width) + x

        Example: (1 * 3) + 1 = index 4

        Valid coordinates:
        x: 0 to 2
        y: 0 to 1
    */
    
    // Initializing our pixel buffer
    std::array<std::uint32_t, 6> pixelBuffer {};
    
    // Set pixel (2,0) to blue
    setPixel(pixelBuffer, 2, 0, 0x0000FF);
    std::cout << "Set coordinate (2,0) to blue\n";
    printPixelBuffer(pixelBuffer);
    
    // Clear pixel buffer to a designated color
    std::cout << "\nCleared pixels to all red\n";
    clearPixelBuffer(pixelBuffer, RED);
    printPixelBuffer(pixelBuffer);
    
    return 0;
}
