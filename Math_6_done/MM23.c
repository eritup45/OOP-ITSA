#include<stdio.h>
#include<stdlib.h>
void sort(int x[],int size)
{
    int i,j,tmp;
    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
            if(x[i] < x[j]){
                tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
            }
        }
    }
}
int main(void)
{
    int nd,np,center,tot,distence;
    int i,j;
    int number[501],buf[1000];
    scanf("%d",&nd);
    for(i=0;i<nd;i++){
        scanf("%d",&np);
        for(j=1;j<=np;j++){
            scanf("%d",&number[j]);
        }
        sort(number,np);
        if(np % 2 == 0)
            center = np / 2;
        else
            center = (np / 2) + 1;
        tot = 0;
        for(j=1;j<=np;j++){
            distence = number[center] - number[j];
            if(distence < 0)
                distence *= -1;
            tot = tot + distence;
        }
        buf[i] = tot;
    }
    for(i=0;i<nd;i++)
        printf("%d\n",buf[i]);
    return 0;
}
