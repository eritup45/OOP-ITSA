#include<stdio.h>
#define MAX 7
int main()
{
    long long perfectnum[MAX] = {6, 28, 496, 8128, 33550336, 8589869056, 137438691328}, num;
    int i, n, ans;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%lld", &num);
        ans = 0;
        for(i = 0 ; i < MAX; i++)
        {
            if(num == perfectnum[i])
                ans = 1;
        }
        if(ans) {
            printf("perfect\n");
        }
        else {printf("nonperfect\n");}
    }
    return 0;
}
