// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
#define K 5         // not required in the lab, but necessary for the code to work!


void moveElementsToEnd(int arr[], int indices[], int numIndices) {
    int size = MAX_SIZE;
    for (int i = 0; i < numIndices; i++) {
        int sourceIndex = indices[i];

        // Save the element to be moved
        int elementToMove = arr[sourceIndex];

        // Shift the elements to make space for the element to be moved
        for (int j = sourceIndex; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }

        // Place the element at the end
        arr[size - 1] = elementToMove;

        // Adjust the size since the element is moved to the end
        size--;
    }
}


void initArray(int arr[])
{
    int size = MAX_SIZE;

    // Initializing the array
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
    int indicesToMove[K]; // Array of K elements to be removed.

    // Generating the random indices of elements to move to the end
    srand((unsigned)time(NULL));

    int x = 0;
    for (int i = 0; i < K ; i++) {
        indicesToMove[i] = rand() % (MAX_SIZE - x);
        x++;
        printf("%d ", indicesToMove[i]);
    }

    int numIndices = sizeof(indicesToMove) / sizeof(indicesToMove[0]);

    moveElementsToEnd(arr, indicesToMove, numIndices);

}


int main() {
    
    int arr[MAX_SIZE];

    initArray(arr);
    putchar('\n');

    // Print the modified array
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}


