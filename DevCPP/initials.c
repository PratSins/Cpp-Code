#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	char str[50], c, in[10];
	int i, j=1,l;
	printf("enter a name\n");
	gets(str);
	l=strlen(str);
	in[0]=str[0];
	for(i=1,j=1;str[i]!='\0';i++)
	{
		if(str[i]==32)
		{
			in[j++]='.';
			in[j++]=str[i+1];
		}
	}
	for(i=l-1;;i--)
	{
		if(str[i==32])
		{
			in[j++]=str[i+1];
			in[j++]='.';
			break;
		}
	}
	
	printf("Initials of the name is %s",in);
	
	return 0;
}
