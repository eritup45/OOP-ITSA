#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

#define Max 1000

char Stack[Max];
int top = -1;

void Push(char sym)
{
    if(top==Max){return;}
    Stack[++top] = sym;
}

char Pop(void)
{
    if(top==-1){return'0';}
    return Stack[top--];
}

int priority(char sym)
{
		switch(sym)
		{
				case '+': return 1;
				case '-': return 1;
				case '*':	return 2;
				case '/': return 2;
				default: return 0;
		}
}

int main(void)
{
    char line[Max];
    int i,test;
    char sym,t,x;

    fgets(line,Max,stdin);
    line[strlen(line)-1]='\0';

    for(i=0;line[i]!='#';i++)
    {
        t = line[i];
        test = isalpha(t);
        if(test!=0)
        {
            printf("%c",t);
        }
        else
        {
            sym = t;
            switch(sym)
            {
                case '(':
                        Push(sym);
                        break;
                case '+': case '-': case '*': case '/':
                        while( priority(Stack[top])>= priority(sym))
                        {
                            x = Pop();
                            printf("%c",x);
                        }
                        Push(sym);

                        break;

                case ')':
                        x = Pop();
                        while(x!='(')
                        {
                            printf("%c",x);
                            x = Pop();
                        }
                        break;
            }
        }
    }
    while(top!=-1)
    {

        x = Pop();
        if(x==')'){break;}
        printf("%c",x);
    }
    printf("\n");
    return 0;
}
