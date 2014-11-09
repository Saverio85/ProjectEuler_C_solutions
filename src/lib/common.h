#ifndef _LIBCOMMON_H_
#define _LIBCOMMON_H_

	# include "linkedlist.h"

	int maxInt(int a, int b);

	// Detects whether or not a number n is multiple of a number m
	long isMultiple(long n,long m);

	// Returns an array containing the prime factorization of a number
	list* factors(long n);

	// gets the long value stored at a void pointer location
	long getLongData(void *data);

	// return the maximum element in the array
	int maxIntArray(int* arr, int size);

	//print the int array
	void printIntArray(int* arr, int size);

	// return the maximum element in the array
	int maxLongArray(long* arr, int size);

	//print the int array
	void printLongArray(long* arr, int size);

	//modifies arr to contain a count of how many times each element in lst appears
	// !!!!! only works for longs
	void aggregateList(list *lst, int arr[]);

	//sum using strings
	char *sum(char *a, char *b);

	// creates a new string and initializes it with several zeroes
	char *createAndInitialize(int n);

	char getValue(char *str, int n);

	int getMaxLength(char *a, char *b);
	char *trimLeadingZeroes(char *str);

	// scalar product of a string (our bigint) times an integer
	char* scalarProduct(char *a, int n);
	// generate the zero string for our simple bigint implementation
	char *zeroString();
	// computes the factorial of a number in our bigint implementation
	char* factorial(int n);

#endif
