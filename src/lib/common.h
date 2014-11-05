#ifndef _LIBCOMMON_H_
#define _LIBCOMMON_H_

	# include "linkedlist.h"

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

#endif
