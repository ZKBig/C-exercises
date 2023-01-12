//
//  main.c
//  compare the value of three numbers
//
//  Created by 王峥 on 2020/2/27.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>

int main() {
    void exchange(int *p1, int *p2, int *p3);
    int a, b, c, *p1_pointer, *p2_pointer, *p3_pointer;
    printf("please enter three numbers:\n");
    scanf("%d%d%d", &a, &b, &c);
    p1_pointer=&a;
    p2_pointer=&b;
    p3_pointer=&c;
    exchange(p1_pointer,p2_pointer,p3_pointer);
    printf("The order is: %d, %d, %d",a, b, c);
    return 0;
}
void exchange(int *p1, int *p2, int *p3){
    void swap(int *x, int *y);
    if(*p1<*p2)swap(p1, p2);
    if(*p1<*p3)swap(p1, p3);
    if(*p2<*p3)swap(p2, p3);
}
void swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
