#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

void initArray(int arr[]) {
    // Initialize the array with values from 1 to MAX_SIZE in ascending order
    for (int i = 0; i < MAX_SIZE; i++) {
        int j = rand() % MAX_SIZE;
        for (int x = 0; x < i; x++)
        {
            if (arr[x] == j)
                break;
            arr[i] = j;
        }
    }
}


    int main() {
        int myArray[MAX_SIZE];
        //int k = 5; // You can change this value to specify how many elements should be unsorted

        initArray(myArray);

        // Print the initialized array
        printf("Initialized Array: ");
        for (int i = 0; i < MAX_SIZE; i++) {
            printf("%d ", myArray[i]);
        }
        printf("\n");

        return 0;
    }