#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
const int k = 4;
const int m = 3;
int sum = 0;

int isPrimeRec(int num) 
{ 
    for (int i=2; i<num; i++) {
        if (num%i==0) {
            return 0;
        }
    }
    return 1;
}
int primeFactRec(int num) 
{
    for (int i=2; i<=num; i++) {
        if(num % i == 0 && isPrimeRec(i)) {
            printf("%d ", i);
        }
    }
}
int oddNumRec(int numb) 
{
    if (isPrimeRec(numb)==1) {
        int fx = (numb*numb*numb) + 1;
        sum += fx;
        printf("%d, %d, ", numb, fx) ;
        primeFactRec(fx);
        printf("\n");
    }
    else {
        int fx = 2*numb*numb + 3;
        sum += fx;
        printf("%d, %d, ", numb, fx) ;
        primeFactRec(fx);
        printf("\n");
    }
}
int evenNumRec(int num)
{
    int fx = 2*num*num + 3*num + 1;
    sum += fx;
    printf("%d, %d, ",num, 2*num*num + 3*num + 1);
    primeFactRec(fx);
    printf("\n");
}
int isPrime(int n)
{
    if(n==1) return 0;
    for(int i=2;i<=n/2;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
void elementMatrixRec(int A[k][m], int i, int j) 
{
    if(i < k && j < m) {
        A[i][j] = rand() % (10 - 1 + 1) + 1;
        printf("%d ", A[i][j]);
        elementMatrixRec(A, i, j+1);
    } else if(j == m) {
        printf("\n");
        elementMatrixRec(A, i+1, j-j);
    } else if(i == k) {
        
    }
}

void powerRec(int A[k][m], int i, int j) 
{
    if(i < k && j < m) {
        double x = pow(A[i][j], i+j);
        printf("%.0lf ", x);
        powerRec(A, i, j+1);
    } else if(j == m) {
        printf("\n");
        powerRec(A, i+1, 0);
    } else if(i == k) {
        
    }
}
int sumDigitsRec(int x)
{
    if(x<10)
        return x;
    else 
        return (x%10) + sumDigitsRec(x/10);
}
int isNum(int x)
{
    while (x>0)
    {
        if(!((x%10)==1 || (x%10)%3==0))
            return 0;
        x/=10;
    }
    return 1;
}
void numrec(int x)
{
    if(x<1)
        return;
    if(x==1)
    {
        if(isNum(x))
            printf("%d  --> %d\n",x,sumDigitsRec(x));
    }
    else
    {
        numrec(x-1);
        if(isNum(x))
            printf("%d  --> %d\n",x,sumDigitsRec(x));
    }
}
int largePrime(int arr[], int s, int n, int z) {
    if(s == n) {
        return z;
    }
    if(isPrime(arr[s]) && arr[s] > z) {
        int y = arr[s];
        largePrime(arr, s+1, n, y);
    } else {
        largePrime(arr, s+1, n, z);
    }
}
int smallOdd(int a[],int s, int small)
{
    if(s==0)
    {
        if(a[s]<small && a[s]%2==1)
            return a[s];
        return small;
    }
    else{
        if(a[s]<small && a[s]%2==1)
            small=a[s];
        small=smallOdd(a,s-1,small);
        return small;
    }
}
int bigEven(int a[],int s, int big)
{
    if(s==0)
    {
        if(a[s]>big && a[s]%2==0)
            return a[s];
        return big;
    }
    else{
        if(a[s]>big && a[s]%2==0)
            big=a[s];
        big=bigEven(a,s-1,big);
        return big;
    }
}
int main()
{
    printf("\nPROGRAM 1\n");
    int x;
    printf("Enter a no.\n -->");
    scanf("%d",&x);
    printf("No. --> Sum\n");
    numrec(x);
    printf("\n");

    printf("\nPROGRAM 2\n");
    int n;
    printf("Enter no. of elements of array n: ");
    scanf("%d",&n);
    int arr[n];
    int lower = 10, upper = 60;
    srand(time(0));
    printf("\nThe array elements are: \n");
    for (int i = 0; i < n; i++) 
    {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\nSmallest Odd no. is %d \n",smallOdd(arr,n-1,61));
    printf("Largest Even no. is %d \n",bigEven(arr,n-1,8));
    printf("Largest Prime Factor of a number in array is %d\n", largePrime(arr, 0, n, 7));
    printf("\n");  

    printf("\nPROGRAM 3\n");
    printf("Enter n :\n --> ");
    scanf("%d", &n);
    printf("The values are written as : x, f(x), prime factors of f(x), below : \n");
    for (int i=2; i<=n; i++) 
    {
        if (i%2 != 0 ) {
            oddNumRec(i);
        }
        else if (i==2) {
            printf("%d, %d, %d", 2, 11, 11);
            printf("\n");
        }
        else {
            evenNumRec(i);
        }
    }
    printf("The sum of all f(x) is %d", sum);
    printf("\n"); 

    printf("\nPROGRAM 4\n");
    int A[k][m];
    printf("Matrix A is \n");
    elementMatrixRec(A, 0, 0);
    printf("Matrix B is \n");
    powerRec(A, 0, 0);
    printf("\n"); 
    return 0;
}
