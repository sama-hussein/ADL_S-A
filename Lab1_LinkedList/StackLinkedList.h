/*
Disclaimer: The following functions are just some examples and gimmicks from the lecture.
The functions and the structure of the program do not fully meet the requirements of the
programming guideline. For example, comments, error handling, etc. may be missing.
The following functions are kept quite small, so that they can be clearly
and completely displayed over the beamer in the lecture hall.
If we tried some things live in the lecture, it is even possible
that some program fragments do not compile.
Also some of the functions are not programmed optimally for demonstration purposes.

In our EMIL room you will find the programming guideline and a program
that demonstrates the adherence the programming guideline.
Please adhere to the programming guideline in all your programs
(e.g., for the laboratorys, the exam, etc.).
*/

#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRING 20

typedef struct sCar {
	char brand[MAXSTRING];
	char licensePlate[MAXSTRING];
} sCar;

typedef struct sElement {
	sCar* car;
	struct sElement* prev;
} sElement;

sElement* push(sElement* last);
sElement* pop(sElement* last);
int isEmpty(sElement* last);
int countElements(sElement* last);
void printStack(sElement* last);
