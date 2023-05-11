#include <stdio.h>

int rec(int n, int k)
{
	if(k>n)
		return 0;
	if ( (k==1) || (k==n))
		return 1;
	return rec(n-1,k-1+ k*rec(n-1,k));
}
int main()
{
	printf("%d",rec(5,3));
	return 0;
}
