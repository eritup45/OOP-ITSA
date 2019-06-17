#include<stdio.h>
#include<math.h>
int main(){
    int in,t;
    int a,b;
    int i;
    while(scanf("%d",&in)!=EOF){
        t=in;b=1;
        for(i=2;i<=sqrt(in);i++)
            if(t%(i*i)==0){
                b*=i;
                t/=i*i;
                i--;
            }
        a=t;
        printf("%d = %d*%d^2\n",in,a,b);
    }
    return 0;
}
