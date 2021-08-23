/*
 * Task3, task3.c
 * Purpose: write a queue library based on an array. 
 * Minimum set of operations: enqueue(), dequeue().
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 23/08/2021
 */

#include <stdio.h>
#include "queue.h"

/*
 * Function prototype.
 */
void run_demo(void);

/*
 * The main function of the program (entry point).
 * Demonstration of using the queue library functions.
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
 * This function demonstrates the usage of the queue library functions and prints
 * the results of their callings and some additional information in the console window. 
 */
void run_demo(void)
{
        const size_t QUEUE_LENGTH = 10;
        struct QUEUE * queue = NULL;

        // Create queue
        queue = create_queue(QUEUE_LENGTH);
        if(queue == NULL){
                printf("Error creating queue!\n");
                return;
        }


        // Get the number of items in the queue (should be 5) 
        printf("Number of items in the queue: %d\n", get_item_count(queue));
        
        // Insert 5 items into the queue 
        struct DATA data;
        for(int i = 0; i < 5; i++){
                data.value = i;
                if(enqueue(&queue, data)){
                        printf("Value %d inserted into the queue.\n", data.value);
                }
        }

        // Get the number of items in the queue (should be 5) 
        printf("Number of items in the queue: %d\n", get_item_count(queue));
        
        // Extract 2 items from the queue
        for(int i = 0; i < 2; i++){
                if(dequeue(&queue, &data)){
                        printf("Value %d extracted from the queue.\n", data.value);
                }
        }

        // Get the number of items in the queue (should be 5) 
        printf("Number of items in the queue: %d\n", get_item_count(queue));

        // Insert elements until queue is not full
        data.value = 11;
        while(enqueue(&queue, data) == TRUE){
                printf("Value %d inserted into the queue.\n", data.value);
                data.value++;
        }

        // Get the number of items in the queue (should be 5) 
        printf("Number of items in the queue: %d\n", get_item_count(queue));

        // Dequeue elements untis queue is not empty
        while(dequeue(&queue, &data) == TRUE){
                printf("Value %d extracted from the queue.\n", data.value);
        }

        // Get the number of items in the queue (should be 5) 
        printf("Number of items in the queue: %d\n", get_item_count(queue));

        delete_queue(queue);
}
