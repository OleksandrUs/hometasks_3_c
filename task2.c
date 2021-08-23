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
void run_demo();

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
void run_demo()
{
        struct STACK *stack = NULL;
        struct DATA data;

        const int N = 10;

        printf("Calling push() function for %d times.\n", N);
        for(int i = 0; i < N; i++){
                data.value = i;
                push(&stack, data);
        }
       
        printf("\nCalling is_empty() function to check if the stack is empty.\n");
        if(is_empty(&stack) == STACK_IS_EMPTY){
                printf("Stack is empty.\n");
        } else {
                printf("Stack is not empty.\n");
        }

        printf("\nCalling get_stack_size() function.\n");
        printf("Stack contains %d elements.\n", get_stack_size(&stack));

        printf("\nCalling peek() function for 2 times.\n");
        printf("%d\n", peek(&stack).value);
        printf("%d\n", peek(&stack).value);


        printf("\nCalling get_stack_size() function.\n");
        printf("Stack contains %d elements.\n", get_stack_size(&stack));

        printf("\nCalling pop() function until the stack is empty.\n");
        while(is_empty(&stack) != STACK_IS_EMPTY){
                printf("%d\n", pop(&stack).value);
        }

        printf("\nCalling get_stack_size() function.\n");
        printf("Stack contains %d elements.\n", get_stack_size(&stack));

        printf("\nCalling is_empty() function to check if the stack is empty.\n");
        if(is_empty(&stack) == STACK_IS_EMPTY){
                printf("Stack is empty.\n");
        } else {
                printf("Stack is not empty.\n");
        }

        printf("\nCalling push() function for %d times.\n", N);
        for(int i = 0; i < N; i++){
                data.value = i;
                push(&stack, data);
        }

        printf("\nCalling is_empty() function to check if the stack is empty.\n");
        if(is_empty(&stack) == STACK_IS_EMPTY){
                printf("Stack is empty.\n");
        } else {
                printf("Stack is not empty.\n");
        }
        
        printf("\nCalling get_stack_size() function.\n");
        printf("Stack contains %d elements.\n", get_stack_size(&stack));

        printf("\nCalling clear_stack() function\n");
        clear_stack(&stack);

        printf("\nCalling get_stack_size() function.\n");
        printf("Stack contains %d elements.\n", get_stack_size(&stack));

        printf("\nCalling is_empty() function to check if the stack is empty.\n");
        if(is_empty(&stack) == STACK_IS_EMPTY){
                printf("Stack is empty.\n");
        } else {
                printf("Stack is not empty.\n");
        }

        printf("\nCalling pop() function until the stack is empty.\n");
        while(is_empty(&stack) != STACK_IS_EMPTY){
                printf("%d\n", pop(&stack).value);
        }
}