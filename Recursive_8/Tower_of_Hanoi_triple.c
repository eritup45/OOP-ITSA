#include<stdio.h>
int main(){
    int n;
    long long a;
    scanf("%d",&n);
    a=3*((1<<n)-1);
    printf("%lld\n",a);
    return 0;
}
