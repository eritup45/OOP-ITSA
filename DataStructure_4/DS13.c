#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#define Max 100

int Stack[Max];
int top=-1;

void Push(int data)
{
    if(top==Max){return;}
    Stack[++top] = data;
}

int Pop(void)
{
    if(top == -1){return -1;}
    return Stack[top--];
}

int operate(int op1,int op2,char sym)
{
    switch(sym)
    {
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
        case '%': return op1%op2;
    }
    return -1;
}

int main(void)
{
    char line[Max],t;
    int i,num,test;
    int op1,op2,ans;

    while((fgets(line,Max,stdin))!=NULL)
    {
        if(line[0]=='0'){break;}
        line[strlen(line)-1]='\0';

        for(i=0;line[i]!='\0';i++)
        {
            t =line[i];
            test = isdigit(t);
            if(test!=0)
            {
                num = t - '0';
                Push(num);
            }
            else
            {
                op2 = Pop();
                op1 = Pop();
                ans = operate(op1,op2,t);
                Push(ans);
            }
        }
        ans = Pop();
        printf("%d\n",ans);
    }
    return 0;
}
