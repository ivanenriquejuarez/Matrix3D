// 1. Building a 3D cube
#include <iostream>
#include <format>
#include <array>

struct Point {
    float x {};
    float y {};
    float z {};
};

// 3. Represents one edge connecting two vertices
struct Edge {
    int start {};
    int end {};
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
    // 2. Used an array DS to store the struct Point(s)
    std::array<Point, 8> cube {{
        {-0.5f,  0.5f,  0.5f},  // A [0] - Top, Left, Positive Z
        {-0.5f,  0.5f, -0.5f},  // B [1] - Top, Left, Negative Z
        { 0.5f,  0.5f, -0.5f},  // C [2] - Top, Right, Negative Z
        { 0.5f,  0.5f,  0.5f},  // D [3] - Top, Right, Positive Z
        
        {-0.5f, -0.5f,  0.5f},  // E [4] - Bottom, Left, Positive Z
        {-0.5f, -0.5f, -0.5f},  // F [5] - Bottom, Left, Negative Z
        { 0.5f, -0.5f, -0.5f},  // G [6] - Bottom, Right, Negative Z
        { 0.5f, -0.5f,  0.5f}   // H [7] - Bottom, Right, Positive Z
    }};
    
    // 3. Define the cube's 12 edges
    //    each edge contains two int indices : start and end
    //    A cube contains:
    //    4 edges forming top, 4 edges forming bottom, 3 vertical edges connecting both faces
    std::array<Edge, 12> edges = {{
        {0, 1},  // A -> B
        {1, 2},  // B -> C
        {2, 3},  // C -> D
        {3, 0},  // D -> A
        {4, 5},  // E -> F
        {5, 6},  // F -> G
        {6, 7},  // G -> H
        {7, 4},  // H -> E
		{4, 0},  // E -> A
        {5, 1},  // F -> B
        {6, 2},  // G -> C
        {7, 3}   // H -> D
    }};
    
    // 4. Understanding how edge indexing works
    std::cout << "Edge Understanding\n";
    std::cout << edges[0].start << std::endl;
    std::cout << edges[0].end << std::endl;
    
    // Retrieve coordinates of one edge
    // edges[0].start = 0 -> cube[0] -> Vertex A
    // edges[0].end   = 1 -> cube[1] -> Vertex B
    std::cout << "\nConnecting points A and B... \n";
    printPoints(cube[edges[0].start]);
    printPoints(cube[edges[0].end]);
    std::cout << std::endl;
    
    // Iterating through all 12 edges
    std::cout << "Iterating edges\n";
    for (const Edge& edge: edges) {
        std::cout << "{" <<edge.start << "," << edge.end <<  "}" << std::endl;
    }
    
    // Connect the edge indices to their vertex coordinates
    // Print both endpoints to verify the geometry
    std::cout << std::endl;
    for (const Edge& edge: edges) {
        std::cout << std::format("Connecting Point {} to Point {}\n", edge.start, edge.end);
        printPoints(cube[edge.start]);
        printPoints(cube[edge.end]);
    }
    return 0;
}
