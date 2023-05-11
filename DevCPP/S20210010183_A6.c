#include <stdio.h>
#include <string.h>
void prog1()
{
    char t[100], p[20];
    int n, pos[20], p1=0, tmp=0, flag=0;
    printf("Enter t[100]: \n -->");
    scanf("%s",t);
    printf("Enter p[20]: \n -->");
    scanf("\n%s",p);
    printf("Enter n: \n -->");
    scanf("%d",&n);
    if(n>strlen(t) || n<1){
        printf("\nWrong input..\n");
        return;
    }
    int a[n];
    printf("Enter array elements with natural numbers:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<1)
        {
            printf("\nWrong input..\n");
            return;
        }
    }
    for(int i=0;t[i]!='\0';i++)
    {
        if(p[p1]==t[i])
        {
            pos[p1]=i;
            p1++;
        }
    }
    if(p1!=strlen(p)){
        printf("\nWrong input..\n");
        return;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=p1;j++)
        {
            if(a[i]==pos[j]+1)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
        if(a[i]<=strlen(t))
            tmp++;
    }
    printf("\nOUTPUT ----> %d \n",tmp);
}
void prog2()
{
    char s[100];
    int m=0;
    printf("Enter string s[100]: \n -->");
    scanf("\n%s",s);
    printf("Enter no. of queries: \n -->");
    scanf("%d",&m);

    printf("Enter the queries : \n");
    while(m-- >0)
    {
        int i, j, k;
        scanf("%d %d %d",&i,&j,&k);
        while(k-- > 0)
        {
            char t = s[j-1];
            for(int x = j-1; x>=i; x--)
            {
                s[x] = s[x -1];
            }
            s[i-1]=t;
        }
    }
    printf("OUTPUT  --> %s",s);
}
int main()
{
    printf("\n PROGRAM 1\n");
    prog1();
    printf("\n");

    printf("\n PROGRAM 2\n");
    prog2();
    printf("\n");

    return 0;
}