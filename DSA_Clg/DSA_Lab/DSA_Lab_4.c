#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
    };

void display(struct node *head)
{
    if(head == NULL)
    {
        printf("------\n");
    }
    else
    {
        printf("%d\n", head -> data);
        display(head->next);
    }
}

void concatenate(struct node *a,struct node *b)
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
void insertAtEnd(struct node** head_ref, int new_data) 
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head_ref; 
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) 
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    { 
        last = last->next;
    }
    
    last->next = new_node;
    return;
}

void sortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node* current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) 
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        current = *head_ref;
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}
struct node* newNode(int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
struct node* makeLoop(struct node* start) //QUESTION 4
{
    int k;
    printf("\nEnter the kth position: ");
    scanf("%d",&k);
    struct node* last_node = start;
    struct node* kth_node = start;
    while (last_node->next!=NULL)
    {
        last_node=last_node->next;
    }
    while (k>1)
    {
        kth_node = kth_node->next;k-=1;
    }
    last_node->next = kth_node;
    return start;
}
int main()
{
    printf("\nPROGRAM 1\n");
    struct node *prev,*a, *b, *p;
    int n,i, k;
    printf("Enter the no. of elements in a:\n -->");
    scanf("%d",&n);
    a=NULL;
    printf("Enter elements of a:\n");
    for (i=0; i<n; i++)
    {
        scanf ("%d", &k);
        insertAtEnd(&a, k);
    }

    printf("Enter the no. of elements in b:\n -->");
    scanf("%d",&n);
    b=NULL;
    p=NULL;
    printf("Enter elements of b:\n");
    for (i=0; i<n; i++)
    {
        scanf ("%d", &k);
        insertAtEnd(&b, k);
    }
    concatenate(a,b);
    printf("Elements of merged list is:\n");
    display(a);
    printf("\n");

    
    printf("\nPROGRAM 2\n");
    struct node* head = NULL;
    struct node* new_node = newNode(5);
    sortedInsert(&head, new_node);
    new_node = newNode(10);
    sortedInsert(&head, new_node);
    new_node = newNode(7);
    sortedInsert(&head, new_node);
    new_node = newNode(3);
    sortedInsert(&head, new_node);
    new_node = newNode(1);
    sortedInsert(&head, new_node);
    new_node = newNode(9);
    sortedInsert(&head, new_node);
    printf("\n Created Linked List\n");
    display(head);
    printf("\n");

    printf("\nPROGRAM 3\n");

    printf("\n");

    printf("\nPROGRAM 4\n");
    makeLoop(a);
    printf("\n");
    return 0;
}