/*
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Filename:	ByteFunctions.c	
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Author:		Jonathan Burrows
 *	Date:		November 15th 2012
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	References:	ByteFunction.h,		Header file for this c code.
 *				Byte.h,				byte struct.
 *	Dependancy:	stdlib.h,			decimal_to_bytes	int_to_byte_string.
 *				stdio.h,			print_byte_list.
 *				string.h,			print_byte_list.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 */
#include "ByteFunctions.h"

/*
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Subroutine:	print_byte_list
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 * 	Purpose:	Print out an list of byte's bit contents.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	@param:		head,	the starting node of the linked list of bytes that will be printed.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Algorithm:	Starting at the head, the list is traversed until the conductor reads NULL. Every bytes character
 *				string of bits is printed to screen.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	References:	Bytes.h		byte struct.
 *	Dependancy:	stdlib.h	NULL value.
 *				stdio.h		fprintf function
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 */
void print_byte_list(byte* head){
	byte* conductor;										/*Used to transverse the list.*/
	
	/*	Staring from the head of the list, the elements of the list are printed to the screen sequencially.	*/
	conductor = head;
	/*	Continues to get next element in the list until the end is reached.	*/
	while(conductor!=NULL){
		fprintf(stdout, "%s ",conductor->bits);				/*Prints the string of bits to the screen.*/
		conductor = conductor->next;
	}
}

/*
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== 
 *	Function:	decimal_to_bits
 *	Purpose:	Returns the 8 leftmost bits of a decimal in a character array.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== 
 *	@param:		decimal, 	a reference to a decimal number whos rightmost 8 bits will be stored in an character array.
 *	@return		bits, 		an array of characters whos contents match the rightmost bits of a decimals binary digits. 
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Algorithm:	For eight itterations, the decimal is checked to see if it is one. If it is, the rightmost digit
 *				is a zero, otherwise, it is z one. The character representation is put into the furthest unfilled spot
 *				of the character array bits. The decimal is logically left shifted by 1 bit. Once 8 itterations have
 *				been made, the character array is ended with a null character and returned.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Notes:		In order to get the bits in correct order of significance, the bits must be added from the end of the
 *				array, with still room for the null character.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Dependancy:	stdlib,		malloc for character array		value of NULL
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 */
char* decimal_to_bits(int* decimal){
	char* bits;											/*The array where the decimals bit values will be stored.*/
	int i;												/*Used in loop control.*/
	
	/*	Attempts to allocate memory for bits plus a null character, if not possible, NULL is returned.	*/
	if((bits = malloc(9*sizeof(char)))==NULL){				/*Room for the 8 bits plus a null terminator*/
		return NULL;
	}
	
	/*	Starting from the end of the array and least significant digit, the 8 most rightmost bits character values
	 *	are stored in bits.	*/
	for(i=7; i >= 0; i--){
		/*	Since the integer values must be converted to character, the last bit value is checked against one*/
		if( ( (*decimal) & 1) == 0){
			bits[i]	= '0';								/*Zero character is stored if bit is not one.*/
		}
		else{
			bits[i]	= '1';								/*One character is stored if bit is zero.*/
		}
		/*	Decimal is logically left shifted by 1 bit.	*/
		(*decimal)	>>= 1;
	}
	
	/*	Character array is ended with a null character.	*/
	bits[8] = '\0';
	
	return bits;
}

/*
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Function:	int_to_byte_string
 *	Purpose:	Converts a decimal into a linked list of binary bytes and return the reference to the start of the list.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	@param:		decimal, 	the value whos bit value will be stored in the bits of the list.
 *				byte_len,	the length of the list that will be returned.
 *	@return:	head,		a reference to the head of the linked list of bytes that was created.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Algorithm:	3 pointers are made for a linked list. If list size is greater than zero, a new byte is made, and 
 *				the tail and head are pointed to it. Links then are continously added to the front of the list until
 *				the list size matches byte_len. Each itteration creates a new node whos next is head, and the head's 
 *				prev is it. The head of the list is then returned.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Notes:		To get the list of bytes in the correct order of significance, the list must be a doubly linked list, 
 *				and characters must be added to the front of the list.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	References:	decimal_to_bytes, 	Constructing the new bytes character componets.
 *				Byte.h,				byte struct.
 *	Dependancy:	stdlib.h			malloc of bytes for the list	value of NULL.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 */
byte* int_to_byte_string(int decimal, int byte_len){
	byte *head, *tail, *current;						/*Pointers for the list of bytes.*/
	int i;												/*Loop control.*/
	
	/*	The size is checked to be greater than zero.	*/
	if(byte_len > 0){
		/*	The first byte in the list is added.	*/
		current = malloc(sizeof(byte));
		current->bits = decimal_to_bits(&decimal);
		current->next = NULL;
		current->prev = NULL;
		head = current;
		tail = current;
	}
	
	/*	The rest of the nodes are added, starting from the end, until the length of the list matches byte_len.	*/
	for(i=1; i<byte_len; i++){
		/*	A new node is created and added to the front of the list.	*/
		current = malloc(sizeof(byte));
		current->bits = decimal_to_bits(&decimal);
		current->prev = NULL;
		current->next = head;
		
		head->prev = current;
		head = current;
	}
	/*	The first node in the list is returned.	*/
	return head;
}

/*
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Function:	string_to_byte_string
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Purpose:	Converts a string of characters into a linked list of binary bits and returns the reference to the
 *				start of the list.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	@param:		word,	the string of characters that will be converted into a linked list of bytes.
 *				byte_len, the length of the linked list that will be made.
 *	@return:	head, a reference to the start of the linked list who holds the byte value of the given word.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Algorithm:	A linked list head and current are declared with the heads bit value equal to the integer value of the
 *				words value at the first position. Until the list is of size byte_len, links are added to the end of
 *				with byte values equal to the integer values of the character at the current position in the word.
 *				A reference to the head of the list is then returned.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Notes:		There is a chance that the word's size is less than the byte_len. For that reason, if the position of
 *				the list trying to be filled is greater or equal to the size, the value is simply zero.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 *	Reference:	Byte.h,		byte struct.
 *	Dependancy:	stdlib.h,	malloc of the bytes,		NULL value.
 ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
 */
byte* string_to_byte_string(char* word, int byte_len){
	byte* head, *tail, *current;						/*Pointers used in the linked list.*/
	int curr_character_value;							/*Holds the integer value of a single character from the word*/
	int i;												/*Used for loop control.*/
	/*	Checks to make sure the desired list is not empty, and there is a first character.	*/
	if(byte_len > 0 && strlen(word) > 0){
	
		/*	The integer value of the letter at position byte_len in the word is stored-1 in curr_character_value.	*/
		/*	It is checked to see if there is a letter at position byte_len-1 in the word.	*/
		if(i < strlen(word)){
			/*	The integer value of the character is stored in curr_character_value	*/
			curr_character_value = 0;
			
		}
		else{
			/*	Otherwise there is not a letter, it is given a value of zero.	*/
			curr_character_value = (int) word[0];
		}
		/*	Initialises the list and sets the tail.	*/
		current = malloc(sizeof(byte));
		current->bits = decimal_to_bits(&curr_character_value);
		current->next = NULL;
		current->prev = NULL;
		
		head = current;
		tail = current;
	}
	/*	Adds links to the front of the list until the list is of size byte_len	*/
	for(i = 1; i < byte_len; i++){
	
		/*	The integer value of the letter at position i in the word is stored in curr_character_value.	*/
		/*	It is checked to see if there is a letter at position i in the word.	*/
		if(i < strlen(word)){
			/*	The integer value of the character is stored in curr_character_value	*/
			curr_character_value = (int) word[i];
		}
		else{
			/*	Otherwise there is not a letter, it is given a value of zero.	*/
			curr_character_value = 0;
		}
		
		/*	A new node is added to the end of the list.	*/
		current = malloc(sizeof(byte));
		current->bits = decimal_to_bits(&curr_character_value);
		current->next = NULL;
		current->prev = tail;
		
		tail->next = current;
		tail = current;
	}
	
	/*	The start of the linked list is returned.	*/
	return head;
}

