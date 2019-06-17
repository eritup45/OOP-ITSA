#include<stdio.h>
int min;
int binary(int n){
    int b;
    for(b=2; b<=n; b<<=1)
        if(b == n)
            return 1;
    return 0;
}
void change(int n, int step){
    if(n == 1){
        if(step < min)
            min = step;
        return;
    }
    else if(n%2 == 0)
        change(n/2, step+1);
    else{
        if(binary(n-1))
            change(n-1, step+1);
        else if(binary(n+1))
            change(n+1, step+1);
    }
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        min = 99999999;
        change(n, 0);
        printf("%d\n", min);
    }
    return 0;
}
