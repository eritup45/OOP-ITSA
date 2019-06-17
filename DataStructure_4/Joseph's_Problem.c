#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct line{
    char L[60];
    struct line *next;
}line;
int main(){
    line *first, *last, *temp, *pop;
    int ncase, n, k;
    char S[60];
    int i;
    scanf("%d", &ncase);
    while(ncase--){
        scanf("%d %d", &n, &k);
        first = NULL;
        for(i=0; i<n; i++){
            scanf("%s", S);
            temp = malloc(sizeof(line));
            strcpy(temp->L, S);
            if(first == NULL)
                first = temp;
            else
                last->next = temp;
            temp->next = first;
            last = temp;
        }
        n--;
        while(n--){
            for(i=0; i<k-2; i++)
                first = first->next;
            pop = first->next;
            temp = pop->next;
            first->next = temp;
            first = temp;
            free(pop);
        }
        printf("%s\n",first->L);
    }
    return 0;
}
