
#include "HashCHLib.h"

/*
Function reads an integer value safely from the keyboard.

Return value:
Read integer value
*/
int readInt() {
	int number, test = 0;
	do {
		test = scanf_s("%d", &number);
		if (test != 1) {
			while (getchar() != '\n');
			printf("Wrong input. Try again.\n");
		}
		else
			return number;
	} while (1);
}

/*
Function calculates the hash value for the passed key.

Input parameters:
key: The integer for which the hash value should be calculated.

Return value:
Calculated hash value for parameter key.
*/
//Todo: Assignment 2, think about other options for calculating the hash value
int hashing(int key) {
	// Choose one of the alternative hash functions
	// return multiplicativeHashing(key);
	// return foldingHashing(key);
	//return xorHashing(key);
	return divisionHashing(key);
}

int divisionHashing(int key) {
	return key % MAX_ARRAY;
}

int foldingHashing(int key) {
	int sum = 0;
	while (key > 0) {
		sum += key % 1000; // Extract a three-digit portion
		key /= 1000; // Move to the next portion
	}
	return sum % MAX_ARRAY;
}

int xorHashing(int key) {
	key = (key >> 16) ^ key; // XOR upper and lower 16 bits
	key = (key >> 8) ^ key;  // XOR upper and lower 8 bits
	return key % MAX_ARRAY;
}

int multiplicativeHashing(int key) {
	const double A = 0.6180339887; // Golden ratio constant
	double fraction = key * A - (int)(key * A); // Extract fractional part
	return (int)(MAX_ARRAY * fraction);
}


/**********************************************************************************************************************
Prototypes for address hashing
**********************************************************************************************************************/
/*
Function creates a new entry in the hash table or if the key already exists overwrites the value with the passed value.

Input parameters:
hashtableAH: Function gets a hash table.
key: The key that should be inserted.
value: The value for the key that should be inserted.

Return value:
Function returns the number of collisions when inserting the key-value pair.
*/

// Function to create a new entry in the hash table using chained hashing
// If a collision is detected, adds the new entry as the first element in the linked list
int putCH(sElementCH* hashtableCH[MAX_ARRAY], int key, char value[MAX_STRING]) {
	int index = hashing(key);
	int collisions = 0;

	// Create a new element
	sElementCH* newElement = (sElementCH*)malloc(sizeof(sElementCH));
	if (newElement == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}

	newElement->key = key;
	strcpy(newElement->value, value);
	newElement->next = NULL;

	// Insert the new element into the linked list at the specified index
	if (hashtableCH[index] == NULL) {
		// No collision, the list is empty at this index
		hashtableCH[index] = newElement;
	}
	else {
		// Collision, add the new element to the beginning of the list
		newElement->next = hashtableCH[index];
		hashtableCH[index] = newElement;
		collisions++;
	}
	return collisions;
}

// Function to search for the entry in the hash table with chained hashing
// Returns the value of the entry or NULL if the key does not exist
char* getCH(sElementCH* hashtableCH[MAX_ARRAY], int key) {
	int index = hashing(key);

	// Traverse the linked list at the specified index
	sElementCH* current = hashtableCH[index];
	while (current != NULL) {
		if (current->key == key) {
			// Key found, return the value
			return current->value;
		}
		current = current->next;
	}

	// Key not found
	return NULL;
}

// Function to print the hash table with chained hashing
void printHashTableCH(sElementCH* hashtableCH[MAX_ARRAY]) {
	printf("Chained Hash Table:\n");
	for (int i = 0; i < MAX_ARRAY; i++) {
		printf("Index %d:", i);
		if (hashtableCH[i] == NULL) {
			printf(" empty\n");
		}
		else {
			sElementCH* current = hashtableCH[i];
			while (current != NULL) {
				printf(" Key: %d, Value: %s ->", current->key, current->value);
				current = current->next;
			}
			printf(" NULL\n");
		}
	}
}

void readCSVAH(FILE* fP, sElementCH* hashtableCH[MAX_ARRAY]) {
	int number = 0;
	char buffer[MAX_STRING];
	char* field;
	int key;
	char string[MAX_STRING];

	if (fP == NULL) {
		printf("File does not exist.");
		exit(0);
	}
	else {
		// Get number of lines
		while (fgets(buffer, MAX_STRING, fP) != NULL) {
			number++;
		}
		rewind(fP);
		printf("Number: %d\n", number);
	}

	for (int i = 0; i < MAX_ARRAY; i++) {
		hashtableCH[i] = NULL; // Initialize each element in the array to NULL
	}

	for (int i = 0; i < number; i++) {
		fgets(buffer, MAX_STRING, fP);

		field = strtok(buffer, ";");
		key = atoi(field);

		field = strtok(NULL, ";");
		strcpy(string, field);
		// Replace \n in name
		string[strlen(string) - 1] = '\0';

		// Insert data into the hash table using chained hashing
		putCH(hashtableCH, key, string);
	}
	return;
}

