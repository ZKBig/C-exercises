//
//  queue.h
//  mall
//
//  Created by 王峥 on 2020/4/29.
//  Copyright © 2020 王峥. All rights reserved.
//

#ifndef queue_h
#define queue_h
#include <stdbool.h>

typedef struct item
{
    long arrive;
    int processtime;
}Item;

#define MAXQUEUE 10

typedef struct node
{
    Item item;
    struct node * next;
}Node;

typedef struct queue
{
    Node * front;
    Node * rear;
    int items;
}queue;

/*operation:         initialize queue                       */
/*precondition:      pq points to a queue                   */
/*post-condition:    The queue is initially empty           */
void InitializeQueue(queue * pq);

/*operation:         check whether the queue is full                                 */
/*preconditon:       pq points to the initialized queue                              */
/*post-condition:    return true if the queue is full, otherwise, return false       */
bool QueueIsFull(const queue * pq);

/*operation:         check whether the queue is empty                                */
/*preconditon:       pq points to the initialized queue                              */
/*post-condition:    return true if the queue is empty, otherwise, return false      */
bool QueueIsEmpty(const queue * pq);

/*operaiton:         confirm the number of items in the queue                        */
/*proconditon:       pq pointe to the initialized queue                              */
/*post-condition:    return the number of items                                      */
int QueueItemCount(const queue * pq);

/*operaiton:         add item at the end of the queue                                     */
/*precondition:      pq points to the initialized queue                                   */
/*post-condition:    return true if the queue is not empty and the item will be added     */
/*                   at the end, otherwise, return false and the queue will not change    */
bool AddQueue(Item item, queue *pq);

/*operation:         delete the item in the beginning of the queue                                */
/*precondition:      pq points to the initialized queue                                           */
/*post-condition:    If the queue is not empty, the fist item will be copied to the *pitem        */
/*                   and will be delted, then return true.                                        */
/*                   If the queue become empty after this operation, then reset the queue empty   */
/*                   If the queue is empty before operaiton, then return false                    */
bool DeQueue(Item * pitem, queue * pq);

/*operation:         empty the queue                       */
/*peocondition:      pq points to the initialized queue    */
/*post-condition:    the queue is empty                    */
void EmptyTheQueue(queue * pq);
 
#endif /* queue_h */
