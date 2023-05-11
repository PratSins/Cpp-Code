#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isEven(int k)
{
    return (k % 2 == 0);
}
int isPrime(int k)
{
    if(k==1)
        return 0;
    int i;
    for(i=2; i<k/2; i++) 
    {
        if (k % i == 0)
            return 0;
    }
    return 1;
}
void matrixPrint(int mat[9])
{
   int row, col, k=0;;
   for (row = 0; row < 3; row++) 
   {
      for (col = 0; col < 3; col++) 
      {
         printf("%d ", mat[k]);
         k++;
      }
      printf("\n");
   }
   printf("\n");
}

void matrix_form(int mat[][10])
{
    int arr[9];
    for (int i = 0; i < 8; i++)
    {
        
        for (int j = 0; j < 8; j++)
        {
            arr[0] = mat[i][j];
            arr[1] = mat[i][j + 1];
            arr[2] = mat[i][j + 2];
            arr[3] = mat[i + 1][j];
            arr[4] = mat[i + 1][j + 1];
            arr[5] = mat[i + 1][j + 2];
            arr[6] = mat[i + 2][j];
            arr[7] = mat[i + 2][j + 1];
            arr[8] = mat[i + 2][j + 2];
            if ( isPrime(arr[1]) && isPrime(arr[3]) && isPrime(arr[5]) && isPrime(arr[7]) && isEven(arr[4]) )
                matrixPrint(arr);
            
        }
    }
}
int main()
{
    
    int mat[10][10] = { {7, 2, 5, 2, 8, 2, 3, 4, 2, 5},
                        {11, 18, 3, 10, 23, 1, 13, 31, 50, 2},
                        {8, 5, 6, 3, 9, 11, 5, 9, 2, 1},
                        {9, 20, 23, 7, 5, 11, 2, 83, 18, 3},
                        {49, 82, 13, 13, 4, 3, 13, 3, 5, 4}, 
                        {3, 37, 4, 18, 47, 7, 5, 43, 23, 2},
                        {5, 6, 16, 1, 11, 17, 39, 6, 7, 3},
                        {16, 38, 5, 11, 2, 67, 11, 2, 3, 1},
                        {7, 11, 2, 2, 71, 1, 4, 59, 10, 29},
                        {6, 6, 5, 17, 3, 5, 4, 3, 2, 4} };
    matrix_form(mat);
    return 0;
}
