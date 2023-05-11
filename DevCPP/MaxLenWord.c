#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	char words[100][100], sent[500];
	int i, j, l,k,max,maxpos=0;
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
	max=strlen(words[0]);
	
	for(i=1;i<=j;i++)
	{
		if(strlen(words[i])>max)
		{
			max=strlen(words[i]);
			maxpos=i;
		}
	}
	printf("Largest word = ");
	puts(words[maxpos]);
	return 0;
}
