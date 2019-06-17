#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//1=個 2=十 3=百 4=千 5=萬 6=十萬 7=百萬 8=千萬 9=億
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
    char chNum[][3] = {"零", "壹", "貳", "參", "肆", "伍", "陸", "柒", "捌", "玖"};
    char chDigit[][6] = {"","拾", "佰", "仟", "萬", "拾萬", "佰萬", "仟萬", "億"};    //8
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
