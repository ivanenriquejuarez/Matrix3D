// 1. Translate 3d point
#include <iostream>
#include <format>

struct Point {
    float x {};
    float y {};
    float z {};
};

void printPoints(const Point& points)
{ std::cout << std::format("x: {}, y: {}, z: {} \n", points.x, points.y, points.z); }

void offsetPointY(Point& points, float offset)
{ points.y += offset; }

// 2. Why translate? Maybe we want a new coordinate to dictate the next move
//    while we preserve the old data point
// We want to create a function that returns the point
// so we use our struct as our return type
Point translatePointY(Point points, float translateNum)
{
    points.y += translateNum;
    return points;
}

int main()
{
    Point pointOne = {0.50f, 0.30f, 0.50f};
    std::cout << "Original coordinates: ";
    printPoints(pointOne);
    
    // 3. Translated points:
    Point pointTwo = translatePointY(pointOne, 0.50f);
    std::cout << "New coordinates: ";
    printPoints(pointTwo);
    
    
    return 0;
}
