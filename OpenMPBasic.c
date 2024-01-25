#include <stdio.h>
#include <omp.h>
int main()
{
    int me;
    printf("Serial\n");
    #pragma omp parallel
    {
        me = omp_get_thread_num();

        printf("parallel\n");
    }
    printf("Serial\n");
    printf("Thread %d:",me);

    return 0;
}