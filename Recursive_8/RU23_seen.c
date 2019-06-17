#include<stdio.h>
int main(){
    int n,A[40];
    int i;
    scanf("%d", &n);
    A[1] = 2;   A[2] = 4;
    for(i=3; i<5; i++)
        A[i] = A[i-1] * 2 - 1;
    for(i=5; i<=n; i++)
        A[i] = A[i-1] * 2 - A[i-4];
    printf("%d\n", A[n]);
    return 0;
}
