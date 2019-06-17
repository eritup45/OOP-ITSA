#include<stdio.h>
int main(){
    int ncase,n;
    long long A[60];
    int i;
    A[1] = 2;
    A[2] = 4;
    A[3] = 8;
    for(i=4; i<6; i++)
        A[i] = A[i-1]*2-1;
    for(i=6; i<=55; i++)
        A[i] = A[i-1]*2-A[i-5];
    scanf("%d", &ncase);
    while(ncase--){
        scanf("%d",&n);
        printf("%lld\n",A[n]);
    }
    return 0;
}
