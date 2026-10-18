// 1. Modify 3d point
#include <iostream>
#include <format>

struct Point {
    float x {};
    float y {};
    float z {};
};

void printPoints(const Point& points)
{ std::cout << std::format("x: {}, y: {}, z: {}", points.x, points.y, points.z); }

// 2. Offset point y by reference to prevent excess memory usage
void offsetPointY(Point& points, float offset)
{ points.y += offset; }

int main()
{
    Point pointOne = {0.50f, 0.30f, 0.50f};
    
    // 3. pointOne y is being offset by 0.50f
    offsetPointY(pointOne, 0.50f);
    printPoints(pointOne);
    
    return 0;
}
