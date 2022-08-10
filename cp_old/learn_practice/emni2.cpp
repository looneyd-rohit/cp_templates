#include <bits/stdc++.h>
using namespace std;
class Point
{
private:
    int a[2];

public:
    Point(int x = 0, int y = 0)
    {
        this->a[0] = x;
        this->a[1] = y;
    }
    void print()
    {
        cout << this->a[0] << " + " << this->a[1] << "i" << endl;
    }
    int *operator[](int pos)
    {
        if (pos == 0)
            return a;
        else if (pos == 1)
            return (a + 1);
        else
        {
            cout << "out of bound !!!" << endl;
            exit(0);
        }
    }
};
int main()
{
    Point p1(1, 2), p2(2, 3);
    *p1[0] = 11;
    *p1[1] = 22;
    p1.print();
    return 0;
}