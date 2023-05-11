#include <stdio.h>
#include <string.h>

int isPallin(char str[])
{
	int flag = 1;
	int i, l;
	l=strlen(str);
	
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=str[l-i-1])
		{
			flag=0;
			break;
		}
	}
	return flag;
}

int main(int argc, char **argv)
{
	char str[500], word[50];
	int i, l, j;
	int flag=1;
	j=0;
	printf("enter a string\n");
	gets(str);
	l=strlen(str);
	
	for(i=0;i<=l;i++)
	{
		if(str[i]!=32 && str[i]!='\0')
		{
			word[j]=str[i];
			j++;
		}
		else
		{
			word[j]='\0';
			if(isPallin(word)==1)
			{
				puts(word);
			}
			j=0;
			word[0]='\0';
		 
		}
	}
	
	return 0;
}
