/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

void initArray(int arr[], int k) {
    // Initialize the array with values from 1 to MAX_SIZE in ascending order
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = i + 1;
    }

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Shuffle the array to randomize the order of the elements
    for (int i = 0; i < MAX_SIZE; i++) {
        int j = rand() % MAX_SIZE;
        // Swap elements arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int temp;
    for (int i = 0; i < MAX_SIZE - k; i++) {
        for (int j = 0; j < MAX_SIZE - i - k; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}

int main() {
    int myArray[MAX_SIZE];
    int k = 5; // You can change this value to specify how many elements should be unsorted

    initArray(myArray, k);

    // Print the initialized array
    printf("Initialized Array: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    return 0;
}
*/