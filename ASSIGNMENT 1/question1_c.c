#include <stdio.h>
#include <omp.h>

int main() {
    int thread_id; // Declare thread_id outside the parallel region
    omp_set_num_threads(5); // Set the number of threads to 5
    #pragma omp parallel
    {
        thread_id = omp_get_thread_num();
        printf("Hello, World! This is thread %d\n", thread_id);
    }
    return 0;
}
