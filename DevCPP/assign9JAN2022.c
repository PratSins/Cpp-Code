#include <stdio.h>
#include <math.h>
int main()
{
    printf("\nPROGRAM 1\n");
    int sum;
    float discount_rate;
    printf("Welcome\n");
    printf("Enter a integer :\n");
    scanf("%d",&sum);
    printf("Enter a floating type number:\n");
    scanf("%f",&discount_rate);
    printf("Integer var = %d \n",sum);
    printf("Floating-point var = %.2f \n",discount_rate);
    printf("\n");

    printf("\nPROGRAM 2\n");
    char ch1='A', ch2='b';
    printf("ASCII value of ch1 = %d and ch2 = %d \n",ch1,ch2);
    printf("\n");

    printf("\nPROGRAM 3\n");
    printf("\nEnter an integer and 2 floating numberals \n");
    int breadth;
    float length, height;
    scanf("\n%d %f %f",&breadth,&length,&height);
    printf("%d %f %e",breadth, length, height);
    printf("\n");

    printf("\nPROGRAM 4\n");
    char name[50];
    int basic, daper, bonper, loandet;
    float salary;
    printf("Enter the Name of the employee : ");
    fflush(stdin);
    gets(name);
    printf("Enter the basic salary of the employee in USD : ");
    scanf("%d",&basic);
    printf("Enter percentage of DA and percentage of bonus :\n");
    scanf("%d %d",&daper,&bonper);
    printf("Enter loan debited in USD:");
    scanf("%d",&loandet);
    salary = basic + basic * daper/100.0 +bonper * basic/100.0 - loandet;
    printf("Name of the employee : %s \n",name);
    printf("The salary of the the employee is $%.0f \n",salary);
    printf("\n");

    printf("\nPROGRAM 5\n");
    char name1[25] , name2[25];
    printf("\nEnter a first name and last name : \n");
    fflush(stdin);
    scanf("%s %s",&name1, &name2);
    printf("\n THE NAME IS : %s %s \n",name2, name1);
    printf("\n");

    printf("\nPROGRAM 6\n");
    int a, b;
    printf("\nEnter no.s a and b : \n");
    scanf("%d %d",&a, &b);
    if(a%b==0)
        printf("%d is divisible by %d",a,b);
    else
        printf("%d is not divisible by %d",a,b);
    printf("\n");

    printf("\nPROGRAM 7\n");
    int a1, b1, prod=0;
    printf("\nEnter no.s a and b : \n");
    scanf("%d %d",&a1, &b1);
    prod = a1 * b1;
    printf("The product of the entered numbers is %d \n",prod);
    if(prod>1000)
        printf("Product of the entered numbers is greater than 1000");
    else if(prod<1000)
        printf("Product of the entered numbers is less than 1000");
    else
        printf("Product of the entered numbers is equal to 1000");
    printf("\n");

    printf("\nPROGRAM 8\n");
    int a2, b2, diff=0;
    printf("\nEnter no.s a and b : \n");
    scanf("%d %d",&a2, &b2);
    diff = abs(a2-b2);
    printf("The difference between the entered numbers is %d \n",diff);
    if (diff == a2)
        printf("Difference is equal to value %d \n",a2);
    else if (diff == b2)
        printf("Difference is equal to value %d \n",b2);
    else
        printf("Difference is not equal to any of the values entered");
    printf("\n");

    printf("\nPROGRAM 9\n");
    int sal;
    char gr;
    printf("Enter the salary (in USD) and grade of the employee :\n");
    scanf("%d",&sal);
    scanf("\n%c",&gr);
    if(gr=='a' || gr=='A')
        sal+=300;
    else if(gr == 'b' || gr=='B')
        sal+=250;
    else 
        sal+=100;
    printf("The salary of the employee with the allowance is $%d \n",sal);
    printf("\n");

    printf("\nPROGRAM 10\n");
    int marks;
    char grc='F';
    printf("Enter marks :\n");
    scanf("%d",&marks);
    if(marks>75)
        grc='A';
    else if(marks>60)
        grc='B';
    else if(marks>45)
        grc='C';
    else if(marks>35)
        grc='D';
    else if(marks>0)
        grc='E';
    printf("Grade of the student is %c \n",grc);
    printf("\n");

    printf("\nPROGRAM 11\n");
    int x, y;
    printf("Enter decimal no.s x and y respectively :\n");
    scanf("%d %d",&x,&y);
    if(x<2000 || x>3000)
        printf("x=%d \n",x);
    if(y>100 && y<500)
        printf("y=%d \n",y);
    printf("\n");

    printf("\nPROGRAM 12\n");
    printf("100");
    for(int i=100;i>5;)
    {
        i-=5;
        printf(", %d",i);
    }
    printf("\n");

    printf("\nPROGRAM 13\n");
    int tp=0,num1,num2;
    printf("Enter two positive numbers :\n");
    scanf("%d %d",&num1,&num2);
    if(num1>num2)
    {
        tp=num1;
        num1=num2;
        num2=tp;
    }
    tp=0;
    for(int i=num1;i<=num2;i++)
    {
        if(i%2!=0)
            tp+=i;
    }
    printf("Sum of all odd no.s between the entered no.s is %d \n",tp);
    printf("\n");

    printf("\nPROGRAM 14\n");
    int f=1,s=1,t,nt;
	printf("Enter the number of terms >2 :\n");
	scanf("%d",&nt);
	nt-=2;
	printf("\n %d, %d",f,s);
	while(nt>0)
	{
		t=s+f;
		printf(", %d",t);
		f=s;
		s=t;
		nt--;
	}
    printf("\n");

    printf("\nPROGRAM 15\n");
    int size;
    printf("Enter the size of the patterns :\n");
    scanf("%d",&size);
    printf("\nPATTERN A :\n");
    for(int i=1;i<=size;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
    printf("\nPATTERN B :\n");
    for(int i=size;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
    printf("\n");

    printf("\nPROGRAM 16\n");
    printf("Enter the size of the patterns :\n");
    scanf("%d",&size);
    printf("\nPATTERN :\n");
    for(int i=1;i<=size;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}