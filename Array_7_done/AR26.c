#include<stdio.h>
int main(){
    int m,n,tot;
    int sex;
    int girl=0,boy=0;
    scanf("%d%d",&m,&n);
    tot=m*n;
    while(tot--){
        scanf("%d",&sex);
        if(sex==0)
            girl++;
        else
            boy++;
    }
    if(girl>boy)
        printf("0\n");
    else if(girl<boy)
        printf("1\n");
    else
        printf("2\n");
    return 0;
}
