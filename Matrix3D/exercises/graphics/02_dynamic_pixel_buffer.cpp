#include <iostream>
#include <vector>
#include <cstdint>

// Configure our box
constexpr int HEIGHT {1080};
constexpr int WIDTH {720};
constexpr int TOTAL_PIXELS = HEIGHT * WIDTH;

// Colors
constexpr std::uint32_t BLUE = 0x0000FF;

void setPixelColor(auto& dynamic_pb, int x, int y, std::uint32_t color)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT){
        int index = (y * WIDTH) + x;
        dynamic_pb[index] = color;
        std::cout << "\nColor set: " <<  dynamic_pb[index];
    } else {
        std::cout << "\nOut of bounds.";
    }
}

int main()
{
    std::cout << "Total pixel dimensions: " << TOTAL_PIXELS;
    std::vector<std::uint32_t> dynamic_pb(TOTAL_PIXELS);
    setPixelColor(dynamic_pb, 0, 0, BLUE);
    setPixelColor(dynamic_pb, 719, 1079, BLUE);
    
    
    return 0;
}
