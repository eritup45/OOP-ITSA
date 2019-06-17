#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//1=�� 2=�Q 3=�� 4=�d 5=�U 6=�Q�U 7=�ʸU 8=�d�U 9=��
int get_digit(int num){
    int d=0;
    while(num != 0){
        num /= 10;
        d++;
    }
    return d;
}

int get_headNum(int num){
    int headNum=0, digit, i=0;
    digit = get_digit(num);
    for(i=1; i<digit; i++){
        num /= 10;
    }
    headNum = num % 10;
    return headNum;
}

int cut_head(int num){
    int i=0, j=0, tmp=0, sum=0;
    int digit = get_digit(num);
    for(i=0; i<digit-1; i++){
        tmp = num % 10;
        for(j=i; j>0; j--){
            tmp *= 10;
        }
        sum += tmp;
        num /= 10;
    }
    return sum;
}

int main(){
    int i=0, j=0, totWord, len, digit, headNum=0;
    int num;
    char chNum[][3] = {"�s", "��", "�L", "��", "�v", "��", "��", "�m", "��", "�h"};
    char chDigit[][6] = {"","�B", "��", "�a", "�U", "�B�U", "�ոU", "�a�U", "��"};    //8
    scanf("%d", &totWord);
    while(totWord--){
        //for(i=0; i<9; i++)  printf("%s ", chDigit[i]);
        scanf("%d", &num);
        headNum = get_headNum(num);
        digit = get_digit(num);
        num = cut_head(num);
        //printf("---%d---", num);
        while(digit != 0){
            //printf("headNum:%d digit:%d\n", headNum, digit);
            if(headNum == 0 && digit > 4){
                continue;
            }
            else if(headNum == 0 && digit < 4)
                printf("%s",chNum[0]);
            else{
                printf("%s%s", chNum[headNum], chDigit[digit-1]);
            }
            headNum = get_headNum(num);
            digit = get_digit(num);
            num = cut_head(num);
        }
        printf("\n");
    }
    return 0;
}
