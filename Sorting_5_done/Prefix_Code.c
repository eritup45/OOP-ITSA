#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int compare(const void *a, const void *b){
    char *A = (char *)a;
    char *B = (char *)b;
    return(strlen(A) - strlen(B));
}
int main(){
    int i=0,j=0,k=0,p=0,totalword,tot=0,count=0,len;
    char line[10010][32];
    scanf("%d", &totalword);
    for(i=0; i<totalword; i++){
        count = 0;
        scanf("%d", &tot);
        for(j=0; j<tot; j++){
            scanf("%s", line[j]);
        }
        qsort(line,tot,sizeof(line[0]),compare);
        for(j=0; j<tot; j++){

            len = strlen(line[count]);
            for(k=j; k<tot; k++){
                if(k == count){
                    continue;
                }
                for(p=0; p<len; p++){
                    if(line[count][p] != line[k][p])
                        break;
                }
                if(p == len){
                    printf("No\n");
                    break;
                }
            }
            if(p == len){
                break;
            }
            count++;
        }
        if(j == tot)
            printf("Yes\n");
    }
    return 0;
}
