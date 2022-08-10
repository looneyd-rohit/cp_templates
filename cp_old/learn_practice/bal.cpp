#include <bits/stdc++.h>
using namespace std;
class Complex
{
    int x;
    int y;

public:
    Complex(int x = 0, int y = 0) : x(x), y(y) {}

    Complex(Complex &c)
    {
        cout << "copy constructor called!!!" << endl;
        this->x = c.x;
        this->y = c.y;
    }

    Complex operator+(const Complex &c)
    {
        Complex c1;
        c1.x = this->x + c.x;
        c1.y = this->y + c.y;
        return c1;
    }
    void display()
    {
        cout << "result = " << x << " + i" << y << endl;
    }
};

int main()
{
    Complex a(1, 2), b(3, 4);
    Complex c = a + b;
    c.display;

    return 0;
}