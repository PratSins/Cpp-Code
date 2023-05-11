#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxval(int a, int b){ 
	return (a > b) ? a : b; 
}
void mergeS(int arr[], int p, int q, int r, int arr2[]) 
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L1[n1], M1[n2];
    int L2[n1], M2[n2];

    for (int i = 0; i < n1; i++){
        L1[i] = arr[p + i];
        L2[i] = arr2[p+i];
    }

    for (int j = 0; j < n2; j++){
        M1[j] = arr[q + 1 + j];
        M2[j] = arr2[q + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) 
    {
        if (L1[i] <= M1[j]) 
        {
            arr[k] = L1[i];
            arr2[k] = L2[i];
            i++;
        } 
        else {
            arr[k] = M1[j];
            arr2[k] = M2[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L1[i];
        arr2[k] = L2[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = M1[j];
        arr2[k] = M2[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r, int arr2[]) 
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, arr2);
        mergeSort(arr, m + 1, r, arr2);
        mergeS(arr, l, m, r, arr2);
    }
}
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void q1()
{
    printf("Enter the no. of tickets and the no. of Queries\n ->");
    int n, q;
    scanf("%d %d", &n, &q);
    
    int t[n];
    int score[n];
    printf("Enter the price of Tickets\n -> ");
    for(int i = 0; i<n; i++)  {
        scanf("%d", &t[i]);
    }
    printf("\nEnter the SCORE of Tickets\n -> ");
    for(int i = 0; i<n; i++)  {
        scanf("%d", &score[i]);
    }

    printf("\nAfter MERGE SORT ---");
    mergeSort(score, 0, n - 1, t);
    printf("\nPrice -> ");
    printArray(t,n);
    printf("Scores -> ");
    printArray(score,n);

    for(int i = 0;i < q;i++)
    {
        printf("\nEnter K\n -> ");
        int k;
        scanf("%d",&k);
        if(k>n) {
            i--;
            printf("\nK < n... Try again!..\n");
            continue;
        }
        int s = 0;
        for(int x = n-1; ; x--)
        {
            s = s+ t[x];
            k--;
            if(k == 0)
                break;
        }
        printf("The money needed is --> Rs.%d\n", s);
    }
}

int maxRevenue(int m, int x[], int revenue[], int n,int t)
{
	int mxRv[m+1];
	memset(mxRv, 0, sizeof(mxRv));
	int nxtbb = 0;
	for (int i = 1; i <= m; i++)
	{
		if (nxtbb < n)
		{
			if (x[nxtbb] != i)
				mxRv[i] = mxRv[i-1];
			else
			{
				if (i <= t)
					mxRv[i] = maxval(mxRv[i-1], revenue[nxtbb]);
				else
					mxRv[i] = maxval(mxRv[i-t-1]+revenue[nxtbb], mxRv[i-1]);

				nxtbb++;
			}
		}
		else
			mxRv[i] = mxRv[i - 1];
	}
	return mxRv[m];
}
int main()
{
    printf("\n-----------Question 1-----------\n\n");
    q1();
    printf("\n");

    printf("\n-----------Question 2-----------\n");

    int m = 15, n = 5;
    int x[] = {6, 8, 12, 14, 15};
    int r[] = {3, 6, 5, 3, 5};
    int t = 5;

    int op = maxRevenue(m, x, r, n, t);

    printf("\nNo. of miles --M = %d",m);
    printf("\nNo. of sites of contruction --N = %d", n);
    printf("\nPosition of sites to construct Billboard --X = ");
    printArray(x, n);
    printf("\nRevenue from the given position of sites to construct Billboard --R = ");
    printArray(r, n);   
    printf("\nConstrant in Miles --t = %d",t);

    printf("\n The Maximum profits are --> Rs.%d\n",op);
    printf("\n");
    return 0;
}