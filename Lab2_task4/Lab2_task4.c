#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50000
#define K 5 // You can adjust this value as needed

// Global variables to count comparisons and exchanges
long long comp_count = 0;
long long exch_count = 0;

// Function prototypes
void swap(int arr[], int i, int j);
int less(int a, int b);
void printArray(int arr[]);
void moveElementsToEnd(int arr[], int indicesToMove[], int numIndices);
void SelectionSort(int arr[]);
void merge(int array[], int l, int m, int r);
void mergesort(int array[], int l, int r);
void initArray(int arr[]);

// Helper function to swap elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Helper function to check if a is less than b
int less(int a, int b) {
    comp_count++;
    return a < b;
}

// Helper function to print the elements of an array
void printArray(int arr[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to move selected elements to the end of the array
void moveElementsToEnd(int arr[], int indicesToMove[], int numIndices) {
    for (int i = 0; i < numIndices; i++) {
        int index = indicesToMove[i];
        int temp = arr[index];

        for (int j = index; j < MAX_SIZE - i - 1; j++) {
            arr[j] = arr[j + 1];
        }

        arr[MAX_SIZE - i - 1] = temp;
    }
}

// Selection Sort
void SelectionSort(int arr[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        int min = i;
        for (int j = i + 1; j < MAX_SIZE; j++) {
            if (less(arr[j], arr[min]))
                min = j;
        }
        swap(arr, i, min);
    }
    printArray(arr);
    printf("%lld comparisons, %lld exchanges \n\n", comp_count, exch_count);
}

// Merge Sort
void merge(int array[], int l, int m, int r) {
    int i, j, k;
    int leftSize = m - l + 1;
    int rightSize = r - m;

    int leftArray[MAX_SIZE], rightArray[MAX_SIZE];

    /* Copy data to temp arrays leftArray[] and rightArray[] */
    for (i = 0; i < leftSize; i++)
        leftArray[i] = array[l + i];
    for (j = 0; j < rightSize; j++)
        rightArray[j] = array[m + 1 + j];

    /* Merge the temp arrays back into array[l..r]*/
    // Initial index of first subarray
    i = 0;
    // Initial index of second subarray
    j = 0;
    // Initial index of merged subarray
    k = l;

    while ((i < leftSize) && (j < rightSize)) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of left side[], if there are any */
    while (i < leftSize) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < rightSize) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergesort(int array[], int l, int r) {
    // End of recursion reached?
    if (l >= r)
        return;

    int m = l + (r - l) / 2;
    mergesort(array, l, m);
    mergesort(array, m + 1, r);
    merge(array, l, m, r);
    printArray(array);
}

// Function to initialize the array
void initArray(int arr[]) {
    // Implementation of initArray
    // ...
}

int main() {
    int myArray[MAX_SIZE];

    for (int k = 1; k < MAX_SIZE; k *= 2) {
        initArray(myArray);

        // Measure time and comparisons for Selection Sort
        comp_count = 0;
        exch_count = 0;
        clock_t start = clock();
        SelectionSort(myArray);
        clock_t end = clock();
        double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Selection Sort with k = %d: %f seconds, Comparisons: %lld, Exchanges: %lld\n", k, cpu_time_used, comp_count, exch_count);

        // Reset the array for the next iteration
        initArray(myArray);

        // Measure time and comparisons for Merge Sort
        comp_count = 0;
        exch_count = 0;
        start = clock();
        mergesort(myArray, 0, MAX_SIZE - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Merge Sort with k = %d: %f seconds, Comparisons: %lld, Exchanges: %lld\n", k, cpu_time_used, comp_count, exch_count);

        // Check if the computation time exceeds 5 minutes
        if (cpu_time_used > 300) {
            printf("Exceeded 5 minutes. Stopping the run for k = %d.\n", k);
            break;
        }
    }

    return 0;
}
