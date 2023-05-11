#include <stdio.h>

int main(int argc, char **argv)
{
	
	int arr1[5], arr2[5],arr3[5], i, j,t=0;
	printf("Enter Elements of array 1:\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&arr1[i]);
	}
	
	printf("\nEnter Elements of array 2:\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&arr2[i]);
	}
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(arr1[i]==arr2[j])
			{
				arr3[t++]=arr1[i];
				
			}
		}
	}
	
	
	return 0;
}
