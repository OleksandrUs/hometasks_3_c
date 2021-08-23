/*
 * Task3, queue.c
 * Purpose: The implementation of the queue library functions.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 23/08/2021
 */

#include <stdlib.h>
#include "queue.h"

int enqueue(struct QUEUE **queue,  struct DATA data)
{
        int status = FALSE;
        if((queue != NULL) && ((*queue) != NULL)) {
                if((*queue)->item_count < ((*queue)->length - 1))
                {
                        (*queue)->data[(*queue)->end--] = data;
                        if((*queue)->end < 1){
                                (*queue)->end = (*queue)->length - 1;
                        }
                        (*queue)->item_count++;
                        status = TRUE;
                }
        }

        return status;
}

int dequeue(struct QUEUE **queue, struct DATA *data)
{
        int status = FALSE;
        if((queue != NULL) && ((*queue) != NULL)){
                if((*queue)->item_count > 0){
                        (*data) = (*queue)->data[(*queue)->start--];
                        if((*queue)->start < 1){
                                (*queue)->start = (*queue)->length - 1;
                        }
                        (*queue)->item_count--;
                        status = TRUE;
                }
         }
         return status;
}

struct QUEUE * create_queue(const int length)
{
        struct QUEUE *queue = NULL;
        if(length > 0)
        {
                queue = malloc(length * sizeof(struct DATA));
                queue->start = length - 1;
                queue->end = queue->start;
                queue->length = length;
                queue->item_count = 0;
        }
        return queue;
}

void delete_queue(struct QUEUE *queue)
{
        if(queue != NULL) {
                free(queue);
        }
}

int queue_is_empty(struct QUEUE *queue)
{
        if(queue->item_count == 0){
                return TRUE;
        }
        return FALSE;
}

uint32_t get_item_count(struct QUEUE *queue)
{
        return queue->item_count;
}