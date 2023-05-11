#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vowelCount(char *a)
{
	int c=0,t,i;
	for(i=0;*(a+i)!='\0';i++)
	{
		t = *(a+i);
		if (t=='a' || t=='e' ||t=='i' ||t=='o' ||t=='u' ||t=='A' ||t=='E' ||t=='I' ||t=='O' ||t=='U')
		{
			c++;
		}
	}
	return c;
}

int main()
{
	int size, c=0;
    char *arr;
    
	printf("Enter the size of the array:\n");
    scanf("%d", &size);  
    
    arr = (char *) malloc(sizeof(char) * size);
    fflush(stdin);
    
	printf("Enter a string\n");
	gets(arr);
	
	c=vowelCount(arr);
	printf("\nNumber of vowels in the string : %d",c);
	
	return 0;
}
