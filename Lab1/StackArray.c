#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

int main()
{
	sCar* stack[MAXARRAY];
	for (int i = 0; i < MAXARRAY; i++) 
		stack[i] = NULL;

	int choice;
	int number = 0;

	printf("Welcome to our stack program!\n\n");

	while (1) {
		printf("What would you like to do next?\n");
		printf("\t1: Push new element on the stack\n");
		printf("\t2: Pop element from the stack\n");
		printf("\t3: Count elements in the stack\n");
		printf("\t4: Print stack\n");
		printf("Press any other key to exit this program.\n");

		if (scanf("%d", &choice) != 1)
			return 0;

		switch (choice) {
		case 1:
			push(stack);
			break;
		case 2:
			pop(stack);
			break;
		case 3:
			number = countElements(stack);
			printf("The stack has %d elements.\n\n", number);
			break;
		case 4:
			printStack(stack);
			break;
		default:
			return 0;
		}
	}
	return 0;

}

// Pushing new elements to the stack
void push(sCar* stack[]) {
	int number = countElements(stack);
	if (number >= MAXARRAY)
		printf("Stack is full");

	for (int i = 0; i < MAXARRAY; i++)
	{
		if (stack[i] == NULL)
		{
			// Allocate memory for the new element first
			stack[i] = (sCar*)malloc(sizeof(sCar));
			if (stack[i] == NULL)
			{
				printf("Memory allocation failed\n");
				exit(1);
			}
			// Prompt the user for input
			printf("Enter brand: ");
			scanf("%s", stack[i]->brand);  // Arrow operator not dot...

			printf("Enter license plate: ");
			scanf("%s", stack[i]->licensePlate);

			break; // Exit the loop after allocating memory and getting input
		}
	}
}

// Deleting elements from the end of the array
void pop(sCar* stack[]) 
{
	// No need for a loop
	int number = countElements;
	if (isEmpty(stack))
	{
		printf("Cannot pop from an empty stack\n");
		exit(1);
	} 
	else 
	{
		printf("Brand removed: %s\n", stack[number - 1]->brand);
		printf("License Plate removed: %s\n\n", stack[number - 1]->licensePlate);
		free(stack[number - 1]);  // To actually remove the element and free the memory
		stack[number - 1] = NULL; // To not cause a dangling pointer..
	}
}

// Checks if the stack is empty
int isEmpty(sCar* stack[]) 
{
	for (int i = 0; i < MAXARRAY; i++) 
	{
		if (stack[i] != NULL)
			return 0; // Stack is not empty, return false (0)
	}
	printf("Stack is Empty\n");
	return 1; // Stack is empty, return true (1)
}

// Counts the number of elements in thes stack
int countElements(sCar* stack[]) {
	int cnt = 0;
	for (int i = 0; stack[i] != NULL; i++)
		cnt++;
	return cnt;
}

void printStack(sCar* stack[]) {
	int number = countElements(stack);
	if (number == 0)
		printf("\n!!!!!!!Stack is empty.!!!!!!!!\n");
	number--;
	while ((number >= 0) && (stack[number] != NULL)) {
		printf("-------------------------------------------------\n");
		printf("The car %d is:\n", number + 1);
		printf("Brand: %s\n", stack[number]->brand);
		printf("License Plate: %s\n\n", stack[number]->licensePlate);
		number--;
	}
}