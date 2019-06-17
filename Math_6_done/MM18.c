#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main(void)
{
    int np,i,j,max = 0,min = INT_MAX,distence = INT_MAX,pos;
    scanf("%d",&np);
    int point[np][3];
    for(i=0;i<np;i++)
        scanf("%d%d",&point[i][0],&point[i][1]);
    for(i=0;i<np;i++){
        max = 0;
        for(j=0;j<np;j++){
            distence = (point[i][0] -  point[j][0]) * (point[i][0] -  point[j][0]) + (point[i][1] -  point[j][1]) * (point[i][1] -  point[j][1]);
            if(distence > max)
                max = distence;
        }
        if(max < min){
            min = max;
            pos = i;
        }
        else if(max == min){
            if(point[i][0] < point[pos][0]){
                pos = i;
            }
            else if(point[i][1] < point[pos][1] && point[i][0] == point[pos][0])
                pos = i;
        }
    }
    printf("%d %d\n",point[pos][0],point[pos][1]);
    return 0;
}
