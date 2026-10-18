// 1. Memory and Pointers
//    Exactly how much memory occupies the variabkes we create
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

Point translatePointY(Point points, float translateNum)
{
    points.y += translateNum;
    return points;
}

int main()
{
    // 2. sizeof determines storage size from the type
    Point pointOne = {0.50f, 0.30f, 0.50f};
    std::cout << "Floats\n";
    std::cout << "float size: "<< sizeof(float) << std::endl;
    std::cout << "Point size: " << sizeof(Point) <<std::endl;
    std::cout << "pointOne size: " << sizeof(pointOne) << std::endl;
    
    // 3. & address-of operator to access the address of said variable
    std::cout << "\nAddress-of operator\n";
    std::cout << "address of pointOne: " << &pointOne << std::endl;
    std::cout << "address of pointOne.x: " << &pointOne.x << std::endl;
    std::cout << "address of pointOne.y: " << &pointOne.y << std::endl;
    std::cout << "address of pointOne.z: " << &pointOne.z << std::endl;
    
    // 4. pointer which points to another variable so we can access the original object
    std::cout << "\nPointers" << std::endl;
    Point* pointerOne = &pointOne;
    std::cout << "pointOne address: " << &pointOne << std::endl;
    std::cout << "pointerOne (pointer) address: " << pointerOne << std::endl;
    std::cout << "Accessing pointTwo value x: " << pointerOne->x << std::endl;
    pointerOne->x = .75f;
    std::cout << "pointerOne changed to: " << pointerOne->x << std::endl;
    std::cout << "since pointerOne changed x value, poineOne x becomes: " << pointOne.x << std::endl;
    return 0;
}
