//
//  BTS.h
//  petclub(BST)
//
//  Created by 王峥 on 2020/5/12.
//  Copyright © 2020 王峥. All rights reserved.
//

#ifndef BTS_h
#define BTS_h

#include <stdio.h>
#include <stdbool.h>

#define SLEN 20
#define MAXITEMS 10
typedef struct item{
    char petname[SLEN];
    char petkind[SLEN];
}Item;

typedef struct trnode{
    Item item;
    struct trnode * left;
    struct trnode * right;
}Trnode;

typedef struct tree{
    Trnode * root;
    int size;
}Tree;

/*operation:         initialize tree to empty          */
/*precondition:      ptree pints to a tree             */
/*post-condition:    tree is initialized to empty      */
void InitializeTree(Tree * ptree);

/*operation:         check weather the tree is empty                          */
/*precondition:      ptree pontis to a tree                                   */
/*post-condition:    if tree is empty, return true, otherwise, return false   */
bool TreeIsEmpty(const Tree * ptree);

/*operation:         check weather the tree is full                           */
/*precondition:      ptree pontis to a tree                                   */
/*post-condition:    if tree is full, return true, otherwise, return false    */
bool TreeIsFull(const Tree * ptree);

/*operation:         count the number of items         */
/*precondition:      ptree points to a tree            */
/*post-condition:    return the number of items        */
unsigned int TreeItemCount(const Tree * ptree);

/*operation:         add an item in the tree                                  */
/*precondition:      pi is the address of the item to be added,               */
/*                   ptree points to an initialized tree                      */
/*post-condition:    if add the item successfully, then return true,          */
/*                   otherwise, return false                                  */
bool AddItem(const Item * pi, Tree * ptree);

/*operation:         look for an item in the tree                             */
/*precondition:      pi points to the item to be found,                       */
/*                   ptree points to an initialized tree                      */
/*post-condition:    if find the item successfullt, then return ture,         */
/*                   otherwise, return false                                  */
bool InTree(const Item * pi, const Tree * ptree);

/*operation:         delete an item in the tree                               */
/*precondition:      pi is the address of the item to be deleted,             */
/*                   ptree points to an initialized tree                      */
/*post-cpndition:    if the item is deleted successfully, then return true,   */
/*                   otherwise, return false                                  */
bool DeleteItem(const Item * pi, Tree * ptree);

/*operation:         put the function acted on every item                     */
/*precondition:      ptree pontis to a tree, pfun points to a function        */
/*post-condition:    the function pointed by pfun acts on every item once     */
void Traverse(const Tree * ptree, void (*pfun)(Item item));

/*operation:         delete all the items in the tree                         */
/*precondition:      ptree points to an initialized tree                      */
/*post-condition:    the tree is empty                                        */
void DeleteAll(Tree * ptree);

#endif /* BTS_h */
