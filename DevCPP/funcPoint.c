#include <stdio.h>
#include <stdlib.h>
void salaryhike(int *var, int b)
{
	*var = *var + b;
}
int main(int argc, char **argv)
{
	int salary =0, bonus=0;
	printf("enter employee current salary : ");
	scanf("%d",&salary);
	printf("enter bonus: ");
	scanf("%d",&bonus);
	salaryhike(&salary, bonus);
	
	printf("Final Salary : %d",salary);
	
	return 0;
}
