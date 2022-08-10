#include <iostream>
using namespace std;

// class hagi;

class hagu
{
    int a = 1;
    static int b;
    char c;
    friend class hagi;

public:
    void getData(void)
    {
        cout << "enter data" << endl;
        cin >> a;
        b++;
    }
    void display()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};

class hagi
{
public:
    void pig(hagu, hagu);
};

int hagu::b;
int main()
{
    hagu rohit;
    hagu sadhu;
    rohit.getData();
    rohit.display();
    sadhu.display();
    sadhu.getData();
    sadhu.display();
    return 0;
}
