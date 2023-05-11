#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int lower = 1, upper = 6, count = 10;
    srand(time(0));
    printf("The random numbers are: ");
    for (int i = 0; i < count; i++) 
    {
        int num = (rand() % (upper - lower + 1)) + lower;
        printf("%d ", num);
    }
    return 0;
}