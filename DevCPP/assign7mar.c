#include <stdio.h>
#include <stdlib.h>
struct student
{
    char name[30];
    int roll;
    float perc;
};
void prog1()
{
    int n;
    char *text;
    printf("Enter limit of the text: ");
    scanf("%d",&n);
    text=(char*)malloc(n*sizeof(char));
    printf("Enter text:\n --> ");
    fflush(stdin); 
    gets(text);
    printf("Inputted text is: %s\n",text);
    free(text);
}
void prog2()
{
    struct student *pstd;
    int n,i;
     
    printf("Enter total number of elements: ");
    scanf("%d",&n);
    
    pstd=(struct student*)malloc(n*sizeof(struct student));
     
    if(pstd==NULL)
    {
        printf("Insufficient Memory, Exiting... \n");
        return ;
    }
    
    for(i=0; i<n; i++)
    {
        printf("\nEnter detail of student [%3d]:\n",i+1);
        printf("Enter name: ");
        scanf(" "); 
        gets((pstd+i)->name);
        printf("Enter roll number: ");
        scanf("%d",&(pstd+i)->roll);
        printf("Enter percentage: ");
        scanf("%f",&(pstd+i)->perc);
    }
     
    printf("\nEntered details are:\n");
    for(i=0; i<n; i++)
    {
        printf("%30s \t %5d \t %.2f\n",(pstd+i)->name,(pstd+i)->roll,(pstd+i)->perc);
    }
}
void prog3()
{
    printf("\n3(a)\n");
    int r = 3, c = 4,i,j,count;
    int* ptr = malloc((r * c) * sizeof(int));

    for (int i = 0; i < r * c; i++)
        ptr[i] = i + 1;

    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++)
            printf("%d ", ptr[i * c + j]);
        printf("\n");
    }
    free(ptr);
    printf("\n");
    printf("\nDIFFERNT METHOD OF EXECUTING PROGRAM 3 -- 3(b)\n");
    int* arr[r];
    for (i = 0; i < r; i++)
    {
        arr[i] = (int*)malloc(c * sizeof(int));
    }
    count = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            arr[i][j] = ++count; 
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    for (int i = 0; i < r; i++)
        free(arr[i]);
}
void prog4()
{
    int n;
    double *data;
    printf("Enter the total number of elements: ");
    scanf("%d", &n);
    data = (double *)calloc(n, sizeof(double));
    if (data == NULL) 
    {
        printf("Error!!! memory not allocated.");
        return ;
    }
    for (int i = 0; i < n; ++i) 
    {
        printf("Enter number - %d: ", i + 1);
        scanf("%lf", data + i);
    }
    
    for (int i = 1; i < n; ++i) 
    {
        if (*data < *(data + i)) 
        {
            *data = *(data + i);
        }
    }
    printf("Largest number = %.2lf", *data);
    free(data);
}
int main()
{
    printf("PROGRAM 1\n");
    prog1();
    printf("\n");

    printf("PROGRAM 2\n");
    prog2();
    printf("\n");

    printf("PROGRAM 3\n");
    prog3();
    printf("\n");

    printf("PROGRAM 4\n");
    prog4();
    printf("\n");
    return 0;
}