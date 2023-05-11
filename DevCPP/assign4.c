#include<stdio.h>

int main(int argc, char **argv)
{
	printf("PROGRAM 1\n");
	int radius;
	float ar=0.0f,per=0.0f;
	printf("\nEnter the radius of the circle in centimetres:");
	scanf("%d",&radius);
	ar=3.14*radius*radius;
	per=3.14*2*radius;
	printf("\nArea of the circle = %f sq.cm",ar);
	printf("\nPerimeter of the circle = %f cm",per);
	printf("\n\n");
	
	printf("PROGRAM 2\n");
	int sal, age;
	printf("\nEnter the salary(in $) and age(in Years):\n");
	scanf("%d",&sal);
	scanf("%d",&age);
	printf("\nSalary = %d USD",sal);
	printf("\nAge = %d yrs",age);
	printf("\n\n");
	
	printf("PROGRAM 3\n");
	int sum=0,n1,n2,n3;
	printf("\nEnter three numbers:\n");
	scanf("%d",&n1);
	scanf("%d",&n2);
	scanf("%d",&n3);
	sum = n1+n2+n3;
	printf("\nSum of the entered numbers = %d",sum);
	printf("\n\n");
	
	printf("PROGRAM 4\n");
	int a1=10, b1=7, d1=4, e1=2;
	float c1=15.75f, f1=5.6;
	float z = 0.0f;
	z= (a1*b1) + (c1/d1) - (e1*f1);
	printf("\nz=%f",z);
	printf("\n\n");
	
	printf("PROGRAM 5\n");
	int l, br, area,perimeter;
	printf("\nEnter the length and breadth of rectangle in cm:\n");
	scanf("%d",&l);
	scanf("%d",&br);
	area = l * br;
	perimeter=l+l+br+br;
	printf("\nArea of the rectangle = %d sq.cm",area);
	printf("\nPerimeter of the rectangle = %d cm",perimeter);
	printf("\n\n");
	
	printf("PROGRAM 6\n");
	int length, rad;
	float vol=0.0f;
	printf("\nEnter the length and radius of the cylinder (in cm):\n");
	scanf("%d",&length);
	scanf("%d",&rad);
	vol = 3.14*rad*rad*length;
	printf("\n Volume of the cylinder = %f cubic cm",vol);
	printf("\n\n");
	
	printf("PROGRAM 7\n");
	int bassal=12000, HRA = 150, TA = 120, oth=450;
	float DA = 0.12 * bassal, pf = 0.14 * bassal, it=0.15 * bassal;
	float netsal= bassal + DA + HRA + TA + oth - (pf + it);
	printf("\nNet Salary of the given employee = %f USD",netsal);
	printf("\n\n");
	
	printf("PROGRAM 8\n");
	int s, m=3, n=5, r, t;
	float x=3.0, y;
	t = n/m;
	r = n%m;
	y = n/m;
	t = x*y-m/2;
	x = x*2.0;
	s = (m+n)/r;
	y = --n;
	printf("\n m=%d, n=%d, t=%d, r=%d, s=%d, x=%f, y=%f",m,n,t,r,s,x,y);
	printf("\n\n");
	
	printf("PROGRAM 9\n");
	float cm;
	printf("\nEnter length in cm = ");
	scanf("%f",&cm);
	printf("\n %.2f centimeters is %.1f feet %.2f centimeters is %.1f inches",cm,(cm/(2.54*12)),cm,(cm/2.54));
	printf("\n\n");
	
	printf("PROGRAM 10\n");
	int iResult, a = 10, b = 8, c = 6, d = 5, e =2;
	iResult = a - b - c - d;
	printf("\niResult = %d",iResult);
	iResult = a - b + c - d;
	printf("\niResult = %d",iResult);
	iResult = a + b / c / d;
	printf("\niResult = %d",iResult);
	iResult = a + b / c * d;
	printf("\niResult = %d",iResult);
	iResult = a / b * c * d;
	printf("\niResult = %d",iResult);
	iResult = a % b / c * d;
	printf("\niResult = %d",iResult);
	iResult = a % b % c % d;
	printf("\niResult = %d",iResult);
	iResult = a - (b - c) - d;
	printf("\niResult = %d",iResult);
	iResult = (a - (b - c)) - d;
	printf("\niResult = %d",iResult);
	iResult = a - ((b - c) - d);
	printf("\niResult = %d",iResult);
	iResult = a % (b % c) * d * e;
	printf("\niResult = %d",iResult);
	iResult = a + (b - c) * d - e;
	printf("\niResult = %d",iResult);
	iResult = (a + b) * c + d * e;
	printf("\niResult = %d",iResult);
	iResult = (a + b) * (c / d) % e;
	printf("\niResult = %d",iResult);
	printf("\n\n");
	
	return 0;
}
