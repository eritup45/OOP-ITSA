#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
void de_bubble(int arr[], int len){
    int i=0,j=0,tmp;
    for(i=0; i<len; i++){
        for(j=0; j<len-i-1; j++){
            if(arr[j] < arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void as_bubble(int arr[], int len){
    int i=0, j=0, tmp;
    for(i=0; i<len; i++){
        for(j=0; j<len-1; j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int as_compare( const void *a, const void *b){
    /*int ret = *(int *)(a)-*(int *)(b);
	if (ret>0) return 1;
	if (ret<0) return -1;
	return 0;*/
	return *(int*)a - *(int*)b;
}
int de_compare( const void *a, const void *b){
    return *(int*)b - *(int*)a;
}

void divArr(int arr[], int div, int len){
    int i=0, divLen = len / div;
    printf("N = %d, Array = ", div);
    printf("%d", arr[0]);
    for(i=1; i<divLen; i++){
        printf(" %d",arr[i]);
    }
    printf("\n");
}

int main(){
    int i=0, j=0, enterFlag=0, div;
    char word[10];
    int arr[100010];
    while(scanf("%s", word) != EOF){
        if( isdigit( word[0] ) && enterFlag == 0){
            arr[i] = atoi(word);
            i++;
        }
        else if( isdigit( word[0] ) && enterFlag == 1){
            div = atoi(word);
            divArr(arr, div, i);
        }
        else if(strcmp( word, "-a" ) == 0){
            //as_bubble(arr, i);
            qsort(arr, i, sizeof(arr[0]), as_compare);
            printf("Array = ");
            printf("%d", arr[0]);
            for(j=1; j<i; j++)
                printf("% d",arr[j]);
            printf("\n");
            enterFlag = 1;
        }
        else if(strcmp( word, "-d" ) == 0){ //check
            printf("Array = ");
            qsort(arr, i, sizeof(arr[0]), de_compare);
            //de_bubble(arr, i);
            printf("%d", arr[0]);
            for(j=1; j<i; j++)
                printf("% d",arr[j]);
            printf("\n");
            enterFlag = 1;
        }

    }
    return 0;
}
