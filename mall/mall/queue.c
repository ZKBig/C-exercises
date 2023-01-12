//
//  queue.c
//  mall
//
//  Created by 王峥 on 2020/4/29.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);

void InitializeQueue(queue * pq)
{
    pq->front=pq->rear=NULL;
}

bool QueueIsFull(const queue * pq)
{
    return pq->items==MAXQUEUE;
}

bool QueueIsEmpty(const queue * pq)
{
    return pq->items==0;
}

int QueueItemCount(const queue * pq)
{
    return pq->items;
}

bool AddQueue(Item item, queue * pq)
{
    Node * pnew;
    
    if(QueueIsFull(pq))
        return false;
    pnew=(Node *)malloc(sizeof(Node));
    if(pnew==NULL)
    {
        fprintf(stderr, "unable to allocate memory!\n");
        exit(1);
    }
    CopyToNode(item, pnew);
    pnew->next=NULL;
    if(QueueIsEmpty(pq))
    {
        pq->front=pnew;
    }
    else
    {
        pq->rear->next=pnew;
    }
    pq->rear=pnew;
    pq->items++;
    
    return true;
}

bool DeQueue(Item * pitem, queue * pq)
{
    Node * pt;
    
    if(QueueIsEmpty(pq))
    {
        return false;
    }
    CopyToItem(pq->front, pitem);
    pt=pq->front;
    pq->front=pq->front->next;
    free(pt);
    pq->items--;
    if(pq->items==0)
        pq->rear=NULL;
    return true;
}

void EmptyTheQueue(queue * pq)
{
    Item dummy;
    while(!QueueIsEmpty(pq))
        DeQueue(&dummy, pq);
}

static void CopyToNode(Item item, Node * pn)
{
    pn->item=item;
}

static void CopyToItem(Node * pn, Item * pi)
{
    *pi=pn->item;
}
