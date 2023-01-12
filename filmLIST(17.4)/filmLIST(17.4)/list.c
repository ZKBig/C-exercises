//
//  list.c
//  filmLIST(17.4)
//
//  Created by 王峥 on 2020/5/11.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node * pnode);

void InitializeList(List * plist)
{
    *plist=NULL;
}

bool ListIsEmpty(const List * plist)
{
    if(*plist==NULL)
        return true;
    else
        return false;
}

bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;
    
    pt=(Node *)malloc(sizeof(Node));
    if(pt==NULL)
        full=true;
    else
        full=false;
    free(pt);
    return full;
}

unsigned int ListItemCount(const List * plist)
{
    Node * pnode=*plist;
    unsigned int count=0;
    
    while(pnode!=NULL)
    {
        count++;
        pnode=pnode->next;
    }
    return count;
}

bool AddItemE(Item item, List * plist)
{
    Node * pnew;
    Node * scan=*plist;
    
    pnew=(Node *)malloc(sizeof(Node));
    if(pnew==NULL)
        return false;
    CopyToNode(item, pnew);
    pnew->next=NULL;
    if(scan==NULL)
        *plist=pnew;
    else
    {
        while(scan->next!=NULL)
            scan=scan->next;
        scan->next=pnew;
    }
    return true;
}

bool AddItemB(Item item, List * plist)
{
    Node * pnew;
    Node *scan=*plist;
    
    pnew=(Node *)malloc(sizeof(Node));
    if(pnew==NULL)
        return false;
    CopyToNode(item, pnew);
    pnew->next=NULL;
    if(scan==NULL)
        *plist=pnew;
    else
    {
        pnew->next=scan;
        *plist=pnew;
    }
    return true;
}

bool AddItemM(Item item, List * plist, int n)
{
    Node * pnew;
    Node * scan=*plist;
    
    if(n>ListItemCount(plist))
    {
        printf("The linked list has %d nodes.",
               ListItemCount(plist));
        return false;
    }
    pnew=(Node *)malloc(sizeof(Node));
    if(pnew==NULL)
        return false;
    CopyToNode(item, pnew);
    pnew->next=NULL;
    if(scan==NULL)
        *plist=pnew;
    else
    {
        for(int i=1; i<n; i++)
            scan=scan->next;
        pnew->next=scan->next;
        scan->next=pnew;
    }
    return true;
}

bool DeleteItem(List * plist, int n)
{
    Node *scan=*plist;
    
    if(n>ListItemCount(plist))
    {
        printf("The linked list has %d nodes.",
               ListItemCount(plist));
        return false;
    }
    if(n==1)
    {
        *plist=scan->next;
        scan->next=NULL;
        free(scan);
    }
    else
    {
        for(int i=1; i<n-1; i++)
            scan=scan->next;
        scan->next=scan->next->next;
        scan->next->next=NULL;
        free(scan->next);
    }
    return true;
}

Node * InvertList(List plist)
{
    Node * p;
    
    if(plist==NULL || plist->next==NULL)
        return plist;
    p=InvertList(plist->next);
    plist->next->next=plist;
    plist->next=NULL;
    return p;
}

void Traverse(const List * plist, void (*pfun)(Item item))
{
    Node * pnode=*plist;
    
    while(pnode!=NULL)
    {
        (*pfun)(pnode->item);
        pnode=pnode->next;
    }
}

void EmptyTheList(List * plist)
{
    Node * psave;
    
    while(*plist!=NULL)
    {
        psave=(*plist)->next;
        free(*plist);
        *plist=psave;
    }
}

static void CopyToNode(Item item, Node * pnode)
{
    pnode->item=item;
}
