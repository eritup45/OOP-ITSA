#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int gcd(int a, int b)
{
    int c;

    while (a != 0)
    {
        c = a;
        a = b%a;
        b = c;
    }

    return b;
}

int main()
{
    double min = (double)INT_MAX;
    int min_sur = 0, min_vol = 0;
    int cases,divisor;
    scanf("%d", &cases);

    while(cases--)
    {
        int height, width, depth;
        scanf("%d%d%d", &height, &width, &depth);

        int volume, surface;

        volume = height*width*depth;
        surface = 2*(height*width+width*depth+height*depth);

        double record;

        record = (double)surface / (double)volume;

        if(record < min)
        {
            min = record;
            min_sur = surface;
            min_vol = volume;
        }

    }

    divisor = gcd(min_sur, min_vol);

    printf("%d/%d\n", min_sur/divisor, min_vol/divisor);

    return 0;
}
