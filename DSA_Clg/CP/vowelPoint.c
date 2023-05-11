#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int size, i,c;
    char *arr, t;
	printf("Enter the size of the array:\n");
    scanf("%d", &size);  
    arr = (char *) malloc(sizeof(char) * size);
    
    fflush(stdin);
    c=0;
	printf("Enter a string\n");
	gets(arr);
	for(i=0;*(arr+i)!='\0';i++)
	{
		t = *(arr+i);
		if (t=='a' || t=='e' ||t=='i' ||t=='o' ||t=='u' ||t=='A' ||t=='E' ||t=='I' ||t=='O' ||t=='U')
		{
			c++;
		}
	}
	
	printf("\nNumber of vowels in the string : %d",c);
	
	return 0;
}
