#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Workshop
{
    int start_time;
    int duration;
    int end;
};

struct Available_Workshops
{
    int n;
    Workshop *arr = (Workshop *)calloc(n, sizeof(Workshop));
} obj;

Available_Workshops *initialize(int start_time[], int duration[], int n)
{
    int i;
    obj.n = n;
    for (i = 0; i < n; i++)
    {
        obj.arr[i].start_time = start_time[i];
        obj.arr[i].duration = duration[i];
        obj.arr[i].end = start_time[i] + duration[i];
    }
    return (&obj);
}

int CalculateMaxWorkshops(Available_Workshops *ptr)
{
    int temp, sum = 0, i = 0;
    temp = ptr->arr[0].end;
    while (i < ptr->n)
    {
        if (temp > ptr->arr[i + 1].start_time)
        {
            sum++;
        }
        else
        {
            temp = ptr->arr[i + 1].end;
        }
        i++;
    }
    return (ptr->n - sum);
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, i;
    cin >> n;

    int start_time[n], duration[n];
    for (i = 0; i < n; i++)
        cin >> start_time[i];
    for (i = 0; i < n; i++)
        cin >> duration[i];
    Available_Workshops *x;
    x = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(x);

    return 0;
}
