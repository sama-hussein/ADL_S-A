// Lab2_task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6

// Declare global variables for counters in Task 3
int comp_count = 0;
int exch_count = 0;

// Prototypes
void InsertionSort(int arr[]);
void SelectionSort(int arr[]);
void ShellSort(int arr[]);
void mergesort(int arr[], int l, int r);
void merge(int array[], int l, int m, int r);
void mergesortBU(int array[], int arraySize);
void mergeBU(int array[], int l, int m, int r);
void quicksort(int array[], int l, int r);
int partition(int array[], int l, int r);
void swap(int array[], int i, int j);
int less(int i, int j);
int isSorted(int array[]);
void printArray(int arr[]);

int main()
{
	int arr[] = {2,5,7,3,1,6};

	// To try one algorithm, we need to comment the rest
	SelectionSort(arr);
	printArray(arr);

	//ShellSort(arr);
	//InsertionSort(arr);
	//mergesort(arr, 0, MAX_SIZE-1);
	//mergesortBU(arr, MAX_SIZE);
	//quicksort(arr, 0, MAX_SIZE-1);

}

// Functions Implementation
void InsertionSort(int arr[]) // swaps the element until its correct position
{

	int i = 1;
	int j = 0;
	while (i < MAX_SIZE) 
	{
		j = i;
		while (j > 0) {
			comp_count++;
			if((arr[j - 1] > arr[j]))
			{ 
				swap(arr, j, j - 1);
				exch_count++;
			}
			j--;
		}
		printArray(arr);
		putchar('\n');
		i++;
		
	}
	printf("%d comparisons, %d exhanges \n\n", comp_count, exch_count);
}

void SelectionSort(int arr[])
{
	int i, j, min_index;

	for (i = 0; i < MAX_SIZE - 1; i++) {
		min_index = i;
		for (j = i + 1; j < MAX_SIZE; j++) {
			comp_count++;
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		exch_count++;
		swap(arr, i, min_index);
	}
}

void ShellSort(int arr[]) 
{
	for (int interval = MAX_SIZE / 2; interval > 0; interval /= 2) {
		for (int i = interval; i < MAX_SIZE; i++) {
			int temp = arr[i];
			int j;
			for (j = i; j >= interval && arr[j - interval] > temp; j -= interval)
			{
				arr[j] = arr[j - interval];
				exch_count++;
			}
			arr[j] = temp;
			comp_count++;

		}
	}
	printArray(arr);
	printf("%d comparisons, %d exhanges \n\n", comp_count, exch_count);
}

/*+++++++++++++++++++++++++++++++ Bottom up Merge Sort +++++++++++++++++++++++++++++++++++++++++++++++*/
void mergesortBU(int array[], int arraySize) {

	int currSize;
	int leftStart;

	for (currSize = 1; currSize <= arraySize - 1; currSize = 2 * currSize) {
		for (leftStart = 0; leftStart < arraySize - 1; leftStart += 2 * currSize) {
			int mid = less(leftStart + currSize - 1, arraySize - 1);

			int right_end = less(leftStart + 2 * currSize - 1, arraySize - 1);
			mergeBU(array, leftStart, mid, right_end);
		}
	}
	printArray(array);

}

// Function to merge the two halves of array arr[] 
void mergeBU(int array[], int l, int m, int r) {
	int i, j, k;
	int leftSize = m - l + 1;
	int rightSize = r - m;

	int leftPart[MAX_SIZE], rightPart[MAX_SIZE];

	// Copy data to temp arrays
	for (i = 0; i < leftSize; i++)
		leftPart[i] = array[l + i];
	for (j = 0; j < rightSize; j++)
		rightPart[j] = array[m + 1 + j];

	// Merge the temp arrays back 
	i = 0;
	j = 0;
	k = l;
	while (i < leftSize && j < rightSize) {
		comp_count++;
		if (leftPart[i] <= rightPart[j]) {
			array[k] = leftPart[i];
			i++;
		}
		else {
			array[k] = rightPart[j];
			j++;
		}
		k++;
		exch_count++;
	}

	// Copy the remaining elements of left array, if there are any
	while (i < leftSize) {
		array[k] = leftPart[i];
		i++;
		k++;
	}

	// Copy the remaining elements of right array, if there are any 
	while (j < rightSize) {
		array[k] = rightPart[j];
		j++;
		k++;
	}
	printf("%d comparisons, %d exhanges \n\n", comp_count, exch_count);
}

/*+++++++++++++++++++++++++++++++++++ Quick Sort +++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int partition(int array[], int low, int high) 
{
	
	int pivot = array[high]; // Choose the last element as the pivot
	int i = low - 1; // Index of smaller element

	for (int j = low; j < high; j++) {
		comp_count++;
		if (array[j] < pivot) {
			i++;
			swap(array, i, j);
			exch_count++;
		}
	}
	swap(array, i + 1, high); // Place the pivot in its correct position
	exch_count++;
	printf("%d comparisons, %d exhanges \n\n", comp_count, exch_count);

	return i + 1;
}

void quicksort(int array[], int low, int high) 
{
	if (low < high) {
		// Partition the array and get the pivot index
		int pivotIndex = partition(array, low, high);

		// Recursively sort the subarrays
		quicksort(array, low, pivotIndex - 1);
		quicksort(array, pivotIndex + 1, high);
	}

}

/*+++++++++++++++++++++++++++++++ Merge Sort +++++++++++++++++++++++++++++++++++++++++++++++*/
void mergesort(int array[], int l, int r) {
	if (l >= r)
		return;
	int m = l + (r - l) / 2;
	mergesort(array, l, m);
	mergesort(array, m + 1, r);
	merge(array, l, m, r);

}

// Merges two subarrays of arr[]. First subarray is arr[l..m]. Second subarray is arr[m+1..r]
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

	// Merge the temp arrays back into array
	// Initial index of first subarray
	i = 0;
	// Initial index of second subarray
	j = 0;
	// Initial index of merged subarray
	k = l;

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
		exch_count++;
	}

	// Copy the remaining elements of left array, if there are any
	while (i < leftSize) {
		array[k] = leftArray[i];
		i++;
		k++;
		exch_count++;
	}

	// Copy the remaining elements of right array, if there are any
	while (j < rightSize) {
		array[k] = rightArray[j];
		j++;
		k++;
		exch_count++;
	}
	// prints with every recursive call????????? need only the last value.....
	printf("%d comparisons, %d exhanges \n\n", comp_count, exch_count);
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

// Helper Functions
void swap(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int less(int x, int y)
{
	return (x < y) ? x : y;

}
int isSorted(int array[]) {
	for (int i = 1; i < MAX_SIZE; i++) {
		if (less(array[i], array[i - 1]))
			return 0;
	}
	return 1;
}

void printArray(int arr[])
{
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');
}
