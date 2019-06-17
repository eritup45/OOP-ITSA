#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *a, const void *b)
{
  return (*(int*)a - *(int*)b);
}

bool check(int a, int b, int c)
{
    if(a+b>c && a+c>b && b+c>a)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int i, j, k;
    int number;
    int *list;

    list = calloc(60, sizeof(int));

    while(scanf("%d", &number) == 1)
    {
        for(i = 0; i < number; i++)
        {
            scanf("%d", &list[i]);
        }

        qsort(list, number, sizeof(int), cmp);

        for(i = 0; i < number-2; i++)
        {
            for(j = i+1; j < number-1; j++)
            {
                for(k = j+1; k < number; k++)
                {
                    if(check(list[i], list[j], list[k]) == true)
                    {
                        printf("%d %d %d\n", list[i], list[j], list[k]);
                    }
                }
            }
        }
    }

    return 0;
}
