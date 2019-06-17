#include <stdio.h>
#include <stdlib.h>

int cmp( const void *a, const void *b)
{
    return (*(int*)b - *(int*)a);
}

int main()
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        int i, total, nth;
        scanf("%d%d", &total, &nth);

        int *input;
        input = calloc(total, sizeof(int));

        for(i = 0; i < total; i++)
        {
            scanf("%d", &input[i]);
        }

        qsort(input, total, sizeof(int), cmp); // sort from small to large

        printf("%d\n", input[nth-1]);
    }

    return 0;
}
