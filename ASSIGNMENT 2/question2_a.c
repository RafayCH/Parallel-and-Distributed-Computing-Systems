#include <stdio.h>
#include <omp.h>

int main() {
    // Define two arrays of integers
    int array1[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int array2[16] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // Declare an array to store the result of elements addition
    int result[16];

    // Parallel loop for element addition of two arrays
    #pragma omp parallel for
    for (int i = 0; i < 16; i++) {
        // Each thread computes one element of the result array
        result[i] = array1[i] + array2[i];
    }

    // Print the result array
    for (int i = 0; i < 16; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
