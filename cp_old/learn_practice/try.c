#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct STUDENT
{
    int s_no;
    int roll;
    char s_name[100];
    char id[6];
    char c_name[100];
};

int main()
{
    int n, i, j, c = 0;
    scanf("%d", &n);
    struct STUDENT record[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &record[i].s_no);
        scanf("%d", &record[i].roll);
        j = -1;
        do
        {
            j++;
            scanf("%c", &record[i].s_name[j]);
        } while (record[i].s_name[j] != '\0');

        j = -1;
        do
        {
            j++;
            scanf("%c", &record[i].id[j]);
        } while (record[i].id[j] != '\0');

        j = -1;
        do
        {
            j++;
            scanf("%c", &record[i].c_name[j]);
        } while (record[i].c_name[j] != '\0');
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (strcmp(record[i].id, record[j].id) == 0)
                break;
        }
        if (i == j)
        {
            printf("%s", record[i].id);
            for (int k = 0; k < n; k++)
            {
                if (strcmp(record[i].id, record[k].id) == 0)
                    c++;
            }
            printf("%d", c);
        }
    }
    return 0;
}