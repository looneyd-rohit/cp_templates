#include <bits/stdc++.h>

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
    Workshop *arr = new Workshop[n];
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
    while (i < ptr->n - 1)
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

int main(int argc, char *argv[])
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
