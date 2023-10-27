// Lab1_LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include "StackLinkedList.h"

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


sElement* push(sElement* last) {
	sElement* newElem;
	sCar* newCar;

	newCar = (sElement*)malloc(sizeof(sElement));
	newElem = (sCar*)malloc(sizeof(sCar));

	if (newCar == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	//Linking
	newElem->car = newCar;
	newElem->prev = last;

	//Return
	return newElem;
}

sElement* pop(sElement* last) 
{
	sElement* temp = last;
	last = last -> prev;
	free(temp);
}

//prev of first element must be sit to null
int isEmpty(sElement* last) {
	//if(last == NULL)

	//if last->next == null
}

int countElements(sElement* last) { //only pass the pointer to the last element
	if (isEmpty(last) == 0)
		return 0;
	sElement* temp = last;
	int number = 0;
	while (temp != NULL) {
		number++;
		temp = temp->prev;
	}
	return number;
}

void printStack(sElement* last) {
	if (isEmpty(last) == 0)
		printf("Stack is empty.\n");
		return;
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