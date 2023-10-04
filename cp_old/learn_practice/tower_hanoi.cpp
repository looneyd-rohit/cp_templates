#include <bits/stdc++.h>
using namespace std;

int tower_hanoi(int n)
{
    if (n == 0)
        return 0;
    return (2 * tower_hanoi(n - 1) + 1);
}

void tower_hanoi_alt(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "move 1 from " << a << " to " << c << "." << endl;
        return;
    }
    tower_hanoi_alt(n - 1, a, c, b);
    cout << "move " << n << " from " << a << " to " << c << "." << endl;
    tower_hanoi_alt(n - 1, b, a, c);
}

int main()
{
    // cout << tower_hanoi(7) << endl;
    tower_hanoi_alt(4, 'A', 'B', 'C');
    return 0;
}