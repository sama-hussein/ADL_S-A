/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500

// Function prototypes
void swap(int arr[], int i, int j);
int less(int a, int b);
void printArray(int arr[]);
void initArray(int arr[], int k);
void moveElementToEnd(int [], int);
void SelectionSort(int arr[]);
void mergesort(int array[], int l, int r);
void merge(int array[], int l, int m, int r);

int main() {
    srand(time(NULL));

    clock_t start, end;
    long double cpu_time_used;

    long long array[MAX_SIZE];

    for (int i = 0; i < 5; i++)
    {
        printf("\n run number: %d \n", i+1);
        for (int k = 1; k < MAX_SIZE; k *= 2)
        {
            printf("\n K value: %d \n", k);
            initArray(array, k);
            SelectionSort(array);
            printArray(array);
            //number of comparisons is "constant" for each array?
            //mergesort(array, 0, MAX_SIZE-1); //same problem, recursion prints comparison value with every recursive call
        }
    }
}

void SelectionSort(int arr[]) // hold 1st element, search for the smallest and put it in the right place
{
    int i, j, min_index;
    int comp_count = 0;
    double cpu_time_used;

    clock_t start = clock();
    for (i = 0; i < MAX_SIZE - 1; i++) {
        min_index = i;

        for (j = i + 1; j < MAX_SIZE; j++) {
            comp_count++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr, i, min_index);
        clock_t end = clock();

        // Check elapsed time after each iteration
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        if (cpu_time_used > 300.0) {
            break;
        }
    }
    printf("Selection Sort: %lf seconds, %d comparisons", cpu_time_used, comp_count);
}

    

void mergesort(int array[], int l, int r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergesort(array, l, m);
    mergesort(array, m + 1, r);
    merge(array, l, m, r);
}

void merge(int array[], int l, int m, int r) {
    int i, j, k, comp_count=0;
    int leftSize = m - l + 1;
    int rightSize = r - m;

    int leftArray[MAX_SIZE], rightArray[MAX_SIZE];

    double cpu_time_used;

    //Copy data to temp arrays
    for (i = 0; i < leftSize; i++)
        leftArray[i] = array[l + i];
    for (j = 0; j < rightSize; j++)
        rightArray[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    clock_t start = clock();
    while ((i < leftSize) && (j < rightSize)) {
        comp_count++;
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
        clock_t end = clock();

        // Check elapsed time after each iteration
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        if (cpu_time_used > 300.0) {
            break;
        }
        printf("\n Merge Sort: %lf seconds, %d comparisons", cpu_time_used, comp_count);
    }

    while (i < leftSize) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
    // prints with every recursive call????????? need only the last value.....
}


// Helper Functions
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
    for (int j = randomIndex; j < MAX_SIZE - 1; j++) {
        swap(arr, j, j + 1);
    }
}
*/