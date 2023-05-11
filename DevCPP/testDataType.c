#include <stdio.h>
int main()
{
	int a= -3;
	a= -a-a+!a;
	printf("%d\n",a);
	a=2;
	int b=5, c,d;
	c=a<b;
	d=(a<b) && (c<b);
	printf("c = %d \nd = %d",c,d);
	int x=5;
	x = (100, 30, 50);
	printf("\nx=%d\n",x);
	
	return 0;
}
