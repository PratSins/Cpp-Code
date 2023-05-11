#include <stdio.h>
#include <math.h>
char numw[][6]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int getReverse(int n)
{
    int rev=0;
    while(n>0){
        rev=rev*10+(n%10);
        n/=10;
    }
    return rev;
}
int isStrong(int n)
{
    int i,f=1,sum=0,m=n,d;
    while(m>0)
    {
        f=1;
        d=m%10;
        for(i=1;i<=d;f*=i,i++);
        sum+=f;
        m/=10;
    }
    if(sum==n)
        return 1;
    return 0;
}
int isPerfect(int n)
{
    int sum=0,i=1;
    while(i<n){
        if(n%i==0)
            sum=sum+i;
        i++;
    }
    if(sum==n)
        return 1;
    return 0;
}
int isArmstrong(int n)
{
    int s=0,m=n,d,c=0;
    c= (int)log10(m) +1;
    while(m>0)
    {
        d=m%10;
        s=s+pow(d,c);
        m/=10;
    }
    if(s==n)
        return 1;
    return 0;
}
void prmFact(int n)
{
    int i=2;
    while(n>1)
    {
        if(n%i==0){
            printf("%d, ",i);
			n/=i;
		}
        else{
            i++;
        }
    }
}
int isPrime(int n)
{
    if(n==1)
        return 0;
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
int getHCF(int a, int b)
{
    int hcf=1;
    int small=a>b?b:a;
    if(a%small==0 && b%small==0)
        return small;
    for(int i=2;i<small;i++)
    {
        if(a%i==0 && b%i==0)
            hcf=i;
    }
    return hcf;
}
void numToWords(int n)
{
    if(n>0)
    {
        numToWords(n/10);
        printf("%s ",numw[n%10]);
    }
}
void prog18()
{
    int n,m,c=0;
    printf("Enter a natural no.:\n ->");
    fflush(stdin);
    scanf("%d",&n);
    for(int i=0;i<=9;i++)
    {
        m=n;
        c=0;
        while(m>0){
            if((m%10)==i)
                c++;
            m/=10;
        }
        printf("%d --> %d \n",i,c);
    }
}
void prog13()
{
    int n,ld,fd,m,k=1;
    printf("Enter n (n > 9):\n ->");
    scanf("%d",&n);
    if(n<10)
        printf("WRONG INPUT..\n.....\n");
    else {
        ld=n%10;
        m=n;
        while(m>10){
            m/=10;
        }
        fd=m;
        n/=10;
        while(n>10){
            m=(int)(n%10)*pow(10,k) + m;
            k++;
            n/=10;
        }
        m=(int)(ld)*pow(10,k) + m;
        printf("The new number is : %d \n",m);
    }
}
void prog48(int a, int b, int c)
{
    float root1, root2, imaginary;
    int discriminant;
    discriminant = (b * b) - (4 * a * c);
    switch(discriminant > 0)
    {
        case 1:
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b - sqrt(discriminant)) / (2 * a);

            printf("Two distinct and real roots exists: %.2f and %.2f", root1, root2);
            break;

        case 0:
            switch(discriminant < 0)
            {
                case 1:
                    root1 = root2 = -b / (2 * a);
                    imaginary = sqrt(-discriminant) / (2 * a);
                    printf("Two distinct complex roots exists: %.2f + i%.2f and %.2f - i%.2f", root1, imaginary, root2, imaginary);
                    break;
                case 0:
                    root1 = root2 = -b / (2 * a);
                    printf("Two equal and real roots exists: %.2f and %.2f", root1, root2);
                    break;
            }
    }
}
int main()
{
    printf("\nPROGRAM 1\n");
    int i=1,n;
    printf("Enter n:\n ->");
    scanf("%d",&n);
    printf("Natural Number till n are\n 1");
    while(++i<=n){
        printf(",%d",i);
    }
    printf("\n");

    printf("\nPROGRAM 2\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    i=n;
    printf("Natural Number from n are\n %d",i);
    while(--i>=1){
        printf(",%d",i);
    }
    printf("\n");

    printf("\nPROGRAM 3\n");
    char ch='a';
    printf("\n %c",ch);
    while(++ch<='z'){
        printf(",%c",ch);
    }
    printf("\n");

    printf("\nPROGRAM 4\n");
    i=2;
    printf("\n %d",i);
    while(i<100){
        i+=2;
        printf(",%d",i);
    }
    printf("\n");

    printf("\nPROGRAM 5\n");
    printf("1");
    for(i=3;i<=99;i+=2){
        printf(",%d",i);
    }
    printf("\n");

    printf("\nPROGRAM 6\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    int sum=0;
    for(i=1;i<=n;sum+=i,i++);
    printf("Sum of no.s till n = %d",sum);
    printf("\n");

    printf("\nPROGRAM 7\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    sum=0;
    for(i=2;i<=n;sum+=i,i+=2);
    printf("Sum of even no.s till n = %d",sum);
    printf("\n");

    printf("\nPROGRAM 8\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    sum=0;
    for(i=1;i<=n;sum+=i,i+=2);
    printf("Sum of odd no.s till n = %d",sum);
    printf("\n");

    printf("\nPROGRAM 9\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    printf("  MULTIPLICATION TABLE OF %d \n",n);
    for(i=1;i<=10;i++)
    {
        printf("    %d * %d  =  %d \n",n,i,n*i);
    }
    printf("\n");

    printf("\nPROGRAM 10\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    i=0;
    while(n>0){
        i++;
        n/=10;
    }
    printf("Number of digits of n = %d \n",i);
    printf("\n");

    printf("\nPROGRAM 11\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    int fd=0,ld=0;
    if(n<0)
        printf("WRONG INPUT..\n.....\n");
    else if(n>10){
        ld=n%10;
        while(n>10){
            n/=10;
        }
        fd=n;
        printf("1st digit is %d and last digit is %d \n",fd,ld);
    }
    else
        printf("Last and first digit are the same = %d \n",n);
    printf("\n");

    printf("\nPROGRAM 12\n");
    printf("Enter n (n > 9):\n ->");
    scanf("%d",&n);
    if(n<10)
        printf("WRONG INPUT..\n.....\n");
    else {
        ld=n%10;
        while(n>10){
            n/=10;
        }
        fd=n;
        sum =ld+fd;
        printf("Sum of first and last digits = %d \n",sum);
    }
    printf("\n");

    printf("\nPROGRAM 13\n");
    prog13();
    printf("\n");

    printf("\nPROGRAM 14\n");
    sum=0;
    printf("Enter n:\n -->");
    scanf("%d",&n);
    while(n>0){
        sum=sum+(n%10);
        n/=10;
    }
    printf("The sum of the digits of the number is %d \n",sum);
    printf("\n");

    printf("\nPROGRAM 15\n");
    int prod=1;
    printf("Enter n:\n -->");
    scanf("%d",&n);
    while(n>0){
        prod*=(n%10);
        n/=10;
    }
    printf("The product of the digits of the number is %d \n",prod);
    printf("\n");

    printf("\nPROGRAM 16\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    int rev=getReverse(n);
    printf("Reverse of the no. entered is %d\n",rev);
    printf("\n");

    printf("\nPROGRAM 17\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    rev=getReverse(n);
    if(n==rev)
        printf("The no. entered is Pallindrome");
    else
        printf("The no. entered is not Pallindrome");
    printf("\n");

    printf("\nPROGRAM 18\n");
    prog18();
    printf("\n");

    printf("\nPROGRAM 19\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    numToWords(n);
    printf("\n");

    printf("\nPROGRAM 20\n");
    printf("ASCII  -->  VALUE\n");
    for(i=-128;i<=127;i++)
    {
        printf("\"%c\"  -->  %d \n",i,i);
    }
    printf("\n");

    printf("\nPROGRAM 21\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    printf("Enter exponent:\n ->");
    scanf("%d",&ld);
    prod=1;
    for(i=1;i<=ld;i++)
    {
        prod*=n;
    }
    printf("The output is: %d \n",prod);
    printf("\n");

    printf("\nPROGRAM 22\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    printf("Factors of the no. are:\n1");
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
            printf(", %d",i);
    }
    printf(", %d\n",n);
    printf("\n");

    printf("\nPROGRAM 23\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    int f=1;
    for(i=1;i<=n;f*=i,i++);
    printf("Factorial = %d\n",f);
    printf("\n");

    printf("\nPROGRAM 24\n");
    int a,b;
    printf("Enter a ->");
    scanf("%d",&a);
    printf("Enter b ->");
    scanf("%d",&b);
    int hcf=getHCF(a,b);
	printf("HCF = %d \n",hcf);
    printf("\n");

    printf("\nPROGRAM 25\n");
    printf("Enter a ->");
    scanf("%d",&a);
    printf("Enter b ->");
    scanf("%d",&b);
    int lcm=(a*b)/getHCF(a,b);
    printf("LCM = %d \n",lcm);
    printf("\n");

    printf("\nPROGRAM 26\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    if(isPrime(n))
        printf("No. is Prime\n");
    else
        printf("No. is not Prime\n");
    printf("\n");

    printf("\nPROGRAM 27\n");
    printf("Enter n (n>2) :\n  ->");
    scanf("%d",&n);
    printf("Prime numbers are :\n");
    for(i=2;i<=n;i++)
    {
        if(isPrime(i))
            printf("%d\n",i);
    }
    printf("\n");

    printf("\nPROGRAM 28\n");
    printf("Enter n :\n  ->");
    scanf("%d",&n);
    sum=0;
    for(i=1;i<=n;i++)
    {
        if(isPrime(i))
            sum+=i;
    }
    printf("Sum of prime no.s till n are %d \n",sum);
    printf("\n");

    printf("\nPROGRAM 29\n");
    printf("Enter n (n>2) :\n  ->");
    scanf("%d",&n);
    printf("Prime factors:\n");
    prmFact(n);
    printf("\n");

    printf("\nPROGRAM 30\n");
    printf("Enter n :\n  ->");
    scanf("%d",&n);
    if(isArmstrong(n))
        printf("No. is Armstrong\n");
    else
        printf("No. is not Armstrong\n");
    printf("\n");

    printf("\nPROGRAM 31\n");
    printf("Enter n :\n  ->");
    scanf("%d",&n);
    printf("Armstrong no.s till n are\n");
    for(i=1;i<=n;i++)
    {
        if(isArmstrong(i))
            printf("%d, ",i);
    }
    printf("\n");

    printf("\nPROGRAM 32\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    if(isPerfect(n))
        printf("No. is Perfect\n");
    else
        printf("No. is not Perfect\n");
    printf("\n");

    printf("\nPROGRAM 33\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    printf("Perfect no.s till n are\n");
    for(i=1;i<=n;i++)
    {
        if(isPerfect(i))
            printf("%d, ",i);
    }
    printf("\n");

    printf("\nPROGRAM 34\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    if(isStrong(n))
        printf("No. is Strong\n");
    else
        printf("No. is not Strong\n");
    printf("\n");

    printf("\nPROGRAM 35\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    printf("Strong no.s till n are\n");
    for(i=1;i<=n;i++)
    {
        if(isStrong(i))
            printf("%d, ",i);
    }
    printf("\n");

    printf("\nPROGRAM 36\n");
    int s=1,t,nt;
    f=1;
	printf("Enter the number of terms >2 :\n");
	scanf("%d",&nt);
	nt-=2;
	printf("\n %d, %d",f,s);
	while(nt>0)
	{
		t=s+f;
		printf(", %d",t);
		f=s;
		s=t;
		nt--;
	}
    printf("\n");

    printf("\nPROGRAM 37\n");
    printf("Enter a ->");
    scanf("%d",&a);
    printf("Enter b ->");
    scanf("%d",&b);
    int max=a>b?a:b;
    printf("Max num is %d \n",max);
    printf("\n");

    printf("\nPROGRAM 38\n");
    printf("Enter a ->");
    scanf("%d",&a);
    printf("Enter b ->");
    scanf("%d",&b);
    int c;
    printf("Enter c ->");
    scanf("%d",&c);
    max = (a>b) ? (a>c?a:c) : (b>c?b:c);
    printf("Max num is %d \n",max);
    printf("\n");

    printf("\nPROGRAM 39\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    int isCh=(n%2==0)?1:0;
    if(isCh)
        printf("No. is even\n");
    else
        printf("No. is odd\n");
    printf("\n");

    printf("\nPROGRAM 40\n");
    printf("Enter year:\n ->");
    scanf("%d",&n);
    isCh= (n&100==0)?(n%400==0?1:0):(n%4==0?1:0);
    if(isCh)
        printf("It's leap year\n");
    else
        printf("It's not leap year\n");
    printf("\n");

    printf("\nPROGRAM 41\n");
    printf("Enter a character:\n ->");
    fflush(stdin);
    scanf("%c",&ch);
    isCh = ((ch>=65 && ch<=90) || (ch>=97 && ch<=122))?1:0;
    if(isCh)
        printf("It's an alphabet\n");
    else
        printf("It's not an alphabet\n");
    printf("\n");

    printf("\nPROGRAM 42\n");
    printf("Enter day no.:\n ->");
    scanf("%d",&n);
    switch(n){
        case 1: printf("\n -->Sunday\n"); break;
        case 2: printf("\n -->Monday\n"); break;
        case 3: printf("\n -->Tueday\n"); break;
        case 4: printf("\n -->Wednesday\n"); break;
        case 5: printf("\n -->Thursday\n"); break;
        case 6: printf("\n -->Friday\n"); break;
        case 7: printf("\n -->Saturday\n"); break;
        default: printf("\n WRONG DAY NO. \n");
    }
    printf("\n");

    printf("\nPROGRAM 43\n");
    printf("Enter month no.:\n ->");
    scanf("%d",&n);
    switch(n){
        case 1: printf("\n -->January\n"); break;
        case 2: printf("\n -->February\n"); break;
        case 3: printf("\n -->March\n"); break;
        case 4: printf("\n -->April\n"); break;
        case 5: printf("\n -->May\n"); break;
        case 6: printf("\n -->June\n"); break;
        case 7: printf("\n -->July\n"); break;
        case 8: printf("\n -->August\n"); break;
        case 9: printf("\n -->September\n"); break;
        case 10: printf("\n -->October\n"); break;
        case 11: printf("\n -->November\n"); break;
        case 12: printf("\n -->December\n"); break;
        default: printf("\n WRONG MONTH NO. \n");
    }
    printf("\n");

    printf("\nPROGRAM 44\n");
    printf("Enter a character:\n ->");
    fflush(stdin);
    scanf("%c",&ch);
    switch(ch){
        case 'a':
        case 'e':
        case 'o':
        case 'i':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U': printf("Its a vowel.\n"); break;
        default: printf("Its a consonant.\n");
    }
    printf("\n");

    printf("\nPROGRAM 45\n");
    printf("Enter a ->");
    scanf("%d",&a);
    printf("Enter b ->");
    scanf("%d",&b);
    switch(a >= b){
        case 0: printf("THE GREATER NO. IS %d \n",b); break;
        case 1: printf("THE GREATER NO. IS %d \n",a); break;
    }
    printf("\n");

    printf("\nPROGRAM 46\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    switch(n%2==0){
        case 0: printf("ODD NO. \n"); break;
        case 1: printf("EVEN NO. %d \n",a); break;
    }
    printf("\n");

    printf("\nPROGRAM 47\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    switch (n > 0)
    {
        case 1:
            printf("   POSITIVE");
        break;
        case 0:
            switch (n < 0)
            {
                case 1: 
                    printf("   NEGATIVE");
                    break;
                case 0:
                    printf("   ZERO");
                    break;
            }
        break;
    }
    printf("\n");

    printf("\nPROGRAM 48\n");
    printf("Enter a ->");
    scanf("%d",&a);
    printf("Enter b ->");
    scanf("%d",&b);
    printf("Enter c ->");
    scanf("%d",&c);
    prog48(a,b,c);
    printf("\n");

    printf("\nPROGRAM 49\n");
    printf("Enter a ->");
    scanf("%d",&a);
    printf("Enter b ->");
    scanf("%d",&b);
    float res=0.0f;
    printf("OPERATIONS\n 1.ADD\n 2.SUBTRACT\n 3.MULTIPLY\n 4.DIVIDE\n 5.MODULUS\n");
    printf("Enter Choice of operation ->");
    scanf("%d",&isCh);
    switch(isCh){
        case 1: res=a+b; break;
        case 2: res=a-b; break;
        case 3: res=a*b; break;
        case 4: res=(float) a/b ; break;
        case 5: res=a%b; break;
        default: printf("Wrong choice ....\n");
    }
    printf("RESULT = %.3f \n",res);
    printf("\n");

    printf("\nPROGRAM 50\n");
    printf("Enter n:\n ->");
    scanf("%d",&n);
    if ( n & 1 == 1 )
      printf("Odd\n");
    else
      printf("Even\n");
    printf("\n*************\n");
    return 0;
}