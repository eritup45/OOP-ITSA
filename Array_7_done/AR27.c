#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#define Max 800000

int main(void)
{
    int len,i=1,cnt=0,temp;
    int num[Max]={0},ans[Max]={0};
    char line[Max]={'\0'};
    char *token;


        fgets(line,Max,stdin);
        len = atoi(line);
        fgets(line,Max,stdin);
        line[strlen(line)-1]='\0';
        token = strtok(line," ");
        while(token!=NULL)
        {
            temp = atoi(token);
            num[temp] = 1;
            token = strtok(NULL," ");
        }
        for(i=1,cnt=0;i<=len;i++)
        {
            if(num[i]==0)
            {
                ans[cnt]=i;
                cnt++;
            }
        }
        for(i=0;i<cnt;i++)
        {
            if(i==cnt-1)
            {
                    printf("%d\n",ans[i]);
                    break;
            }
            printf("%d ",ans[i]);
        }
        for(i=0;i<Max;i++)
        {
            ans[i]=0;
            num[i]=0;
        }

    return 0;
}
