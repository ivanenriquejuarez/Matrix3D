#include <iostream>
#include <format>

struct Point3d
{
    float x {};
    float y {};
    float z {};
};

void printPoints(const Point3d& point3d)
{
    std::cout << std::format("Coordinates: ({}, {}, {})\n", point3d.x, point3d.y, point3d.z);
}

void moveXPoint(Point3d& point, float offset)
{
    point.x += offset;
}

Point3d translateXPoint(Point3d point, float offset)
{
    point.x += offset;
    return point;
}

int main(int argc, const char * argv[]) {
    Point3d point {1.0f, 2.0f, 3.0f};
    printPoints(point);
    
    moveXPoint(point, 5.0f);
    printPoints(point);
    
    printPoints(point);
    Point3d point2 = translateXPoint(point, 2.0f);
    
    printPoints(point2);
    return 0;
}
