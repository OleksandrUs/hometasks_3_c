/*
 * Task2, stack.h
 * Purpose: The header file of the stack library.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 12/08/2021
 */

#ifndef _STACK_H_
#define _STACK_H_

#include <stdint.h>

/*
 * These identifiers are used as codes to identify the result of is_empty() function execution.
 */
#define STACK_IS_EMPTY 0
#define STACK_HAS_ITEMS 1

/*
 * This data structure is used as a wrapper around the useful data (in this case the values of int data type)
 * and it allows to make stack independent from data types stored in it (i.e. a kind of abstraction).
 */
struct DATA
{
        int value;
};

/*
 * This structure describes the element of the stack based on a linked list.
 */
struct STACK
{
        struct DATA data;
        struct STACK *next; 
};

// The prototypes of base functions to work with a stack.
void push(struct STACK **stack, struct DATA data);
struct DATA pop(struct STACK **stack);

// The prototypes of additional functions to work with a stack.
uint8_t is_empty(struct STACK **stack);
struct DATA peek(struct STACK **stack);
size_t get_stack_size(struct STACK **stack);
void clear_stack(struct STACK **stack);

#endif