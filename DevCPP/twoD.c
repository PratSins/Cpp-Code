#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	char words[100][100], sent[500];
	int i, j, l,k;
	int flag=1;
	printf("enter a string\n");
	gets(sent);
	l=strlen(sent);
    k=j=0;
	for(i=0;i<l;i++)
	{
		if(sent[i]!=32 && sent[i]!='\0')
		{
			words[j][k++]=sent[i];
		}
		else
		{
			words[j][k]='\0';
			j++;
			k=0;
		}
	}
	
	for(i=0;i<=j;i++)
	{
		puts(words[i]);
	}
	
	return 0;
}
