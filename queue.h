/*
 * Task3, queue.h
 * Purpose: The header file of the queue library.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 23/08/2021
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdint.h>

#define TRUE 1
#define FALSE 0

/*
 * This data structure is used as a wrapper around the useful data (in this case the values of int data type)
 * and it allows to make queue independent from the data type of the values that are in the queue.
 */
struct DATA
{
        int value;
};

struct QUEUE
{
        struct DATA *data;
        uint32_t start;
        uint32_t end;
        uint32_t item_count;
        size_t length;
};

// The prototypes of base functions to work with a stack.
int enqueue(struct QUEUE **queue,  struct DATA data);
int dequeue(struct QUEUE **queue, struct DATA *data);

// The prototypes of additional functions to work with a stack.
struct QUEUE *create_queue(const size_t length);
void delete_queue(struct QUEUE *queue);
int queue_is_empty(struct QUEUE *queue);
uint32_t get_item_count(struct QUEUE *queue);

#endif
