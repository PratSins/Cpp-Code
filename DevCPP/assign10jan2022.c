#include <stdio.h>

int main()
{
    printf("\n PROGRAM 1\n");
    char ch;
    printf("Enter an alphabet :\n");
    scanf("%c", &ch);
    if((ch>=65 && ch<=90) || (ch>=97 && ch<=122))
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='O' || ch=='U' || ch=='E' || ch=='I')
            printf("\nIts a vowel\n");
        else
            printf("\nIts a consonant \n");
    }
    else
        printf("\nIts not an alphabet..\n");
    printf("\n");

    printf("\n PROGRAM 2\n");
    short t;
    printf("Enter Hour of the Day:\n");
    scanf("%d",&t);
    if(t <= 4)
        printf("Hi, Sleepy Head..\n");
    else if (t<=10)
        printf("Hello, Sunny morning.. \n");
    else if(t<=16)
        printf("Good afternoon..\n");
    else if(t<=19)
        printf("Good evening..\n");
    else if(t<=22)
        printf("Good night..\n");
    else if(t<=24)
        printf("Hi, Sleepy Head..\n"); 
    else
        printf("WRONG TIME FORMAT...\n");
    printf("\n");

    printf("\n PROGRAM 3\n");
    short a,b,c,d=0;
    printf("Enter the coefficients of the quadratic eqn. :\n");
    scanf("%hd",&a);
    scanf("%hd",&b);
    scanf("%hd",&c);
    d= (b*b) - (4*a*c);
	printf("\n Discriminant= %hd\n",d);
    if(d < 0)
        printf("The roots are imaginary\n");
    else 
        printf("The roots are real\n");
    printf("\n");

    printf("\n PROGRAM 4\n");
    int m1,m2,m3,m4,m5, tot=0,avg=0;
    char grade;
    printf("Enter the marks scored in the 5 subjects :\n");
    scanf("%d",&m1);
    scanf("%d",&m2);
    scanf("%d",&m3);
    scanf("%d",&m4);
    scanf("%d",&m5);
    tot = m1+m2+m3+m4+m5;
    avg = tot/5;
    printf("The total score of the student is : %d \n",tot);
    printf("The avg. score of the student is : %d \n",avg);
    avg = avg/10;
    switch(avg)
    {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        case 5:
            grade = 'E';
            break;
        default:
            grade = 'F';
    }
    printf("\n The grade of the student is : %c \n",grade);
    printf("\n");

    printf("\n PROGRAM 5\n");
    float km, fr=0.0f;
    printf("Enter distance travelled by the taxi in KMs :\n");
    scanf("%f",&km);
    if(km<=12.0)
        fr = 100.0f;
    else if(km<=16.0)
        fr = 100 + 8.0*( km - 12.0 );
    else if(km <= 20.0)
        fr = 100 + 8.0*4.0 + 6.0*( km - 16.0 );
    else if(km>20.0)
        fr = 100 + 8.0*4.0 + 6.0*4.0 + 5.0*( km - 20.0 );
    printf("\n The taxi fare is = %.2f\n",fr);
    printf("\n");
    return 0;
}