#include <stdio.h>
#include <stdlib.h>

int *getReverse(int *arr, int l)
{
	int i;
	int *rev;
    rev = (int *) malloc(sizeof(int) * l);
	
	for(i=0;i<l;i++)
	{
		rev[i]=arr[l-i-1];
	}
	return rev;
}
int main()
{
	int arr[5], *reverse, i;
	printf("Enter elements of the Array :\n");
	for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
	reverse = getReverse(arr,5);
	
	printf("\n\nReversed Elements :\n");
	for (i = 0; i < 5; i++) 
    { 
        printf("%d\n",*(reverse+i));
    }
	return 0;
}
