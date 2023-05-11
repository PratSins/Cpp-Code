#include <stdio.h>
//ASSIGNMENT CP COMMON ROOM - 17/1/2022
int main()
{
    printf("\n PROGRAM 1\n");
    char ch;
    int num=0, sum=0, isneg=0; 
    printf("Enter the string:\n  ->");
    do
    {
        scanf("%c",&ch);  
        if('0'<=ch && ch<='9')
        {
            num = num*10+(ch-'0');  
            continue;
        }
        else if(isneg==1 && num==0)
        {isneg=0;}
        else{ 
            if(isneg==1)
            {
                num=num*(-1);
                isneg=0;
            } 
            sum = sum+num;
            num=0;
        }
        if(ch=='-')
        { isneg=1; }
    }while(ch!=10);  
    sum = sum+num;
    printf("Sum = %d \n",sum);
    printf("\n");

    printf("\n PROGRAM 2\n");
    ch=0;
    num=sum=isneg=0;
    printf("Enter the string:\n  ->");
    do
    {
        scanf("%c",&ch);
        if('0'<=ch && ch<='9')
        {
            num = num*10+(ch-'0');  
            continue;
        }
        else if(isneg==1 && num==0)
        {isneg=0;}
        else{ 
            if(isneg==1)
            {
                num=0;
                isneg=0;
            } 
            sum = sum+num;
            num=0;
        }
        if(ch=='-')
        { isneg=1; }
    }while(ch!=10);  
    sum = sum+num;
    printf("Sum = %d \n",sum);
    printf("\n");

    printf("\n PROGRAM 3\n");
    ch=0;
    num=sum=isneg=0;
    int k,tk;
    k=tk=0;
    printf("Enter k: ");
    scanf("%d",&k);
    fflush(stdin);
    printf("Enter the string:\n  ->");
    do
    {
        scanf("%c",&ch);  
        if('0'<=ch && ch<='9')
        {
            num = num*10+(ch-'0');  
            continue;
        }
        else if(isneg==1 && num==0)
            {isneg=0;}
        else{ 
            if(isneg==1)
            {
                num=num*(-1);
                isneg=0;
            } 
            if(num==(-1))
            {
                tk++;
            }
            if(tk==k)
              {  break;}
            sum = sum+num;
            num=0;
        }
		if(ch=='-')
        { isneg=1; }
    }while(ch!=10);  
    sum = sum+num;
    printf("Sum = %d \n",sum);
    printf("\n");

    printf("\n PROGRAM 4\n");
    fflush(stdin);
    ch=0;
    tk=num=sum=isneg=0;
    printf("Enter the string:\n  ->");
    do
    {
        scanf("%c",&ch);  
        if('0'<=ch && ch<='9')
        {
            num = num*10+(ch-'0');  
            continue;
        }
        else if(isneg==1 && num==0)
        {isneg=0;}
        else{ 
            if(isneg==1)
            {
                num=num*(-1);
                isneg=0;
            } 
            if(num==(-1))
            { tk++;}
			if(tk==2 && num==(-1))
			{ break;}
			else if(tk==1 && num!=(-1))
			{ tk=0;}
            sum = sum+num;
            num=0;
        }
		if(ch=='-')
        {isneg=1;}
    }while(ch!=10);  
    sum = sum+num;
    printf("Sum = %d \n",sum);
    return 0;
}