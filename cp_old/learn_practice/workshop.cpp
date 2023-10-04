//
// Created by ROHIT on 21-07-2021.
//

#include <bits/stdc++.h>
using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int start_time;
    int duration;
    int end;
};
struct Available_Workshops
{
    int n;
    Workshop *arr;
};

Available_Workshops *initialize(int start_time[], int duration[], int n)
{
    int i;
    Available_Workshops *obj = new Available_Workshops;
    obj->n = n;
    obj->arr = new Workshop[n];
    for (i = 0; i < n; i++)
    {
        obj->arr[i].start_time = start_time[i];
        obj->arr[i].duration = duration[i];
        obj->arr[i].end = start_time[i] + duration[i];
    }
    return (obj);
}
void swapWorkshop(Workshop *a,Workshop *b)
{
    int temp_1 = a->start_time, temp_2 = a->duration, temp_3 = a->end;
    a->start_time = b->start_time;a->duration = b->duration;a->end = b->end;
    b->start_time = temp_1;b->duration = temp_2;b->end = temp_3;
}
void sortWorkshop(Available_Workshops *ptr)
{
    int i, j, n = ptr->n;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
        {
            if (ptr->arr[j].end > ptr->arr[j+1].end)
            {
                swapWorkshop(&(ptr->arr[j]), &(ptr->arr[j+1]));
            }
        }
}

int CalculateMaxWorkshops(Available_Workshops *ptr)
{
    int temp, sum = 0, i = 0;
    sortWorkshop(ptr);
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

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
