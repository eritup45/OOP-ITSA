#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input;
    int temp = 0, max = 0;

    while(scanf("%d", &input)==1)
    {
        temp += input;

        if(max < temp)
        {
            max = temp;
        }

        if(temp < 0)
        {
            temp = 0;
        }
    }

    printf("%d\n", max);

    return 0;
}
