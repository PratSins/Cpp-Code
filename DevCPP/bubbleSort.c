#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int size, i,j, t;
    int *arr;
    printf("Enter the size of the array:\n");
    scanf("%d", &size);  
    arr = (int *) malloc(sizeof(int) * size);
    
    printf("Enter elements :\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    	
	for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if( *(arr+j) > *(arr+j+1) )
            {
                t = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = t;
            }
        }
    }
    
    printf("\n \nElements :\n");
    for (i = 0; i < size; i++) 
    { 
        printf("%d\n",*(arr+i));
    }
	
	return 0;
}
