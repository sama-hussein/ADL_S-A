#pragma once

#include "HashAHLib.h"

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
int hashing(int key) 
{
	return key % MAX_ARRAY;  //address = key mod n
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
int putAH(sElementAH hashtableAH[MAX_ARRAY], int key, char value[MAX_STRING]) {
	//Todo: Assignment 1.1
	int index = hashing(key);

	// Check if the key already exists in the hash table
	if (hashtableAH[index].key == key) {
		// Key already exists, overwrite the value
		strcpy(hashtableAH[index].value, value);
		return 0; // No collisions
	}
	else {
		// Handle collisions (linear probing)
		while (hashtableAH[index].key != -1) {
			index = (index + 1) % MAX_ARRAY;
		}

		// Insert the key-value pair
		hashtableAH[index].key = key;
		strcpy(hashtableAH[index].value, value);

		return 1; // Number of collisions
	}

}

/*
Function searches for the key-value pair in the hash table having the passed key.

Input parameters:
hashtableAH: Function gets a hash table.
key: The key that should be searched for in the hash table.

Return value:
Function returns the value of entry with the given key or NULL if the key does not exist in the hash table.
*/
char* getAH(sElementAH hashtableAH[MAX_ARRAY], int key) {
	//Todo: Assignment 1.2
	int index = hashing(key);

	// Search for the key
	while (hashtableAH[index].key != -1) {    // checking if the current entry in the hash table is not marked as empty
		if (hashtableAH[index].key == key) {
			return hashtableAH[index].value; // Key found
		}
		index = (index + 1) % MAX_ARRAY;
	}

	return NULL; // Key not found
}

/*
Function searches for the entry in the hash table having the passed key.
If it finds an entry the function deletes it from the hash table.

Input parameters:
hashtableAH: Function gets a hash table.
key: The key that should be searched for in the hash table and whose key-value pair should be deleted.

Return value:
none
*/
void deleteAH(sElementAH hashtableAH[MAX_ARRAY], int key) {
	//Todo: Assignment 1.3
	int index = hashing(key);

	// Search for the key
	while (hashtableAH[index].key != -1) {
		if (hashtableAH[index].key == key) {
			// Delete the key-value pair by marking the entry as unused
			hashtableAH[index].key = -1;
			hashtableAH[index].value[0] = '\0'; // Clear the value
			return;
		}
		index = (index + 1) % MAX_ARRAY;
	}
}

/*
Function prints the hash table on the console.

Input parameters:
hashtableAH: Function gets a hash table.

Return value:
none
*/
void printHashTableAH(sElementAH hashtableAH[MAX_ARRAY]) {
	//Todo: Assignment 1.4
	printf("Hash Table:\n");
	for (int i = 0; i < MAX_ARRAY; i++) {
		if (hashtableAH[i].key != -1) {
			printf("Index %d: Key: %d, Value: %s\n", i, hashtableAH[i].key, hashtableAH[i].value);
		}
	}
	printf("\n");
}

/*
Function reads key-value pairs from a csv-files and stores these pairs in a hash table.

Input parameters:
fp: Function gets a file pointer to a csv-file which contains some key-value-pairs.
hashtableAH: Function gets a hash table.

Return value:
none
*/
void readCSVAH(FILE* fP, sElementAH hashtableAH[MAX_ARRAY]) {
	int number = 0;
	char buffer[MAX_LINE];
	char* field;
	char* nextToken = NULL;
	int key;
	char string[MAX_STRING];


	if (fP == NULL) {
		printf("File does not exist.");
		exit(0);
	}
	else
		// Get number of lines
		while (!feof(fP)) {
			char ch = fgetc(fP);
			if (ch == '\n')
				number++;
		}

	if (fP != NULL)
		rewind(fP);

	for (int i = 0; i < number; i++) {
		fgets(buffer, MAX_LINE, fP);


		field = strtok_s(buffer, ";", &nextToken);
		key = atoi(field);

		field = strtok_s(NULL, ";", &nextToken);
		strcpy_s(string, MAX_STRING, field);
		//replace \n in name
		string[strlen(string) - 1] = '\0';

		putAH(hashtableAH, key, string);
	}

	return;
}
