#include <iostream>
#include <math.h>
using namespace std;

int modExp(int a, int n)
{
    if (n > 0)
    {
        if ((n & 1) == 1)
            return a * modExp(a, n - 1);
        return modExp(pow(a, 2), n >> 1);
    }
    return 1;
}
int main()
{
    cout << "Modulus Exponentiation result by recursion : " << modExp(5, 4) << endl;
    return 0;
}