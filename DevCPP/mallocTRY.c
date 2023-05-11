#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int size, i ;
    int *arr1;
    printf("Enter the size of the array:\n");
    scanf("%d", &size);  
    arr1 = (int *) malloc(sizeof(int) * size);
    
    printf("Enter elements :\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr1[i]);
        //scanf("%d", (arr1+i));
    }
    
    printf("\n \nElements :\n");
    for (i = 0; i < size; i++) 
    { 
        printf("%d\n",*(arr1+i));
       // arr1++;
    }
    
    free(arr1);
    //deallocates the memory previously allocated
	//by a call to calloc/malloc/realloc
	return 0;
}

