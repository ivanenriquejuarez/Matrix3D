#include <iostream>
#include <format>

struct Point3d
{
    float x {};
    float y {};
    float z {};
};

int main(int argc, const char * argv[]) {
    Point3d point {0.99f, 0.45f, 0.99f};
    std::cout << std::format("Point: ({}, {}, {})\n", point.x, point.y, point.z);
    
    point.y = 0.99f;
    std::cout << std::format("After y reassignment: ({}, {}, {})\n", point.x, point.y, point.z);
    
    return 0;
}
