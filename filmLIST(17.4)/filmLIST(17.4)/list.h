//
//  list.h
//  filmLIST(17.4)
//
//  Created by 王峥 on 2020/5/11.
//  Copyright © 2020 王峥. All rights reserved.
//

#ifndef list_h
#define list_h
#include <stdbool.h>
#include <stdio.h>

#define TSIZE 45
struct film{
    char title[TSIZE];
    int rating;
};

typedef struct film Item;

typedef struct node{
    Item item;
    struct node * next;
}Node;

typedef Node * List;

/*operation:        initialize a linked list*/
/*precondition:     plist points to a linked list*/
/*post-condition:   the linked list is initialized to empty*/
void InitializeList(List * plist);

/*operation:        check whether the linked list is empty*/
/*precondition:     plist pontis to the linked list which has already been initialized to empty*/
/*post-condition:   if the linked list is empty, return true, otherwise, return false*/
bool ListIsEmpty(const List * plist);

/*operation:        check whether the linked list is full*/
/*precondition:     plist pontis to the linked list which has already been initialized*/
/*post-condition:   if the linked list is full, return true, otherwise, return false*/
bool ListIsFull(const List * plist);

/*operation:        count the number of the items*/
/*precondition:     plist pontis to the linked list which has already been initialized*/
/*post-condition:   return the number of items in the linked lists*/
unsigned int ListItemCount(const List * plist);

/*operation:        add item in the end of the linked list*/
/*precondition:     item is to be added, and plist pontis to the linked list which has already
                    been initialized*/
/*post-condition:   if it can add an item in the end of the linked list, return true, otherwise,
                    return false*/
bool AddItemE(Item item, List * plist);

/*operation:        add item at the beginning of the linked list*/
/*precondition:     item is to be added, and plist pontis to the linked list which has already
                    been initialized*/
/*post-condition:   if it can add an item at the beginning of the linked list, return true, otherwise,
                    return false*/
bool AddItemB(Item item, List * plist);

/*operation:        add item in the middle of the linked list*/
/*precondition:     item is to be added and n is the location, and plist pontis to the linked list
                    which has already been initialized*/
/*post-condition:   if it can add an item in the middle of the linked list, return true, otherwise,
                    return false*/
bool AddItemM(Item item, List * plist, int n);

/*operation:        delete an item in the linked list*/
/*precondition:     n is the location, and plist pontis to the linked list which has already been
                    initialized*/
/*post-condition:   if it can delete an item in the linked list, return true, otherwise,return false*/
bool DeleteItem(List * plist, int n);

/*operation:        put the function acted on the every item in the linked list*/
/*precondition:     plist pontis to the linked list which has already been initialized,and pfun points to
                    a function, which receives an Item and no return value*/
/*post-condition:   the function pointed by pfun function every item in the linked list once only*/
void Traverse(const List * plist, void (*pfun)(Item item));

/*operation:        release the linked list*/
/*precondition:     plist pontis to the linked list which has already been initialized*/
/*post-condition:   release all the memory, and the list is set to empty*/
void EmptyTheList(List * plist);

/*operation:        inverse all items in a linked list*/
/*precondition:     plist pontis to the linked list which has already been initialized to empty*/
/*post-condition:   if it inverse successfully, then return p*/
Node * InvertList(List plist);

#endif /* list_h */
