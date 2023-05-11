#include <stdio.h>
#include <stdlib.h>
int x = 0;
int isEven( int k ) // To check if it is even or not
{
    if ( k % 2 == 0 )
        return 0;
    return 1;
}

int isOdd( int k ) // To check if it is odd or not
{
    if (k % 2 == 0)
        return 0;
    return 1;
}

int findandprint(int *arr, int m, int n) 
{

    if ((!isEven(arr[1])) && isOdd(arr[5]) && (arr[7] == arr[1] + arr[5]) && (arr[3] == arr[5] + arr[7]) && (arr[4] == arr[1] + arr[3] + arr[5] + arr[7]))
    {
        for (int i = 0; i < 9; i++)
        {
            if (i % 3 == 0)
                printf("\n");
            printf("%d, ", arr[i]);
        }
        x = 1;
    }
    return arr[4];
}

void matrix_form(int mat[][10])
// To call other functions
{
    int arr[9];
    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            x = 0;
            arr[0] = mat[i][j];
            arr[1] = mat[i][j + 1];
            arr[2] = mat[i][j + 2];
            arr[3] = mat[i + 1][j];
            arr[4] = mat[i + 1][j + 1];
            arr[5] = mat[i + 1][j + 2];
            arr[6] = mat[i + 2][j];
            arr[7] = mat[i + 2][j + 1];
            arr[8] = mat[i + 2][j + 2];
            sum = findandprint(arr, 3, 3);
            if (x == 1)
                printf("\n Sum is %d \n",sum);
        }
    }
}

int main()
{
    int mat[10][10] = {{7, 2, 5, 2, 8, 2, 3, 4, 2, 5},
                       {8, 18, 3, 10, 18, 1, 14, 32, 5, 2},
                       {8, 5, 6, 3, 9, 1, 5, 9, 2, 1},
                       {9, 20, 46, 7, 5, 11, 2, 8, 18, 3},
                       {46, 82, 13, 10, 4, 3, 13, 3, 5, 4},
                       {3, 33, 4, 18, 40, 7, 5, 9, 23, 2},
                       {5, 6, 16, 1, 11, 17, 39, 6, 7, 3},
                       {16, 38, 5, 11, 2, 4, 11, 2, 3, 1},
                       {7, 11, 2, 4, 10, 1, 4, 9, 1, 2},
                       {6, 6, 5, 1, 3, 5, 4, 3, 2, 4}};
    matrix_form(mat);
    return 0;
}