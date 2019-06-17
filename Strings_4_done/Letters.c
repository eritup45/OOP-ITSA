#include    <stdio.h>
#include    <string.h>
#include    <ctype.h>
#define Max 120

int main(void)
{
    char line[Max];
    char x;
    int test,i,index;
    int cnt[27]={0};

    while((scanf("%s",line))!=EOF)
    {
        for(i=0;line[i]!='\0';i++)
        {
            x = line[i];
            test =  isalpha(x);

            if(test!=0)
            {
                x = tolower(x);
                index = x - 'a';
                cnt[index]++;
            }
        }
        for(i=0;i<26;i++)
        {
            printf("%d\n",cnt[i]);
        }
    }

    return 0;
}
