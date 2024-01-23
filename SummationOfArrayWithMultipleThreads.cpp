#include <iostream>
#include <thread>

#define N 5
#define M 1

/* This function is called by each thread */
void sumRow(int *row, long *res)
{
    int i;
    long sum = 0;
    for (i = 0; i < M; i++)
    sum += row[i];
    *res = sum; /* return the sum. */
}

/* Initialize the array */
void initArray(int array[N][M])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            // Initialize each element of the array with some value, for example, (i+1)*(j+1)
            array[i][j] = (i + 1) * (j + 1);
        }
    }
}

/* Main program */
int main(int argc, char **argv)
{
    int array[N][M];
    int i;
    std::thread threads[N];
    long res[N];
    long sum = 0;

    initArray(array);

    for (i = 0; i < N; i++)
    {
        threads[i] = std::thread(sumRow, array[i], &res[i]);
    }

    /* Wait for the threads’ termination and sum the partial results */
    for (i = 0; i < N; i++)
    {
        threads[i].join();
        sum += res[i];
    }

    std::cout << "Sum: " << sum << "\n";

    return 0;
}
