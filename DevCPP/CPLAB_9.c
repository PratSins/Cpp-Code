#include <stdio.h>
#include <string.h>
void fillmatrix(int A[3][3]){
    for(int i=0;i<3;i++){
        printf("Enter Row no. %d with space separated values=",i+1);
        scanf("%d %d %d",&A[i][0],&A[i][1],&A[i][2]);
    }
}
void Sum(int* arr,int *s,int *sum){
    for(int i=0;i<*s;i++){
        *sum+=*(arr+i);
    }
}
void StrRev(char *Str,int s){
    int i=0;
    char temp;
    while(i<s){
        temp=*(Str+i);
        *(Str+i)=*(Str+s);
        *(Str+s)=temp;
        i++;
        s--;
    }
}
void printMatrix(int A[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}
void MatMul(int A[][3],int B[][3],int C[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            *(*(C+i)+j)=0;
            for(int k=0;k<3;k++){
                *(*(C+i)+j)+=(*(*(A+i)+k)*(*(*(B+k)+j)));
            }
        }
    }
}
int main(){
    printf("Question-1.a\n\n");
    int A[]={80,75,60,90,50};
    int *P[5];
    for(int i=0;i<5;i++){
        P[i]=&A[i];
    }
    int **Q=P;
    for(int j=0;j<5;j++){
        printf("%d ",*(*Q+j));
    }
    printf("\n");
    printf("Question-1.b\n");
    Q++;
    printf("%d %d %d", Q-P, *Q-A, **Q);
    *Q++;
    printf("\n");
    printf("Question-1.c\n");
    printf("%d %d %d",Q-P,*Q-A,**Q);
    *(++Q);
    printf("\n");
    printf("Question-1.d\n");
    printf("%d %d %d",Q-P,*Q-A,**Q);
    ++(*Q);
    printf("\n");
    printf("Question-1.e\n");
    printf("%d %d %d",Q-P,*Q-A,**Q);
    printf("\n");
    printf("\nQuestion-2\n\n");
    int A1[3][3];
    int B[3][3];
    int C[3][3];
    printf("Matrix-A\n");
    fillmatrix(A1);
    printf("Matrix-B\n");
    fillmatrix(B);
    printf("Matrix-C\n");
    fillmatrix(C);
    int D[3][3],E[3][3];
    MatMul(A1,B,D);
    MatMul(D,C,E);
    printMatrix(E);
    printf("\n");
    printf("\nQuestion-3\n\n");
    int n3=0;
    printf("Enter the Size of Array=");
    scanf("%d",&n3);
    int Arr3[n3];
    for(int i=0;i<n3;i++){
        printf("Enter element no-%d=",i+1);
        scanf("%d",&Arr3[i]);
    }
    int p=0;
    printf("Enter p=");
    scanf("%d",&p);
    int temp=0;
    int* ptr=Arr3;
    for(int i=0;i<p;i++){
        temp=*(ptr+n3-1);
        for(int j=n3-1;j>0;j--){
            *(ptr+j)=*(ptr+j-1);
        }
        *ptr=temp;
    }
    for(int i=0;i<n3;i++){
        printf("%d ",Arr3[i]);
    }
    printf("\n\nQuestion-4\n\n");
    int n4=100;
    char str[n4];
    printf("\nEnter the string=");
    scanf("%s",str);
    StrRev(str,strlen(str)-1);
    printf("%s",str);

    printf("\n\nQuestion-5\n\n");
    int n5=0,sum=0;
    printf("Enter size of array=");
    scanf("%d",&n5);
    int arr5[n5];
    for(int i=0;i<n5;i++){
        printf("Enter element no-%d=",i+1);
        scanf("%d",&arr5[i]);
    }
    Sum(arr5,&n5,&sum);
    printf("Sum=%d",sum);
    return 0;
}