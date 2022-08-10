#include <bits/stdc++.h>
using namespace std;

class Base
{
    int a;

public:
    Base()
    {
    }
    Base(int a)
    {
        this->a = a;
    }
    void fun()
    {
        cout << "this is fun from base" << endl;
    }
};

class Derived : public Base
{
    int b;

public:
    Derived(int b = 0)
    {
        this->b = b;
    }
    void fun()
    {
        cout << "this is fun from derived" << endl;
    }
};

class Complex
{
    int x;
    int y;

public:
    Complex(int x = 0, int y = 0) : x{x}, y{y} {}

    Complex(const Complex &c)
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
    void displaydd();
};
void Complex::displaydd()
{
    cout << "result xx lol" << endl;
}
// int Complex::var;

int main()
{
    // Base *base = new Derived();
    // base->fun();
    // Complex a(1, 2), b(3, 4);
    // Complex c = a + b;
    // Complex::displaydd();  //throws error as member funciton is not static
    Complex c;
    cout << "hi" << endl;
    return 0;
}