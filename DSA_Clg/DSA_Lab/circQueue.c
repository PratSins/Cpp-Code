#include<stdio.h>
#include<stdlib.h>

#define qsize 100
int circq[qsize],fr=-1,rr=-1;

int isFull(){
    if (fr==rr+1 || (fr==0 && rr==qsize-1))
        return 1;
    else
        return 0; 
}
int isEmp(){
    if(fr==-1)
       return 1;
    else 
        return 0;
}
void enq(int element)
{
    if(isFull()==1) 
        printf("queue is full ! no element added !\n");
    else
    {
        if(fr==-1) 
            fr=0;
        rr=(rr+1)%qsize;
        circq[rr]=element;
    }
    
}
int deq()
{
    if(isEmp()==1) 
        printf("No element in queue to dequeue");
    else
    {
        int element=circq[fr];
        if(fr==rr)
        {
            fr=-1;
            rr=-1;
        }
        else{
            fr=(fr+1)%qsize;
        }
        return element;
    }
}

void display()
{
    if(isEmp()==1) 
        printf("Queue is empty\n");
    else
    {
       int i=fr;
       printf("Elements in queue are\n");
       while (i!=rr)
       {
           printf("%d ",circq[i]);
           i=(i+1)%qsize;
       }
       printf("%d\n",circq[i]);
       
        
    } 
}
void consec(int arr_qsize)
{
    int i=fr;
    int count=0;
    while (i!=rr)
    {
        if(circq[i]==circq[i+1]+1 ||circq[i]==circq[i+1]-1){
            printf("(%d,%d) ",circq[i],circq[i+1]);
            count++;
        }
        i=(i+1)%qsize;
    }
    if(circq[fr]==circq[rr]+1 || circq[fr]==circq[rr]-1) 
    {
        printf("(%d,%d)",circq[fr],circq[rr]); 
        count++;
    }
    printf("\nTotal no. of consecutive pairs is %d\n",count);
}

int main()
{
    int n,element;
    printf("Enter total no. of elments in queue ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter elment no. %d ",i+1);
        scanf("%d",&element);
        enq(element);
    }
    display();
    consec(n);
}