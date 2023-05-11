#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20

void readsparse(int b[MAX][3])
{
        int i,t;
        printf("\nEnter no. of non-zero elements:");
        scanf("%d",&t);
        b[0][2]=t;
        for (i=1;i<=t;i++)
        {
            printf("\nEnter the next triple(row,column, value):");
            scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
        }
}
void printsparse(int b[MAX][3])
{
        int i,n;
        n=b[0][2]; //no of 3-triples
        printf("\nAfter Transpose:\n");
        printf("\nrow\t\tcolumn\t\tvalue\n");
        for (i=0;i<=n;i++)
        {
            printf("%d\t\t%d\t\t%d\n",b[i][0],b[i][1],b[i][2]);
        }

}
void transpose(int b1[][3],int b2[][3])
{
        int i,j,k,n;
        b2[0][0]=b1[0][1];
        b2[0][1]=b1[0][0];
        b2[0][2]=b1[0][2];
        k=1;
        n=b1[0][2];
        for (i=0;i<b1[0][1];i++)
        {
            for (j=1;j<=n;j++)
            {
                if(i==b1[j][1])
                {
                    b2[k][0]=i;
                    b2[k][1]=b1[j][0];
                    b2[k][2]=b1[j][2];
                    k++;
                }
            }
        }
}
void prog2(){
    int cities,N,M;
    int i,j;
    printf("Let Number of Cities = 2\n");
    printf("Enter number of Movies (N) ->> ");
    scanf("%d",&N);
    printf("Enter number of Persons (M) ->> ");
    scanf("%d", &M);
    int City1[N][M];
    int City2[N][M];
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            City1[i][j] = rand()%6;
            
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            City2[i][j] = rand()%6;
        }
    }

    //Sparse Matrix City 1
    int size1 = 0;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            if(City1[i][j] != 0)
                size1++;
    int sMCity1[3][size1];
    int moviesC1[size1];
    int ratingsC1[size1];
    int k=0;
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            if(City1[i][j] != 0){
                sMCity1[0][k] = i;
                moviesC1[k] = i;
                sMCity1[1][k] = j;
                sMCity1[2][k] = City1[i][j];
                ratingsC1[k] = City1[i][j];
                k++;
            }
        }
    }

    //Sparse Matrix 2
    int size2 = 0;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            if(City2[i][j] != 0)
                size2++;
    int sMCity2[3][size2];
    int moviesC2[size2];
    int ratingsC2[size2];
    k=0;
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            if(City2[i][j] != 0){
                sMCity2[0][k] = i;
                moviesC2[k] = i;
                sMCity2[1][k] = j;
                sMCity2[2][k] = City2[i][j];
                ratingsC2[k] = City2[i][j];
                k++;
            }
        }
    }

    printf("\nSparse Matrix of City 1 ->>\n");
    for (i=0; i<3; i++){
        for (j=0; j<size1; j++)
            printf("%d ", sMCity1[i][j]);
        printf("\n");
    }

    printf("\nSparse Matrix of City 2 ->>\n");
    for (i=0; i<3; i++){
        for (j=0; j<size2; j++)
            printf("%d ", sMCity2[i][j]);
        printf("\n");
    }

    int movC1[N];
    int movC2[N];
    int tmp = moviesC1[0];
    int sum = 0;
    int count = 0;
    for(i=0, j = 0; i<size1;i++){
        if(tmp == moviesC1[i]){
            sum+=ratingsC1[i];
            count++;
        }
        else{
            movC1[j] = sum/count;
            j++;
            int tmp = moviesC1[i];
            int sum = 0;
            int count = 0;
            sum+=ratingsC1[i];
        }
    }

    tmp = moviesC2[0];
    sum = 0;
    count = 0;
    for(i=0, j = 0; i<size2;i++){
        if(tmp == moviesC2[i]){
            sum+=ratingsC2[i];
            count++;
        }
        else{
            movC2[j] = sum/count;
            j++;
            int tmp = moviesC2[i];
            int sum = 0;
            int count = 0;
            sum+=ratingsC2[i];
        }
    }

    int avgRating[N];
    for(i=0;i<N;i++){
        avgRating[i] = (movC1[i]+movC2[i])/2;
    }

    printf("\nAVERAGE RATING ->> \n");
    for(i=0;i<N;i++){
        printf("%d ",avgRating[i]);
    }
}
int main()
{
    printf("\nPROGRAM 1\n");
    int b1[MAX][3],b2[MAX][3],m, n;
    printf("Enter the size of matrix (rows,columns):");
    scanf("%d %d", &m, &n);
    b1[0][0]=m;
    b1[0][1]=n;
    readsparse(b1);
    transpose(b1,b2);
    printsparse (b2);
    printf("\n");

    printf("\nPROGRAM 2\n");
    prog2();
    printf("\n");
    
    printf("\nPROGRAM 3\n");
    int n;
    printf("\nEnter matrix size:\n  ->");
    scanf("%d", &n);
    int arr[n][n];
    printf("\nEnter the elements:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d", &arr[i][j]);
    }

    double c[3][3]={ {1/9,1/9,1/9},
                     {1/9,1/9,1/9},
                     {1/9,1/9,1/9},   };

    int k= (n-2)*(n-2), t1=0;
    int arr2[n-2][n-2], temp[k];
    int tp2[3][3];

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            tp2[0][0] = arr[i][j];
            tp2[0][1] = arr[i][j + 1];
            tp2[0][2] = arr[i][j + 2];
            tp2[1][0] = arr[i + 1][j];
            tp2[1][1] = arr[i + 1][j + 1];
            tp2[1][2] = arr[i + 1][j + 2];
            tp2[2][0] = arr[i + 2][j];
            tp2[2][1] = arr[i + 2][j + 1];
            tp2[2][2] = arr[i + 2][j + 2];
        }
        for(int x=0;x<3;x++)
        {
            for(int y=0;x<3;x++)
            {
                tp2[x][y]= (int) ceil( tp2[x][y]*c[x][y] );
            }
        }
        for(int x=0;x<3;x++)
        {
            for(int y=0;x<3;x++)
            {
                temp[t1]+= tp2[x][y];
            }
        }
        t1++;
    }
    t1=0;
    for(int x=0;x<n-2;x++)
    {
        for(int y=0;x<n-2;x++)
        {
            arr2[x][y]=temp[t1];
            t1++;
        }
    }
    printf("\nOutput Matrix \n");
    for(int x=0;x<n-2;x++)
    {
        for(int y=0;x<n-2;x++)
        {
            printf("%d ",arr2[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}