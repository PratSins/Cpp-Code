#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char str[500], word[50];
	int c=0;
	char *p;
	int flag=1;
	printf("enter a string\n");
	gets(str);
	p=str;
	while(*p!='\0')
	{
		if (*p=='a' || *p=='e' ||*p=='i' ||*p=='o' ||*p=='u' ||*p=='A' ||*p=='E' ||*p=='I' ||*p=='O' ||*p=='U')
		{
			c++;
		}
		p++;
	}
	printf("\nNumber of vowels in the string : %d",c);
	
	return 0;
}
