// 1. Creating a single coordinate on 3d plane
#include <iostream>
#include <format>

// 2. Coordinates
// What is a single a coordinate on a 3d plane?
//  a: X, Y and Z
// Object is our shape that carries those 3 coordinates.
// Lets use a struct and call that 'point'.
struct Point {
    float x {};
    float y {};
    float z {};
};


// Prints the coordinate points of shape 'point'
void printPoints(const Point& points)
{
    std::cout << std::format("x: {}, y: {}, z: {}", points.x, points.y, points.z);
}

int main()
{
    // 3. Lets initialzie a coordinate
    Point pointOne = {0.50f, 0.80f, 0.50f};
    printPoints(pointOne);
    
    return 0;
}
