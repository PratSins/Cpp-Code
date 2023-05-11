
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 10
#define M 5  // size of the A matrix
#define K 3  // size of the B matrix
#define L M-K+1 // size of the C matrix
#define P M-K+2 // size of the D matrix
#define Q ((M-K+2)/2) // size of the E matrix
//#define M_PI 3.14159265358979323846

// function declarations for the first program
int isPrime(int); 
int allPrime(int, int, int); 
void pairPrimeDivisible(int [], int, int);
void pairPrimePresent(int []);
int sumTwoInteger(int, int);
int isDivisible(int, int, int );
int isPresent(int [], int);

// function declarations for the second program
void printMatrix(int A[][M], int);
void printMask(double B[][K], int);
void fnMatrixConv(int Mat1[][M], double Mat2[][K]);
void fnMatrixPool(int C[][L]);


int main()
{
	int X, x, y;
	int i,j;
	int lower = 0, upper=255;
	int A[M][M]={0}, C[K][K]={0}, D[K+1][K+1]={0}, E[K-1][K-1]={0};
    double B[K][K]={0};
	double sigma = 1.0;
    double r, s = 2.0 * sigma * sigma;
    double sum = 0.0;
    int ind = K/2;
	
	//================= Code for the first program =================
    printf("Please enter the value of X\n");
	scanf("%d",&X);
	printf("Please enter the value of x and y\n");
	scanf("%d %d",&x,&y);
	
	printf("\n\n");
	printf("====== Output of the first program ======\n");
	
    allPrime(X, x, y);	
	
	
	
	//===================  Code for the second program =============
	
	printf("\n\n\n\n");
	printf("====== Output of the second program ======\n");
	
	
	for(i=0; i<M; i++)
		for(j=0; j<M; j++)
		{
			//scanf("%d", &A[i][j]);
			A[i][j] = (rand()%(upper - lower + 1)) + lower;
		}
		
	printf("\nThe matrix A=\n");
	printMatrix(A,M);
		    
    
    for (int x = -ind; x <= ind; x++) 
	{
        for (int y = -ind; y <= ind; y++) 
		{
            r = sqrt(x * x + y * y);
            B[x + ind][y + ind] = (exp(-(r * r) / s)) / (M_PI * s);
            sum += B[x + ind][y + ind];
        }
    }
 
    // sum of all elements equal to 1
    for (int i = 0; i < K; ++i)
        for (int j = 0; j < K; ++j)
            B[i][j] /= sum;

	
	printf("\nThe matrix B=\n");
	printMask(B,K);
	
	fnMatrixConv(A, B);
	
	return 0;
	
}


int allPrime(int x, int m, int n) 
{
	int i, count = 0, listPrime[N];
	int flag = 0;
	while(count<N)
	{
		
		flag = isPrime(x);
		
		if(flag==1)
		{
			listPrime[count] = x;		
			count++;
		}
		
		x++;
		
	}
	
	printf("All the %d prime numbers are written below.\n", N);
	for(i=0; i<N; i++)
	{
		
		printf("%d ", listPrime[i]);
	}
	
	pairPrimeDivisible(listPrime, m, n);
	pairPrimePresent(listPrime);
	
	
	return 0;
	
}

int isPrime(int n) 
{
	int i;
	for(i=2; i <= n/2; ++i) 
	{
		if(n%i == 0) 
		return 0;
	} 
	return 1;
}

void pairPrimeDivisible(int PrimeNo[N], int int1, int int2)
{
	int i,j,Val;
	int flag = 0, temp=0;
	for(i=0; i<N; i++)
		for(j=i+1; j<N; j++)
		{
			Val = sumTwoInteger(PrimeNo[i],PrimeNo[j]);
			
			if(isDivisible(Val,int1,int2)==1)
			{   
				if(temp==0)
				{	
					printf("\nThe pair of prime numbers whose sum is divisible by % d and %d are given below.", int1, int2);
					temp=1;
				}
				printf("\n%d %d", PrimeNo[i], PrimeNo[j]);
				flag = 1;
			}
				
		}
		
	if(flag==0)
		printf("\nNo pair is found whose sum is divisible by %d and %d", int1, int2);
			
	
	
}

void pairPrimePresent(int PrimeNo[N])
{
	int i,j,Val;
	int flag = 0, temp=0;
	for(i=0; i<N; i++)
		for(j=i+1; j<N; j++)
		{
			Val = sumTwoInteger(PrimeNo[i],PrimeNo[j]);
			
			if(isPresent(PrimeNo,Val-3)==1)
			{   
				if(temp==0)
				{	
					printf("\nThe pair of prime numbers whose sum subtracted by 3 is present in the array are given below.");
					temp=1;
				}
				printf("\n%d %d", PrimeNo[i], PrimeNo[j]);
				flag = 1;
			}
				
		}
		
	if(flag==0)
		printf("\nNo pair is found whose sum present in the list." );
			
	
	
}

int sumTwoInteger(int a, int b)
{
	return (a+b);
}

int isDivisible(int value, int x, int y)
{
	return ((value%x)==0 & (value%y)==0)? 1:0;
	
}


int isPresent(int arrPrime[], int val)
{
	int i;
	
	for(i=0; i<N; i++)
	{
		if(val==arrPrime[i])
			return 1;
	}
	
	return 0;
	
}


 

void printMatrix(int Mat[][M], int m)
{
	int i, j;
	
	for(i=0; i<m; i++)
	{	for(j=0; j<m; j++)
		{
			printf("%3d ", Mat[i][j]);
		}
		printf("\n");
	}
	
}

void printMask(double Mat[][K], int k)
{
	int i, j;
	
	for(i=0; i<k; i++)
	{	for(j=0; j<k; j++)
		{
			printf("%5lf ", Mat[i][j]);
		}
		printf("\n");
	}
	
}

void fnMatrixConv(int Mat1[][M], double Mat2[][K])
{
	
	int i, j, r, s;
	int C[L][L]={0};
	
	for(i=0;i<L;i++)
	{
		for(j=0;j<L;j++)
		{
			for(r=0;r<K;r++)
			{
				for(s=0;s<K;s++)
				{
					C[i][j] += Mat1[i+r][j+s]*Mat2[r][s];					
					
				}
			}
			if(C[i][j]<0)
			   C[i][j] = -C[i][j];
		}
	}
	
	
	printf("\nThe matrix C=\n");
	
	for(i=0; i<L; i++)
	{	for(j=0; j<L; j++)
		{
			
			printf("%4d ", C[i][j]);
		}
		printf("\n");
	}
	
	
	fnMatrixPool(C);
	
}


void fnMatrixPool(int C[][L])
{
	int i, j, r, s, temp;
	int D[P][P] = {0}, E[Q][Q] = {0};
	for(i=0; i<L; i++)
	{	for(j=0; j<L; j++)
		{
			D[i][j] = C[i][j];			
		}
		
	}

	printf("\nThe matrix D=\n");
	
	for(i=0; i<P; i++)
	{	for(j=0; j<P; j++)
		{
			
			printf("%4d ", D[i][j]);
		}
		printf("\n");
	}
	
	
	
	for(i=0;i<Q;i++)
	{
		for(j=0;j<Q;j++)
		{
			temp=0;
			for(r=0;r<2;r++)
			{
				for(s=0;s<2;s++)
				{
									
					if(D[i*2+r][j*2+s]>temp)
						temp  = D[i*2+r][j*2+s];					
					
				}
			}
			
			E[i][j] = temp;
			
		}
	}
	
	
	printf("\nThe matrix E=\n");
		
	for(i=0; i<Q; i++)
	{	for(j=0; j<Q; j++)
		{
			
			printf("%4d ", E[i][j]);
		}
		printf("\n");
	}
	
}