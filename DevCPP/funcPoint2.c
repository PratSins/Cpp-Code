#include <stdio.h>
#include <stdlib.h>
void swapNum(int *num1, int *num2)
{
	int tempnum;
	tempnum = *num1;
	*num1 = *num2;
	*num2 = tempnum;
}
int main(int argc, char **argv)
{
	int v1=11, v2=77;
	printf("Before Swapping\n");
	printf("Value of v1 is : %d", v1);
	printf("\nValue of v2 is : %d", v2);
	
	swapNum(&v1, &v2);
	
	printf("\n\nAfter Swapping\n");
	printf("Value of v1 is : %d", v1);
	printf("\nValue of v2 is : %d", v2);
	return 0;
}
