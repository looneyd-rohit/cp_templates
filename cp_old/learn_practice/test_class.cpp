#include <bits/stdc++.h>
using namespace std;

// int c;

class abc
{
    int a;
    static int b;

public:
    abc()
    {
    }
    abc(int a)
    {
        this->a = a;
    }
    void setData(int a)
    {
        this->a = a;
        // return *this;
        b++;
        // c = 3;
    }
    void getData()
    {
        cout << "print = " << a << endl;
        cout << "count = " << b << endl;
        // cout << "print c = " << c << endl;
    }
};

int abc::b;

int main(int argc, char *argv[])
{
    // abc a, b;
    // a.setData(5);
    // a.getData();
    // b.setData(5);
    // b.getData();
    // string str("rohit");

    // string str = "rohit";
    // cout << str << endl;

    // string str(3, 'r');
    // cout << str << endl;
    // char str[6];
    // cin.getline(str, 6);
    // getline()

    // cout << str << endl;
    return 0;
}