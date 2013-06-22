/*
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 *	Filename:	ByteFunctions.h
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Predeclare functions that convert values in byte form.
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 *	Author:		Jonathan Burrows
 *	Date:		Nov 20 2012
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 *	References:	byte.h
 *	Dependancy:	stdlib.h
 *				stdio.h
 *				string.h
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
*/
#ifndef BYTE_FUNCTIONS_H
#define BYTE_FUNCTIONS_H 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Byte.h"

/*
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 *	Subroutine:	print_byte_list
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Prints out a list of byte's bit contents.
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 */
void print_byte_list(byte* head);

/*
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	decimal_to_bits
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Returns the 8 rightmost bits of a decimal, in a character array.
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 */
char* decimal_to_bits(int* decimal);

/*
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	int_to_byte_string
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Converts a decimal into a linked list of binary bytes and return the reference to the start of the list.
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 */
byte* int_to_byte_string(int decimal, int byte_len);

/*
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Converts a string of characters into a linked list of binary bits and returns the reference to the
 *              start of the list.
 === === === === === === === === === === === === === === === === === === === === === === === === === === === === === ===
 */
byte* string_to_byte_string(char* word, int byte_len);


#endif
