// Lab2_task5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int getNextGap(int gap);
void swap(int array[], int i, int j);
void combSort(int arr[], int n);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int n);

int main()
{
    int arr[] = { 2,5,7,3,1,6,8,11,13 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");  // print the unsorted array
    printArray(arr, size);
    printf("Sorted array (Comb Sort):\n");  // print the sorted array
    combSort(arr, size);
    printArray(arr, size);

    putchar('\n');

    int arr2[] = { 2,5,7,3,1,6,8,11,13 };
    printf("Unsorted array: \n");  // print the unsorted array
    printArray(arr2, size);
    printf("Sorted array (Bubble Sort):\n");  // print the sorted array
    bubbleSort(arr2, size);
    printArray(arr2, size);

    return 0;
}

int getNextGap(int gap) {

    gap = (gap * 10) / 13;  // floor(6/1.3) = 4, then 3 then 2 then 1

    if (gap < 1) { 
        return 1;
    }
    return gap;
}

void combSort(int arr[], int n) {

    int comp_count = 0;
    int exch_count = 0;

    // the initial value of the gap variable is set to the size of the array (number of elements)
    int gap = n;

    while (gap > 1) {       // gap != 1 ??
        gap = getNextGap(gap);

        // Perform a single pass of Comb Sort
        for (int i = 0; i < n - gap; i++) {
            comp_count++;
            if (arr[i] > arr[i + gap]) {
                exch_count++;
                swap(arr, i, i + gap);
            }
        }
    }
    printf("%d comparisons, %d exhanges \n", comp_count, exch_count);

}

void bubbleSort(int arr[], int n) {
    int comp_count = 0;
    int exch_count = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp_count++;
            if (arr[j] > arr[j + 1]) {
                exch_count++;
                swap(arr, j, j + 1);
            }
        }
    }
    printf("%d comparisons, %d exhanges \n", comp_count, exch_count);
}

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}


void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}