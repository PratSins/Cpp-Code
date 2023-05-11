#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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

int binSqSrch(int n, int start, int last)
{
    int mid = (start + last) / 2;
    if (start > last){
       return -1;
    }
    if (mid * mid == n)
        return mid;
    else if (mid * mid > n)
        return binSqSrch(n, start, mid - 1);
    else
        return binSqSrch(n, mid + 1, last);
}
void bubbleSort(int arr[], int size)
{
    int i, j, t;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if( *(arr+j) > *(arr+j+1) )
            {
                t = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = t;
            }
        }
    }
}
void prog1()
{
    int n,element;
    printf("Enter the number of elements:\n -->");
    scanf("%d",&n);
    printf("Enter the  elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&element);
        enq(element);
    }
    printf("\n");
    display();
    printf("\n");
    consec(n);
}
void prog2()
{
    int n, key, k=0;
    printf("Enter the number of elements:\n -->");
    scanf("%d",&n);
    int arr[n];
    int ind[n];
    printf("Enter the  elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        ind[i] = -1;
    }
    printf("Enter the search key\n -->");
    scanf("%d",&key);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            ind[k]=i;
            k++;
        }
    }
    if(ind[0]== -1){
        printf("Search not found");
    }
    else{
        int count=0;
        printf("Positions of occurrence are\n");
        for(int i=0;i<n && ind[i]!=-1;i++)
        {
            printf("%d, ",ind[i]);
            count++;
        }
        printf("\n");
        printf("No. of occurrences = %d\n",count);
    }
}
void prog3()
{
    int n;
    printf("Enter n:\n -->");
    scanf("%d",&n);
    if(n>121)
    {
        printf("Number should be less than 11^2\n");
    }
    else{
        int k= binSqSrch(n, 0, 11);
        if(k!=-1)
        {
            printf("The input is a square of an integer.\n");
            printf("Square root of the input is < %d >\n",k);
        }
        else
            printf("NOT FOUND... SO NOT A PERFECT SQUARE");
    }
}
void prog4()
{
    int n, key;
    printf("Enter the number of elements:\n -->");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the  elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the search key\n -->");
    scanf("%d",&key);

    bubbleSort(arr,n);

    int start = 0, end = n -1;
    int ans = -1;
    int noc =0;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] < key) {
            start = mid + 1;
            noc++;
        }
        else {
            ans = mid;
            end = mid - 1;
        }
    }
    if(ans!=(-1))
        printf("The first element >= (INPUT SEARCH KEY) is %d at position < %d >\n", arr[ans],ans);
    else
        printf("NOT FOUND..\n");
    printf("No. of comparisons made in the process = %d\n",noc);

}
int main()
{
    printf("\n**PROGRAM 1**\n");
    prog1();
    printf("\n");

    printf("\n**PROGRAM 2**\n");
    prog2();
    printf("\n");

    printf("\n**PROGRAM 3**\n");
    prog3();
    printf("\n");

    printf("\n**PROGRAM 4**\n");
    prog4();
    printf("\n");
    return 0;
}