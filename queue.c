/*
 * Task3, queue.c
 * Purpose: The implementation of the queue library functions.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 23/08/2021
 */

#include <stdlib.h>
#include "queue.h"

/*
 * The function adds new item (an instance of the DATA sctructure) to the end (tail) of the queue.
 * 
 * @param queue is the pointer to the pointer to the queue 
 * @param data is an instance of DATA structure (i.e. item) to add to the queue
 * @return TRUE if new item was added to the queue successfully, otherwise FALSE 
 */
int enqueue(struct QUEUE **queue, struct DATA data)
{
        int status = FALSE;
        if((queue != NULL) && ((*queue) != NULL)) {
                if((*queue)->item_count < ((*queue)->length - 1)) {
                        (*queue)->data[(*queue)->end--] = data;
                        if((*queue)->end < 1) {
                                (*queue)->end = (*queue)->length - 1;
                        }
                        (*queue)->item_count++;
                        status = TRUE;
                }
        }

        return status;
}

/*
 * The function removes an item (an instance of the DATA sctructure) from 
 * the beginning (head) of the queue and returns it.
 * 
 * @param queue is the pointer to the pointer to the queue 
 * @param data is a pointer to an instance of DATA structure (i.e. item) that is used
 * to return an item removed from the queue
 * @return TRUE if an item was removed from the queue successfully, otherwise FALSE 
 */
int dequeue(struct QUEUE **queue, struct DATA *data)
{
        int status = FALSE;
        if((queue != NULL) && ((*queue) != NULL)) {
                if((*queue)->item_count > 0) {
                        (*data) = (*queue)->data[(*queue)->start--];
                        if((*queue)->start < 1) {
                                (*queue)->start = (*queue)->length - 1;
                        }
                        (*queue)->item_count--;
                        status = TRUE;
                }
         }
         return status;
}

/*
 * The function creates a queue dynamically and returns the pointer to the queue.
 * The number of items that can be stored in the queue is (length - 1). Dynamically
 * allocated memory for the queue must be freed after the queue is not need any more.
 * 
 * @param length is the size (in storage units) of an array that is used in the queue;
 * the maximum number of item that can be stored in the queue is (length - 1)
 * @return the pointer to an instance of the QUEUE data structure that represents queue
 * based on an array, or NULL if an error occured
 */
struct QUEUE *create_queue(const size_t length)
{
        struct QUEUE *queue;
        if(length > 0) {
                // Explicit type conversion is used here to improve the readability of the code
                queue = (struct QUEUE *)malloc(sizeof(struct QUEUE));
                queue->data = (struct DATA *)malloc(length * sizeof(struct DATA));
                queue->start = length - 1;
                queue->end = queue->start;
                queue->length = length;
                queue->item_count = 0;
        }
        return queue;
}

/*
 * The function frees dynamically allocated memory that was used by queue.
 * After execution of this function the queue will not exist and is not accessible any more.
 * 
 * @param queue is the pointer to the queue
 */
void delete_queue(struct QUEUE *queue)
{
        if(queue != NULL) {
                if(queue->data != NULL) {
                        free(queue->data);
                }
                free(queue);
        }
}

/*
 * The function checks if there are items in the queue.
 * 
 * @param queue is the pointer to the queue
 * @retrun TRUE if the queue is not empty, otherwise FALSE
 */
int queue_is_empty(struct QUEUE *queue)
{
        if(queue->item_count == 0) {
                return TRUE;
        }
        return FALSE;
}

/*
 * The function returns the number of items in the queue.
 * 
 * @param queue is the pointer to the queue
 * @return the number of items that are in the queue
 */
uint32_t get_item_count(struct QUEUE *queue)
{
        return queue->item_count;
}