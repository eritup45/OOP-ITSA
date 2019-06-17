#include<stdio.h>
#include<string.h>
int main(){
    int l;
    char S[130];
    double ans,temp;
    int i,j;
    while(scanf("%d%s", &l, S) != EOF){
        ans = 0;
        for(; l<=strlen(S); l++){
            for(i=0; i <= strlen(S)-l; i++){
                temp = 0;
                for(j = i; j < i+l; j++)
                    if(S[j] == 'C' || S[j] == 'c' || S[j] == 'G' || S[j] == 'g')
                        temp += (double)1/l;
                if(temp > ans)
                    ans = temp;
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
