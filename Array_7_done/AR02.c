#include    <stdio.h>
#include    <stdlib.h>
#define Max 10
typedef struct node
{
    int cof;
    int pow;
    struct node *next;
}Node;

Node *pol[Max];

Node *insert(Node *head,int cof,int pow)
{
    Node *n;
    Node *ptr = head;
    n = (Node *)malloc(sizeof(Node));
    n->cof = cof;
    n->pow = pow;
    n->next = NULL;

    if(head == NULL)
    {
        head = n;
    }
    else
    {
        while(ptr->next != NULL){ptr = ptr->next;}
        ptr->next = n;
    }
    return head;
}

Node *search(Node *head, int pow)
{
    Node *ptr = head;

    while(ptr!=NULL)
    {
        if(ptr->pow == pow){return ptr;}
        ptr = ptr->next;
    }
    return NULL;
}

Node *mult(Node *n1,Node *n2)
{
    Node *ans = NULL,*check,*p1,*p2;
    int pow,cof;

    for(p1=n1;p1!=NULL; p1 = p1->next)
    {
        for(p2=n2;p2!=NULL;p2 = p2->next)
        {
            pow = p1->pow + p2->pow;
            cof = p1->cof * p2->cof;
            check = search(ans,pow);
            if(check==NULL)
            {
                ans = insert(ans,cof,pow);
            }
            else
            {
                check->cof = check->cof + cof;
            }

        }
    }
    return ans;
}
void print_poly(Node *head)
{
    Node *ptr = head;
    while(ptr->next!=NULL)
    {
        printf("%d ",ptr->cof);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->cof);
}

int main(void)
{
    int x2_c,x1_c,con_c,pow;
    int i=2;
    Node *head=NULL;

    while(scanf("%d%d%d%d",&x2_c,&x1_c,&con_c,&pow)!=EOF)
    {
        head = insert(head,x2_c,2);
        head = insert(head,x1_c,1);
        head = insert(head,con_c,0);
        pol[0] = head;
        pol[1] = head;

        for(i=2;i<=pow;i++)
        {
            pol[0] = mult(pol[0],pol[1]);
        }
        print_poly(pol[0]);
    }
    return 0;
}
