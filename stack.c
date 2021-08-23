/*
 * Task2, stack.c
 * Purpose: The implementation of the stack library functions.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 23/08/2021
 */

#include <stdlib.h>
#include "stack.h"

/*
 * The function adds a new element to the stack and this element becomes
 * the head of the stack. The memory for storing the new element is allocated
 * dynamically.
 * 
 * @param stack is the pointer to the pointer to the head of the stack
 * @param data is the instance of the DATA structure that contains a value that will be added to the stack
 */
void push(struct STACK **stack, struct DATA data)
{
        if(*stack == NULL){
                *stack = malloc(sizeof(struct STACK));
                (*stack)->next = NULL;
                (*stack)->data = data;
        } else {
                struct STACK *temp;
                temp = malloc(sizeof(struct STACK));
                temp->next = *stack;
                temp->data = data;
                *stack = temp;
        }
}

/*
 * The function removes an element from the stack and the previous element becomes
 * the head of the stack. The memory used for storing this element will be freed.
 * 
 * @param stack is the pointer to the pointer to the head of the stack
 * @return the instance of the DATA structure that contains a value 
 * that has been removed from the stack
 */
struct DATA pop(struct STACK **stack)
{
        struct DATA data = {0};

        if((stack != NULL) && ((*stack) != NULL)){
                data = (*stack)->data;
                struct STACK *temp = (*stack);
                (*stack) = (*stack)->next;
                free(temp);
        }
       
        return data;
}

/*
 * The function checks if there are some elements (items) in the stack.
 * 
 * @param stack is the pointer to the pointer to the head of the stack
 * @return STACK_HAS_ITEMS if the stack is not empty and contains at least one element,
 * otherwise returns STACK_IS_EMPTY
 */
uint8_t is_empty(struct STACK **stack)
{
        if(*stack != NULL) {
                return STACK_HAS_ITEMS;
        }
        return STACK_IS_EMPTY;
}

/*
 * The function returns an element (item) that is on the top of the stack 
 * but NOT removes it from the stack.
 * 
 * @param stack is the pointer to the pointer to the head of the stack
 * @return the instance of the DATA structure that contains useful data 
 * and is on the top of the stack
 */
struct DATA peek(struct STACK **stack)
{
        struct DATA data = {0};

        if((stack != NULL) && ((*stack) != NULL)){
                data = (*stack)->data;
        }
       
        return data;
}

/*
 * The function returns the number of elements that are in the stack.
 * 
 * @param stack is the pointer to the pointer to the head of the stack
 * @return the amount of elements that stored in the stack
 */
size_t get_stack_size(struct STACK **stack)
{
        size_t size = 0;
        struct STACK *head = *stack;
        while(head != NULL){
                size++;
                head = head->next;
        }
        return size;
}

/*
 * The function removes all the elements from the stack. After calling this function
 * the stack size (i.e. the number of elements in it) will be 0. Dynamically allocated 
 * memory for storing the elements in the stack will be freed.
 * 
 * @param stack is the pointer to the pointer to the head of the stack
 */
void clear_stack(struct STACK **stack)
{
        if((stack != NULL) && ((*stack) != NULL)){
                while(is_empty(stack) != STACK_IS_EMPTY){
                        pop(stack);
                }
        }
}