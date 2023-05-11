#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *getReverse(char *str)
{
	int i, l;
	char *st;
	l=strlen(str);
    st = (char *) malloc(sizeof(char) * l);

	for(i=0;i<l;i++)
	{
		st[i]=str[l-i-1];
	}
	st[i]='\0';
	return st;
}
int main(int argc, char **argv)
{
	char str[500], *reverse;
	printf("Enter a string : ");
	gets(str);
	printf("\n");
	reverse = getReverse(str);
	printf("Reverse String is : ");
	puts(reverse);
	/*char str[500];
	printf("Enter a string : ");
	gets(str);
    char *ptr=str;
    printf("\n");
	ptr = getReverse(str);
	printf("Reverse String is : ");
	puts(ptr);*/
	return 0;
}
