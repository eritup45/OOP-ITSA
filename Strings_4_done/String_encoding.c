#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

#define Max 100

int main(void)
{
    char line[Max]={'\0'};
    int i;
    int ans=0;

    while((fgets(line,Max,stdin))!=NULL)
    {
        line[strlen(line)-1]='\0';
        ans = line[0]-'A'+1;
        for(i=1;line[i]!='\0';i++)
        {
            ans = (line[i]-'A')+ 1 + ans*26;
        }
        printf("%d\n",ans);
    }
    return 0;
}
