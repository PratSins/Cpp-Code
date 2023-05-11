#include <stdio.h>
#include <time.h>
void take_enter()
{
    printf("Press enter to stop the counter\n");
    while(1)
    {
        if(getchar())
            break;
    }
}
int main()
{
    clock_t t;
    t = clock();
    printf("TimeR Starts\n");
    take_enter();
    printf("Timer Ends\n");
    t=clock()-t;
    double time_taken = ((double) t) / CLOCKS_PER_SEC;
    printf("The Program took %f seconds to execute",time_taken);
    return 0;
}