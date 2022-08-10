#include <iostream>
using namespace std;

class base
{
public:
    void jj()
    {
        cout << "i am base" << endl;
    }
};

class derived : public base
{
public:
    // void jj(int a)
    // {
    //     cout << "i am derived" << endl;
    // }
};

int main()
{
    derived d;
    d.jj();
    return 0;
}