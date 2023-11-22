#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50000

// Global variables to count comparisons and exchanges
long long comp_count = 0;
long long exch_count = 0;

// Function prototypes
void swap(int arr[], int i, int j);
int less(int a, int b);
void printArray(int arr[]);
void moveElementToEnd(int [], int);
void SelectionSort(int arr[]);
void initArray(int arr[], int k);


int main() {
    srand(time(NULL));

    clock_t start, end;
    long double cpu_time_used;
    //int comparisonsCount, swapsCount;

    long long array[MAX_SIZE];
    //int k = 10000;

    for (int k = 1; k < MAX_SIZE; k*=2)
    {
        initArray(array, k);
        SelectionSort(array);
        printf("%d \n", k);
    }
    printf("Array Size\t Selection Sort Time\t Selection Sort Comparisons\n");
}


void SelectionSort(int arr[]) // hold 1st element, search for the smallest and put it in the right place
{
    int i, j, min_index;
    int comp_count = 0;
    clock_t start = clock();
    double cpu_time_used;

    for (i = 0; i < MAX_SIZE - 1; i++) {
        min_index = i;

        for (j = i + 1; j < MAX_SIZE; j++) {
            comp_count++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap the found minimum element with the first element
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

        clock_t end = clock();

        // Check elapsed time after each iteration
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        if (cpu_time_used > 300.0) {
            break;
        }
    }

    printf("%lf \n", cpu_time_used);
    printf("%d comparisons", comp_count);

}

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int less(int x, int y)
{
    return (x < y) ? x : y;
}


void moveElementToEnd(int arr[], int randomIndex) {

    // Shift the elements to make space for the element to be moved
    for (int j = randomIndex; j < MAX_SIZE - 1; j++) {
        swap(arr, j, j + 1);
    }
}


void initArray(int array[], int k) {
    for (int i = 0; i < MAX_SIZE; i++) {
        array[i] = i + 1;
    }

    if (k >= MAX_SIZE) {
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < k; i++) {
        int randomIndex = i + rand() % (MAX_SIZE - i);
        moveElementToEnd(array, randomIndex);
    }
}

void printArray(int arr[])
{
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}


/*
    for (int k = 1; k < MAX_SIZE; k *= 2) {
        initArray(array, k);

        // Selection Sort
        comparisonsCount = 0;
        swapsCount = 0;
        startTime = measureTime(selectionSort, array, 0, MAX_SIZE - 1, &comparisonsCount, &swapsCount);
        endTime = measureTime(selectionSort, array, 0, MAX_SIZE - 1, &comparisonsCount, &swapsCount);
        printf("%d\t%.6f\t", k, endTime - startTime);

        // Merge Sort
        comparisonsCount = 0;
        swapsCount = 0;
        startTime = measureTime(mergesort, array, 0, MAX_SIZE - 1, &comparisonsCount, &swapsCount);
        endTime = measureTime(mergesort, array, 0, MAX_SIZE - 1, &comparisonsCount, &swapsCount);
        printf("%.6f\t%d\t%d\n", endTime - startTime, comparisonsCount, swapsCount);
    }

    return 0;
    */