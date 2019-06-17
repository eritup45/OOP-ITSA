#include<stdio.h>
int main(){
    int ncase, n;
    long long R1[100] = {0}, R2[100] = {0};
    int i;
    R1[0] = 0;    R2[0] = 1;
    for(i=1; i<=90; i++){
        R1[i] = R2[i-1];
        R2[i] = R1[i-1] + R2[i-1];
    }
    scanf("%d", &ncase);
    while(ncase--){
        scanf("%d", &n);
        printf("%lld\n", R1[n] + R2[n]);
    }
    return 0;
}
