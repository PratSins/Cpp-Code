#include <stdio.h>
#include <stdlib.h>
int *fun()
{
	static 	int a=9111;
	return (&a);
}
int main(int argc, char **argv)
{
	int *p;
	p = fun();
	printf("%u\n",p);
	printf("%d\n",*(p));
	
	
	return 0;
}
