#include <stdio.h>

main()
{
	char str[50];
	int i, vc=0;
	printf("enter a string\n");
//	scanf("%str", &str);
//	printf("SCANF %s\n",str);
//	getch();
//	printf("enter a string\n");
	gets(str);
//	puts(str);
//    printf("%s",str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='O' || str[i]=='U' || str[i]=='E' || str[i]=='I')
		   vc++;
	}
	printf("Number of vowels : %d", vc);
}
