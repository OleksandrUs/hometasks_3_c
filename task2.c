/*
 * Task2, task2.c
 * Purpose: write a stack library based on a linked list. Minimum set of
 * operations: push(), pop().
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 23/08/2021
 */

#include <stdio.h>
#include "stack.h"

/*
 * Function prototype.
 */
void run_demo(void);

/*
 * The main function of the program.
 * Demonstration of using the stack library functions.
 * 
 * @param argc the number of command line arguments
 * @param argv the array that contains passed command line arguments
 * @return 0 if successful
 */
int main(int argc, char *argv[])
{
        run_demo();
        return 0;
}

/*
 * This function demonstrates the usage of the stack library functions and prints
 * the results of their callings and some additional information in the console window. 
 */
void run_demo(void)
{
        struct STACK *stack = NULL;
        struct DATA data;

        const int N = 10;

        // Add 10 items to the stack.
        printf("Calling push() function for %d times.\n", N);
        for(int i = 0; i < N; i++){
                data.value = i;
                push(&stack, data);
        }
       
        // Check if the items were added (i.e. the stack is not empty).
        printf("\nCalling is_empty() function to check if the stack is empty.\n");
        if(is_empty(&stack) == STACK_IS_EMPTY){
                printf("Stack is empty.\n");
        } else {
                printf("Stack is not empty.\n");
        }

        // Get the stack size.
        printf("\nCalling get_stack_size() function.\n");
        printf("Stack contains %ld elements.\n", get_stack_size(&stack));

        // Read twice an item that is on the top of the stack. The item should not be removed 
        // from the stack.
        printf("\nCalling peek() function for 2 times.\n");
        printf("%d\n", peek(&stack).value);
        printf("%d\n", peek(&stack).value);

        // Check if the stack size remains the same after calling peek() function. 
        printf("\nCalling get_stack_size() function.\n");
        printf("Stack contains %ld elements.\n", get_stack_size(&stack));

        // Remove items from the stack until it is not empty and print it.
        printf("\nCalling pop() function until the stack is empty.\n");
        while(is_empty(&stack) != STACK_IS_EMPTY){
                printf("%d\n", pop(&stack).value);
        }

        // Check if all elements were removed and number of elements in the stack is 0.
        printf("\nCalling get_stack_size() function.\n");
        printf("Stack contains %ld elements.\n", get_stack_size(&stack));

        // Check if the stack is empty.
        printf("\nCalling is_empty() function to check if the stack is empty.\n");
        if(is_empty(&stack) == STACK_IS_EMPTY){
                printf("Stack is empty.\n");
        } else {
                printf("Stack is not empty.\n");
        }

        // Add 10 items to the stack again.
        printf("\nCalling push() function for %d times.\n", N);
        for(int i = 0; i < N; i++){
                data.value = i;
                push(&stack, data);
        }

        // Check if the elements were added and the stack is not empty.
        printf("\nCalling is_empty() function to check if the stack is empty.\n");
        if(is_empty(&stack) == STACK_IS_EMPTY){
                printf("Stack is empty.\n");
        } else {
                printf("Stack is not empty.\n");
        }
        
        // Get the number of elements in the stack.
        printf("\nCalling get_stack_size() function.\n");
        printf("Stack contains %ld elements.\n", get_stack_size(&stack));

        // Clear stack (remove all the elements).
        printf("\nCalling clear_stack() function\n");
        clear_stack(&stack);

        // Get the numer of elements in the stack (must be 0).
        printf("\nCalling get_stack_size() function.\n");
        printf("Stack contains %ld elements.\n", get_stack_size(&stack));
      
        // Check if the stack is empty.
        printf("\nCalling is_empty() function to check if the stack is empty.\n");
        if(is_empty(&stack) == STACK_IS_EMPTY){
                printf("Stack is empty.\n");
        } else {
                printf("Stack is not empty.\n");
        }

        // Remove items from the stack until it is not empty and print it
        // (the stack is empty now and there should not be any items popped from the stack).
        printf("\nCalling pop() function until the stack is empty.\n");
        while(is_empty(&stack) != STACK_IS_EMPTY){
                printf("%d\n", pop(&stack).value);
        }
}