#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    int ans=0;
    int i,j;
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        for(j=0;j<i;j++)
            if(A[j]>A[i]*2)
                ans++;
    }
    printf("%d\n",ans);
    return 0;
}
