#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int compare( const void *a, const void *b){
    /*int ret = *(int *)(a)-*(int *)(b);
	if (ret>0) return 1;
	if (ret<0) return -1;
	return 0;*/
	return *(int*)a - *(int*)b;
}

int main(){
    int tot, len, arrlen=0, i=0, j=0, arr[100010] = {0};

    scanf("%d", &tot);
    for(i=0; i<tot; i++){
        arrlen = 0;
        scanf("%d", &len);
        for(j=0; j<len; j++){
            scanf("%d", &arr[arrlen]);
            arrlen++;
        }
        for(j=0; j<len; j++){
            scanf("%d", &arr[arrlen]);
            arrlen++;
        }
        qsort(arr, arrlen, sizeof(arr[0]), compare);
        if( arrlen % 2 == 0 )
            printf("%d\n", arr[arrlen/2-1]);
        else
            printf("%d\n", arr[arrlen/2]);
    }

    return 0;
}
