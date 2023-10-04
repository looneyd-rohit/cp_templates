#include <iostream>
using namespace std;

class req
{
    int a;

public:
    req()
    {
        a = 0;
    }
    req(int num)
    {
        a = num;
    }
    req(req &x)
    {
        cout << "copy!!!" << endl;
        a = x.a;
    }
    void display()
    {
        cout << "value = " << a << endl;
    }
};

int main()
{
    req a, b(2), c(a);
    req d = b;
    a.display();
    b.display();
    c.display();
    d.display();

    return 0;
}