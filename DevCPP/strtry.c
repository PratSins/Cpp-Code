#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	char str[50];
	int i, l;
	int spe, alp, dig;
	spe=alp=dig=0;
	printf("enter a string\n");
	gets(str);
	//The following are also acceptable
	//           scanf("%s",&str);
	//           scanf("%s",str);
	l=strlen(str);
	
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i] >=65 && str[i]<=90)
		{   alp++; }
		else if(str[i] >=97 && str[i]<=122)
		{   alp++;  }
		else if(str[i] >=48 && str[i]<=57)
		{   dig++; }
		else if(str[i] != 32)
		{   spe++;  }
	}
	
	printf("Number of alphabets = %d \n",alp);
	printf("Number of digits = %d \n",dig);
	printf("Number of special characters = %d \n",spe);
	
	return 0;
}
