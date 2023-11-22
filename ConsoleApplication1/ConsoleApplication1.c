#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
#pragma once

void swap(int array[], int i, int j);
void initArray(int array[], int k);

int main() {
    int array[MAX_SIZE];
    int k = 5; // You can change k to any value

    initArray(array, k);

    // Print the initialized array
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}


void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void initArray(int array[], int k) {
    for (int i = 0; i < MAX_SIZE; i++) {
        array[i] = i + 1;
    }

    if (k >= MAX_SIZE) {
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE - k; i++) {
        int randomIndex = i + rand() % (MAX_SIZE - i);
        swap(array, i, randomIndex);
    }
}