#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <string.h>
void sum(int *p, int *q, int *z) {
    for(int i = 0; i < *q; i++) {
        *z += *p;
        p++;
    }
}
char *getReverse(char *str)
{
	int i, l;
	char *st;
	l=strlen(str);
    st = (char *) malloc(sizeof(char) * l);

	for(i=0;i<l;i++)
	{
		st[i]=str[l-i-1];
	}
	st[i]='\0';
	return st;
}
void matrixInput(int mat[][3]) {
   int row, col;
   for (row = 0; row < 3; row++) {
      for (col = 0; col < 3; col++) {
         scanf("%d", (*(mat + row) + col));
      }
   }
}
void matrixMultiply(int mat1[][3], int mat2[][3], int res[][3]) 
{
   int row, col, i;
   int sum;
   for (row = 0; row < 3; row++) {
      for (col = 0; col < 3; col++) {
         sum = 0;
         for (i = 0; i < 3; i++) {
            sum += (*(*(mat1 + row) + i)) * (*(*(mat2 + i) + col));
         }
         *(*(res + row) + col) = sum;
      }
   }
}
void matrixPrint(int mat[][3]) {
   int row, col;
   for (row = 0; row < 3; row++) {
      for (col = 0; col < 3; col++) {
         printf("%d ", *(*(mat + row) + col));
      }
      printf("\n");
   }
}
void prog1()
{
    int a[5]={80,75,60,90,50};
    int i=0;
    int *p[5];
    while(i<5)
    {
        p[i]=&a[i];
        i++;
    }
    int **q=p;
    printf("Elements of Array are:\n");
    i=0;
    while(i<5){
        printf("%d ",*p[i]);
        i++;
    }
    printf("\n");
    q++;
    printf("%d %d %d\n", q-p, *q-a, **q);

    *q++;
    printf("%d %d %d\n", q-p, *q-a, **q);

    *(++q);
    printf("%d %d %d\n", q-p, *q-a, **q);

    ++(*q);
    printf("%d %d %d\n", q-p, *q-a, **q);
}
void prog3()
{
    int size, i, p;
    int *arr;
    int *new;
    printf("Enter the size of the array:\n");
    scanf("%d", &size);  
    arr = (int *) malloc(sizeof(int) * size);
    new = (int *) malloc(sizeof(int) * size);
    printf("Enter elements :\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter p:\n  -->");
    scanf("%d",&p);
    int *pt=&arr[size-p];

    for (i = 0; i < p; i++) 
    { 
        new[i]=*(pt+i);
    }
    int j=0;
    for (i = size-p-1; i < size; i++) 
    { 
        new[i]=arr[j];
        j++;
    }
    printf("\nElements :\n");
    for (i = 0; i < size; i++) 
    { 
        printf("%d ",*(new+i));
    }
    printf("\n\n");
    free(arr);
}
int main()
{
    printf("PROGRAM 1\n");
    prog1();
    printf("\n");

    printf("PROGRAM 2\n");
    int a[3][3], b[3][3], c[3][3], d[3][3], e[3][3];
    printf("Enter elements of the array A:\n");
    matrixInput(a);
    printf("Enter elements of the array B:\n");
    matrixInput(b);
    printf("Enter elements of the array C:\n");
    matrixInput(c);

    matrixMultiply(a,b,d);
    matrixMultiply(d,c,e);

    matrixPrint(e);
    printf("\n");

    printf("PROGRAM 3\n");
    prog3();
    printf("\n");

    printf("PROGRAM 4\n");
    char str[500];
    fflush(stdin);
	printf("Enter a string : ");
	gets(str);
    char *ptr=str;
    printf("\n");
	ptr = getReverse(str);
	printf("Reverse String is : ");
	puts(ptr);
    printf("\n");  

    printf("PROGRAM 5\n");
    int n;
    printf("The length of integers array:\n");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    int sum1 = 0;
    int *q = &n;
    int *z = &sum1;
    
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int *p = arr;
    sum(p, q, z);
    printf("The sum is: %d", sum1);
    printf("\n");
    
    return 0;
}