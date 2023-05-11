#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertionSort(char s[][100],int n)
{
    int j, i;
    char key[100];
    for (i = 1; i < n; i++)
    {
        strcpy(key, s[i]);

        for (j = i; strcmpi(s[j - 1], key) > 0 && j > 0; j--);

        memcpy(&s[j + 1], &s[j], (i - j) * 100);
        strcpy(s[j], key);
    }
}
int bubbleSort(int a[], int n)
{
    int i, j, t;
    int count = 0;
    int flag;

    for(i=0;i<n-1;i++)
    {
        flag = 0;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                count++;
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                flag = 1;
            }
        }
        if(!flag)
            break;
    }
    return count;
}
void displayBooks(char a[][100], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%s,  ",a[i]);
    }
    printf("\n");
}
void displayArr(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d,  ",a[i]);
    }
    printf("\n");
}
int max(int a,int b)
{
    if (a>b)
        return a;
    return b;
}
void prog4()
{
    int n, k, s=0;

    printf("Enter the value of N and K: ");
    scanf("%d %d",&n,&k);

    int arr[n];
    printf("\nEnter the elements: ");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for (int i=0;i<k;i++){
        s += arr[i];
    }

    int mtn = s; // max_till_now
    int ch;
    for (int i=0; i < (k-1); i++)
    {
        s = s - arr[k-1-i] + arr[n-i-1];
        ch = max(mtn,s);
        mtn = ch;
    }
    printf("\n OUTPUT = %d\n",mtn);
}
int main()
{
    printf("\n PROGRAM 1\n");
    char books[][100]={"AHURA", "CASTHA", "BANDARA",  "GOOSEBUMPS", "INDIANA", "JONAS", "PRIYANKA", "QUORA","FLING", "ZOROASTER"};
    int n=sizeof(books)/sizeof(books[0]);

    //------Insertion sort---- will take the Minimum time

    printf("List before sorting:\n");
    displayBooks(books,n);

    InsertionSort(books,n);

    printf("\nList After sorting:\n");
    displayBooks(books,n);
    printf("\n");

    printf("\n PROGRAM 2\n");
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int k = bubbleSort(arr,n);
    displayArr(arr,n);
    printf("Number of swaps done = %d\n",k);
    printf("\n");

    printf("\n PROGRAM 3\n");
    int t, x;
    printf("Enter the number of TRIALS: ");
    scanf("%d",&t);
    for(int j = 1; j <= t; j++)
    {
        printf("TRIAL %d\n",j);
        printf("N = ");
        scanf("%d",&n);
        printf("X = ");
        scanf("%d",&x);
        int arr1[n];
        printf("Enter the elements:\n");
        int j, k=0, arrel;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arrel);
            for( j=0;j<k;j++){
                if(arrel==arr1[j])
                    break;
            }
            if(j==k){
                arr1[k]=arrel;
                k++;
            }
        }
        if(k==x)
            printf("Good\n\n");
        else if(k>x)
            printf("Average\n\n");
        else if(k<x)
            printf("Bad\n\n");
    }
    printf("\n");

    printf("\n PROGRAM 4\n");
    prog4();
    printf("\n");
    return 0;
}