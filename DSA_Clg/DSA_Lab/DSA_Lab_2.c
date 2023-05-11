#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <string.h>
void matrixInput(int mat[][3])
{
   int row, col;
   for (row = 0; row < 3; row++)
   {
      for (col = 0; col < 3; col++)
      {
         scanf("%d", (*(mat + row) + col));
      }
   }
}
void matrixPrint(int mat[][3])
{
   int row, col;
   for (row = 0; row < 3; row++)
   {
      for (col = 0; col < 3; col++)
      {
         printf("%d ", *(*(mat + row) + col));
      }
      printf("\n");
   }
}
