#include<stdio.h>
#include<string.h>
int main(){
    char S[1010];
    int i;
    fgets(S,1010,stdin);
    for(i=0;i<strlen(S)-1;i++){
        if((S[i]>='A'&&S[i]<='M')||(S[i]>='a'&&S[i]<='m'))
            S[i]+=13;
        else if((S[i]>='N'&&S[i]<='Z')||(S[i]>='n'&&S[i]<='z'))
            S[i]-=13;
    }
    printf("%s",S);
    return 0;
}
