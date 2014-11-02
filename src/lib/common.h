#ifndef _LIBCOMMON_H_
#define _LIBCOMMON_H_

	# include "linkedlist.h"

	// Detects whether or not a number n is multiple of a number m
	long isMultiple(long n,long m);

	// Returns an array containing the prime factorization of a number
	list* factors(long n);

	// gets the long value stored at a void pointer location
	long getLongData(void *data);

#endif
