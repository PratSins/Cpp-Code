#include <stdio.h>

int main(int argc, char **argv)
{
	//PROGRAM 1
	printf("*****************************************************\n");
	printf("Name:\tPratyush Singh\n");
	printf("Roll Number:\tS20210010183\n");
	printf("Branch:\tComputer Science and Engineeering\n");
	printf("*****************************************************\n");

	//PROGRAM 2
	int dist=0,cm=0;;
	printf("\nEnter a distance in metres:\t");
	scanf("%d",&dist);
	cm = dist * 100;
	printf("Distance in centimetres:\t%d\n",cm);
	
	//PROGRAM 3
	int l=0, w=0, area=0;;
	printf("\nEnter length and width of the rectangle:\n");
	scanf("%d",&l);
	scanf("%d",&w);
	area=l*w;
	printf("Area of the rectangle is %d",area);
	
	//PROGRAM 4
	float a,b,res=0;
	short ch;
	printf("\n\nChoose Operation: \n1.Addition\n2.Substraction\n3.Multiplication\n4.Division\n5.Modulus\n");
	scanf("%d",&ch);
	printf("Enter 2 numbers:\n");
	scanf("%f",&a);
	scanf("%f",&b);
	if(ch==1)
		res=a+b;
	else if(ch==2)
		res=a-b;
	else if(ch==3)
		res=a*b;
	else if(ch==4)
		res=a/b;
	else if(ch==5)
		res=(int)a % (int)b;
	else
	    printf("\nWrong choice...\n");
	
	printf("\nResult = %f\n",res);
	
	//PROGRAM 5
	int x,y,z;
	float s=0.0f;
	printf("\nEnter x, y, z:\n");
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);
	
	s= (((((2*x) + (4*y))/2) + 3)*z)- (((4*z)-(6*y))*x)/2;
	printf("\nResult = %f\n",s);
	return 0;
}
