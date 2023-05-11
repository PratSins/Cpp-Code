#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	char str[50];
	int i, l;
	int flag=1;
	
	printf("enter a string\n");
	gets(str);
	l=strlen(str);
	
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=str[l-i-1])
		{
			flag=0;
			break;
		}
	}
	
	if(flag==1)
		printf("Pallindrome number");
    else
    	printf("Not a Pallindrome number");
	
	return 0;
}
