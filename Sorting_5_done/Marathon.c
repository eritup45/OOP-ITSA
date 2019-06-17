#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct Player{
    int num;
    int min;
    int sec;
};

int compare_min (const void * a, const void * b){
  struct Player *pA = (struct Player *)a;
  struct Player *pB = (struct Player *)b;
  return ( pA->min - pB->min );
}

void bubble(struct Player arr[], int len){
    int i=0, j=0;
    struct Player tmp;
    for(i=0; i<len; i++){
        for(j=0; j<len-1; j++){
            if(arr[j].sec > arr[j+1].sec && arr[j].min >= arr[j+1].min){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int main(){
    struct Player player[100010];
    int tot=0,i=0,j=0;
    char *token, line[1024];
    while(scanf("%d", &player[tot].num) != EOF){
        scanf("%s", line);
        token = strtok(line, "'\n\r");
        player[tot].min = atoi(token);
        token = strtok(NULL, "'\n\r");
        player[tot].sec = atoi(token);
        tot++;
    }
    qsort(player, tot, sizeof(struct Player), compare_min);
    bubble(player, tot);
    for(i=0; i<3; i++){
        printf("%d %d'%d\n",player[i].num,player[i].min,player[i].sec);
    }
    return 0;
}
