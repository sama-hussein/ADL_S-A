// Lab1_LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "StackLinkedList.h"
//#include <stdio.h>
//#include <stdlib.h>

int main()
{
	sElement* last = NULL;

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
			last = push(last);
			break;
		case 2:
			last = pop(last);
			break;
		case 3:
			number = countElements(last);
			printf("The stack has %d elements.\n\n", number);
			break;
		case 4:
			printStack(last);
			break;
		default:
			return 0;
		}
	}
	return 0;
}

sElement* push(sElement* last) 
{	
	// Create a new car
	sCar* newCar = (sCar*)malloc(sizeof(sCar));
	if (newCar == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	sElement* newElem;
	newElem = (sElement*)malloc(sizeof(sElement));
	if (newElem == NULL) 
	{
		printf("Memory allocation failed\n");
		exit(0);
	}
	// Prompt the user for input
	printf("Enter brand: ");
	scanf("%s", newCar->brand);
	printf("Enter license plate: ");
	scanf("%s", newCar->licensePlate);
	//Linking
	newElem->car = newCar;
	newElem->prev = last;
	return newElem;
}

sElement* pop(sElement* last) 
{
	if (isEmpty(last) == 0) {
		printf("Stack is emtpy\n\n");
		return NULL;
	}
	// Print last element
	printf("Last element:\n");
	printf("Brand: %s\n", last->car->brand);
	printf("License Plate: %s\n", last->car->licensePlate);
	// Remove the last element
	sElement* newLast = last->prev;
	free(last->car);
	free(last);
	return newLast;
}

int isEmpty(sElement* last) {
	if (last == NULL)
		return 0;
	else
		return 1;
}

int countElements(sElement* last) { 
	// First, check whether the list is empty or not
	if (isEmpty(last) == 0)
	{
		printf("Stack is empty");
		return 0;
	}
	int cnt = 0;
	sElement* temp = last;
	while (temp != NULL)
	{
		cnt++;
		temp = temp->prev;
	}
	return cnt;
}

void printStack(sElement* last) {
	//printf("Hiiiiiiiiiiiiiiiiiiiii");
	if (isEmpty(last) == 0)
	{
		printf("Stack is empty.\n");
		return;
	}
	sElement* temp = last;
	int number = countElements(last);
	while (temp != NULL) {
		printf("The car %d is:\n", number);
		printf("Brand: %s\n", temp->car->brand);
		printf("License Plate: %s\n\n", temp->car->licensePlate);
		temp = temp->prev;
		number--;
	}
}