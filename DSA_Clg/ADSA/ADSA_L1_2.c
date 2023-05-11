#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
} Node;


Node *insert(Node *root,int d)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = d;
    if(root == NULL)
        root = p;
    else
    {
        Node *ptr = root;
        while(ptr->next !=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next=p;
    }
    return root;
}
void concatenate(Node *a,Node *b)
{
    if( a != NULL && b!= NULL )
    {
        if (a->next == NULL)
            a->next = b;
        else
            concatenate(a->next,b);
    }
    else
    {
        printf("Either a or b is NULL\n");
    }
}

void display(Node *root)
{
    Node *p = root;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    Node *root1 = (Node *)malloc(sizeof(Node));
    Node *root2 = (Node *)malloc(sizeof(Node));
    root1=insert(root1,20);
    root1=insert(root1,30);
    root1=insert(root1,40);
    root1=insert(root1,50);
    root1=insert(root1,60);
    root1=insert(root1,70);
    root1=insert(root1,80);

    root2=insert(root2,25);
    root2=insert(root2,35);
    root2=insert(root2,45);
    root2=insert(root2,55);
    root2=insert(root2,65);
    root2=insert(root2,75);
    root2=insert(root2,85);

    printf("\nList 1 :  ");
    display(root1);

    printf("\nList 2 :  ");
    display(root2);

    concatenate(root1,root2);

    printf("\nNew List:  ");
    display(root1);

    return 0;
}