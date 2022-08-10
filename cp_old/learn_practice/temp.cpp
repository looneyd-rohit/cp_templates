#include <iostream>
#include <math.h>
using namespace std;

class point
{
    int x;
    int y;

public:
    point(int a, int b);
    friend float dist(point p1, point p2);
};
point::point(int a, int b)
{
    x = a;
    y = b;
}

float dist(point p1, point p2)
{
    float d = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    return d;
}

int main()
{
    point p1(3, 4), p2(6, 8);
    cout << "The distance between two points is " << dist(p1, p2);
}
