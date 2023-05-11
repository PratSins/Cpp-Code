#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int prog2()
{
    int M,K,lower=0,upper=255,i,j;
    float sigma=1.0,sum=0;
    printf("Enter order of matrix A: ");
    scanf("%d",&M);
    printf("Enter order of matrix B: ");
    scanf("%d",&K);
    int A[M][M];
    float B[K][K];
    srand(time(0));
    printf("\n Matrix A\n");
    for(i=0;i<M;i++){
        for(j=0;j<M;j++)
            A[i][j]=(rand()%(upper-lower+1))+lower;
    }
    for(i=0;i<M;i++)
    {
        for(j=0;j<M;j++) 
            printf("%d ",A[i][j]);
        printf("\n");
    }
    printf("\n\n Matrix B\n");
    
    for(i=0;i<K;i++)
    {
        for(j=0;j<K;j++)
        {
            B[i][j]= (float) (1/(2*M_PI*sigma)*exp(-((i*i)+(j*j)/(2*sigma*sigma))));
            sum+=B[i][j];
        }
    }
    for(i=0;i<K;i++){
        for(j=0;j<K;j++)
            B[i][j]=B[i][j]/sum;
    }
    for(i=0;i<K;i++)
    {
        for(j=0;j<K;j++)
            printf("%f ",B[i][j]);
        printf("\n");
    }
    return 0;
}
int isPrime(int n)
{
    if(n==1) return 0;
    for(int i=2;i<=n/2;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int sumTwoInteger(int p1, int p2){
    return p1+p2;
}
int isDivisible(int sum, int x, int y){
    return (sum%x==0 && sum%y==0)? 1:0;
}
void pairPrimeDivisible(int p1, int p2, int x, int y)
{
    int sum = sumTwoInteger(p1,p2);
    if(isDivisible(sum, x, y) ==1){
        printf("(%d, %d) ; sum = %d; divisible by both %d and %d\n", p1,p2, sum, x, y);
    }
}
int isPresent(int s, int arr[], int size)
{
    for(int i=0; i<size; i++){
        if(s==arr[i]) return 1;
    }
    return 0;
}
void pairPrimePresent(int p1, int p2, int arr[], int size)
{
    int sum = sumTwoInteger(p1, p2);
    int key= sum-3;
    if(isPresent(key, arr, size)==1){
        printf("(%d,%d) sum: %d - 3 = %d is present in the array\n", p1, p2, sum, key);
    }
}
void allPrime(int arr[],int n, int a)
{
    int k=0;
    printf("The first %d prime numbers starting from %d are:\n", n,a);
    for(int i=a; k<=n; i++)
    {
        if(isPrime(i)==1)
        {
            arr[k]=i;
            printf("%4d", i);
            k++;
        }
    }
    printf("\n\n");

    int x,y;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);

    for(int a=0; a<k; a++)
    {
        int p1=arr[a];
        for(int b=0; b<k; b++)
        {
            int p2=arr[b];
            pairPrimeDivisible(p1, p2, x, y);
          
        }
    }
    printf("\n\n");
    for(int a=0; a<k; a++)
    {
        int p1=arr[a];
        for(int b=0; b<k; b++)
        {
            int p2=arr[b];
            pairPrimePresent(p1, p2, arr, k);
        }
    }
}
int main()
{
    printf("\n PROGRAM 1\n");
    int a, n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("Enter value of a: ");
    scanf("%d", &a);
    int primes[n];
    allPrime(primes, n, a);
    printf("\n");

    printf("\n PROGRAM 2\n");
    prog2();
    return 0;
}