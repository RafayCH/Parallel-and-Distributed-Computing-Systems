#include <stdio.h>
#include <omp.h>

int main() 
{
    omp_set_num_threads(5); // Setting the number of threads to 5
    #pragma omp parallel                //Specifying parallel region
    {
        int thread_id = omp_get_thread_num();    //to get thread id
        printf("Hello, World! This is thread %d\n", thread_id); // Message with thread ID "output"
    }
    return 0;
}
