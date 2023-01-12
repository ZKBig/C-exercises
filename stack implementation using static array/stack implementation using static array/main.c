//
//  main.c
//  stack implementation using static array
//
//  Created by 王峥 on 2020/3/12.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5
void push(int);
int pop(void);
int isFull(void);
int isEmpty(void);
void peek(void);
void traverse(void);
int stack[CAPACITY], top=-1;
int main() {
    int ch, item;
    while(1){
        putchar('\n');
        printf("1, Push\n");
        printf("2, Pop\n");
        printf("3, Peek\n");
        printf("4, Traverse\n");
        printf("5, Quit\n");
        printf("Please enter your choice:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:     printf("Enter the element:\n");
                        scanf("%d", &item);
                        push(item);
                        break;
            case 2:     item=pop();
                        if(item==0){
                            printf("The stack is underflow.");
                        }else{
                            printf("%d", item);
                        }
                        break;
            case 3:     peek();
                        break;
            case 4:     traverse();
                        break;
            case 5:     exit(0);
            default:    printf("invalid input.\n");
        }
    }
    return 0;
}

void push(int ele){
    if(isFull()){printf("The stack is overflow.\n ");}
    else{
        top++;
        stack[top]=ele;
        printf("%d is input", ele);
    }}

int isFull(){
    if(top==CAPACITY-1){return 1;}
    else{return 0;}
}

int pop(){
    if(isEmpty()){return 0;}
    else{return stack[top--];}
}

int isEmpty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}

void peek(){
    if(isEmpty()){
        printf("The stack is uderflow.\n");
    }else{
        printf("%d is peek number.\n", stack[top]);
    }
}

void traverse(){
    if(isEmpty()){
        printf("The stack is underflow.\n");
    }else{
        int i;
        printf("stack elements are:\n");
        for(i=0;i<=top;i++){
            printf("%d", stack[i]);
        }
    }
}
