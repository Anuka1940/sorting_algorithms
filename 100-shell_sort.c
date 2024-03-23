#include "sort.h"
/** Function to perform shell sort**/
void shell_sort(int *array, size_t size) {
    int i, j, temp;
    size_t gap; // Change gap to size_t to match the size type

    // Calculate the initial gap using Knuth sequence
    for (gap = 1; gap < size / 3; gap = gap * 3 + 1);

    while (gap > 0) {
        // Perform gapped insertion sort for this gap size.
        for (i = gap; i < size; i++) {
            // Save array[i] in temp and make a hole at position i
            temp = array[i];

            // Shift earlier gap-sorted elements up until the correct location for array[i] is found
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }

            // Put temp (the original array[i]) in its correct location
            array[j] = temp;
        }
        // Decrease gap
        gap = (gap - 1) / 3;

        // Print array after decreasing gap
        printf("Array after decreasing gap to %zu:\n", gap); // Change %d to %zu for size_t
        for (size_t k = 0; k < size; k++) { // Change int to size_t for k
            printf("%d ", array[k]);
        }
        printf("\n");
    }
}
