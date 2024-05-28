#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define Max 1000 // Assuming the max value in the array doesn't exceed 999

// Function to count occurrences of each element in the array
void countElements(int *array, int size, int *count) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        // Increment the count of the element at array[i] atomically
        #pragma omp atomic
        count[array[i]]++;
    }
}

// Function to write sorted elements back to the array
void writeArray(int *array, int *count, int size) {
    int index = 0;
    #pragma omp parallel for
    for (int i = 0; i < Max ; i++) {
        // Write each element back to the array based on its count
        while (count[i] > 0) {
            // Critical section to ensure mutual exclusion while updating array
            #pragma omp critical
            {
                array[index++] = i;
                count[i]--;
            }
        }
    }
}

int main() {
    int size = 10; // size/lenght of array
    int *array = malloc(size * sizeof(int)); // Dynamically allocate memory for the array
    int *count = calloc(Max, sizeof(int)); // Initialize count array with zeros

    // random numbers for the array
    for (int i = 0; i < size; i++) {
        array[i] = rand() % Max;
    }

    // Count occurrences of each element in the array
    countElements(array, size, count);

    // Write sorted elements back to the array
    writeArray(array, count, size);

    // Printing the sorted array
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(array);
    free(count);

    return 0;
}
