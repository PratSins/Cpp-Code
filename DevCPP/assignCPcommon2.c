#include <stdio.h>

int main(int argc, char **argv)
{
	int i; float n; char ch, s[15];
	printf("Enter an integer:\n");
	scanf("%d",&i);
	printf("Enter a floating point literal:\n");
	scanf("%f",&n);
	//fflush(stdin);
	printf("Enter a character:\n");
	scanf("\n%c", &ch);
	fflush(stdin);
	printf("Enter a string with less than 15 characters:\n");
	gets(s);
	printf("\ninteger:%d\n",i);
	printf("float:%f\n",n);
	printf("character: %c \n", ch);
	printf("string:%s\n",s);
	
	
	return 0;
}
