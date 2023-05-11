#include <stdio.h>
#include <stdlib.h>

void convert(int a[], int n)
{
    int t;
    for (int i = 1; i < n; i += 2)
    {
        if (a[i - 1] > a[i]){
            t = a[i];
            a[i] = a[i - 1];
            a[i - 1] = t;
        }

        if (i + 1 < n && (a[i + 1] > a[i])){
            t = a[i];
            a[i] = a[i + 1];
            a[i + 1] = t;
        }
    }
}
int main()
{
    printf("\n---------------------LAB 12---------------------\n\n");

    int arr[] = { 4, 3, 7, 8, 6, 2, 1 };
    printf("Intial Array\n  -> [ 4 3 7 8 6 2 1 ]\n");
    int n = sizeof(arr) / sizeof(arr[0]);

    convert(arr, n);

    printf("\nFinal Array\n  -> [ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    
    return 0;
}