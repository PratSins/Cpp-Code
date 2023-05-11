#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define maxsize 20
int rear=-1;
int front =-1;

int st1[100], st2[100];
int top1 = -1, top2 = -1;
int count = 0;
void create1()
{    top1 = top2 = -1; }
void push1(int data)
{ st1[++top1] = data; }
int pop1(){
    return(st1[top1--]);
}
void push2(int data)
{    st2[++top2] = data; }
int pop2()
{    return(st2[top2--]); }
void enqueue(){
    int data, i;
    printf("Enter data into queue -> ");
    scanf("%d", &data);
    push1(data);
    count++;
}
void display(int Queue[])  
{  
    printf("\nQueue : ");
    for(int i=0;i<=rear;i++)  
        printf("%d  ", Queue[i]);  
    printf("\n\n");
}  

void EnQueqe (int Queue[])
{
    int item;
    if(rear== maxsize-1)
        printf("Queue is overflow n");
    else
    {
        printf("Enter an element:");
        scanf("%d",&item);
        rear=rear+1;
        Queue[rear]=item;
        if(front==-1)
            front=0;
    }
}

void interLeaveQueue(int Queue[])
{
    int front1,front2;
    front1=front;
    front2=rear/2+1;
    int Q_inter[maxsize];
    for(int i=0;i<maxsize-1;i+=2)
    {
        Q_inter[i]=Queue[front1];
        Q_inter[i+1]=Queue[front2];
        front1++; front2++;
    }
    display(Q_inter);
}
void dequeue(){
    int i;
 
    for (i = 0;i <= count;i++){
        push2(pop1());
    }
    pop2();
    count--;
    for (i = 0;i <= count;i++){
        push1(pop2());
    }
}
void display1()
{
    int i;
    for (i = 0;i <= top1;i++){
        printf(" %d ", st1[i]);
    }
}
void peek1()
{    printf(" %d ",st1[0] ); }
void prog1()
{
    printf("\n PROGRAM 1\n");
    int ch;
    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Dequeu element from queue");
    printf("\n3 - Display from queue");
    printf("\n4 - Peek");
    printf("\n5 - Exit");
    create();
    while (1)
    {
        printf("\nEnter choice --> ");
        scanf("%d", &ch);
        if (ch==5)
            break;
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display1();
            break;
        case 4:
            peek1();
            break;
        default:
            printf("Wrong choice");
        } 
    }
    printf("\n");
}
int main()
{
    prog1();
    
    printf("\n PROGRAM 2\n");
    int Q[maxsize];
    printf("Enter the number of elements(even) : ");
    int n;
    scanf("%d",&n);
    if(n%2!=0){printf("Enter an even number.\n");return 0;}
    for(int i=0;i<n;i++)EnQueqe(Q);
    display(Q);
    interLeaveQueue(Q);
    printf("\n");

    
    return 0;
}