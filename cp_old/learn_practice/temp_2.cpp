#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b, i;
    cin >> a >> b;
    for (i = a; i <= b; i++)
    {
        if ((i % 2 == 0) && (i > 9))
        {
            cout << "even\n";
        }
        else if ((i % 2 == 1) && (i > 9))
        {
            cout << "odd\n";
        }
        else if (1 <= i <= 9)
        {
            if (i == 1)
                cout << "one\n";
            if (i == 2)
                cout << "two\n";
            if (i == 3)
                cout << "three\n";
            if (i == 4)
                cout << "four\n";
            if (i == 5)
                cout << "five\n";
            if (i == 6)
                cout << "six\n";
            if (i == 7)
                cout << "seven\n";
            if (i == 8)
                cout << "eight\n";
            if (i == 9)
                cout << "nine\n";
        }
    }
    return 0;
}