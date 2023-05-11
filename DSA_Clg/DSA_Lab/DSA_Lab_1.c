#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int isLeapYr(int y)
{
    if(y%100==0)
    {
        if(y%400==0)
            return 1;
    }
    else if(y%4==0)
        return 1;

    return 0;
}
void prog1()
{
    unsigned int d, m, y;
    printf("\nEnter date DD MM YYYY :\n");
    scanf("%d",&d);
    scanf("%d",&m);
    scanf("%d",&y);
    if(d>=1 && d<=27)
        d++;
    else if(m==4 || m==6 || m==9 || m==11)
    {
        if(d>=30)
        {
            d=1;
            m++;
        }
        else
            d++;
    }
    else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10)
    {
        if(d>=31)
        {
            d=1;
            m++;
        }
        else
            d++;
    }
    else if(m==12)
    {
        if(d>=31)
        {
            d=1;
            m=1;
            y++;
        }
        else
            d++;
    }
    else if (m==2)
    {
        int k;
        if(isLeapYr(y))
            k=29;
        else 
            k=28;
        
        if(d>=k)
        {
            d=1;
            m++;
        }
        else 
        d++;
    }
    printf("New Date is: %2d %2d %4d", d,m,y);
}

int linSearch(int a[], int n, int key) // PROGRAM 2
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
int duplicates(int a[], int n) // PROGRAM 2
{
    int flags[n];
    int f;
    for(int i=0; i<n-1;i++)
    {
        if(flags[i]!=1 && flags[i]!=2)
        {
            for(int j=i+1 ; j<n ;j++)
            {
                if(a[i]==a[j])
                {  
                   flags[i]=1;
                   flags[j]=2;
                }
            }
            
        }
    }
    f=0;
    for(int i=0;i<n;i++)
    {
        if(flags[i]==1)
            f++;
    }
    return f;
}
int main()
{
    printf("\n PROGRAM 1\n");
    prog1();
    printf("\n");

    printf("\n PROGRAM 2\n");
    int a1[]={ 2,4,5,2,4,8,99};
    printf("Lin = %d \n",linSearch(a1,7,2));
    printf("Lin = %d \n",linSearch(a1,7,22));
    printf("dup = %d",duplicates(a1,7));
    printf("\n");

    
    printf("\nQuestion 3\n");

    printf("2A\n");
    FILE *fileptr;
    fileptr = fopen("time1.csv", "w");
    for (int i = 1; i < 10000; i++)
    {
        clock_t time_t1;
        int a[i];
        time_t1 = clock();
        for (int k = 0; k < i; ++k)
        {
            a[k] = k;
        }
        linSearch(a, i, -1);
        time_t1 = clock() - time_t1;
        printf("%d ",i);
        fprintf(fileptr, "%lf\n", ((double)time_t1)/ CLOCKS_PER_SEC);
    }
    printf("\nend\n ");

    printf("2B\n");
    FILE *fileptr2;
    fileptr2 = fopen("time2.csv", "w");
    for (int i = 1; i < 10000; i++)
    {
        clock_t time_t1;
        int a[i];
        time_t1 = clock();
        for (int k = 0; k < i; ++k)
        {
            a[k] = k;
        }
        duplicates(a, i);
        time_t1 = clock() - time_t1;
        printf("%d ",i);
        fprintf(fileptr2, "%lf\n", ((double)time_t1)/ CLOCKS_PER_SEC);
    }
    printf("\nend\n");
    return 0;
}