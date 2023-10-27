#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRING 20
#define MAXARRAY 50

typedef struct sCar { // 40 bytes
	char brand[MAXSTRING];
	char licensePlate[MAXSTRING];
} sCar;

void push(sCar* array[]);
void pop(sCar* array[]);
int isEmpty(sCar* array[]);
int countElements(sCar* array[]);
void printStack(sCar* array[]);

