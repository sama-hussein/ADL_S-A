// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// Function keeps swaping the value k with each element until the end of the array
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


int main() {
    
    int arr[MAX_SIZE];
    int k = 3;

    initArray(arr, k);
    putchar('\n');

    // Print the modified array
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}


