#include <stdio.h>

void Q1(){
    //Matrix Input
    int rows, col,i,j;
    printf("Enter size of Matrix (Rows x Coloumn) ->>\n");
    printf("Enter number of rows ->> ");
    scanf("%d", &rows);
    printf("Enter number of coloumn ->> ");
    scanf("%d", &col);
    int a[rows][col];
    printf("Enter values in Matrix of (%d) rows & (%d) coloumn ->> \n",rows, col);
    for(i = 0; i<rows; i++){
        for(j = 0; j<col; j++){
            scanf("%d", &a[i][j]);
        }
    }

    //Creation Of Sparse Matrix
    int size = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < col; j++)
            if(a[i][j] != 0)
                size++;
    }
    int sparseMatrix[3][size];
    int k=0;
    for(i=0; i<rows; i++){
        for(j=0; j<col; j++){
            if(a[i][j] != 0){
                sparseMatrix[0][k] = i;
                sparseMatrix[1][k] = j;
                sparseMatrix[2][k] = a[i][j];
                k++;
            }
        }
    }

    printf("Initial Sparse Matrix ->> \n");
    for (i=0; i<3; i++){
        for (j=0; j<size; j++)
            printf("%d ", sparseMatrix[i][j]);
        printf("\n");
    }

    //Transpose of Matrix
    for(i=0;i<size;i++){
        //swap(a[0][i], a[1][i])
        int x = sparseMatrix[0][i];
        sparseMatrix[0][i] = sparseMatrix[1][i];
        sparseMatrix[1][i] = x;
    }

    printf("Transpose of Sparse Matrix ->> \n");
    for (i=0; i<3; i++){
        for (j=0; j<size; j++)
            printf("%d ", sparseMatrix[i][j]);
        printf("\n");
    }
}

int main() 
{
    Q1();
}