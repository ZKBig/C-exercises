//
//  main.c
//  convert binary to quaternary
//
//  Created by 王峥 on 2020/3/8.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int main() {
    int binarytoquaternary(int number);
    int n,octal;
    printf("please enter the binary number:\n");
    scanf("%d", &n);
    printf("quaternary equivalent:\n");
    octal=binarytoquaternary(n);
    printf("%d", octal);
    putchar('\n');
    return 0;
}
int binarytoquaternary(int number){
    int binarytodecimal(int number);
    int r, value;
    int quater=0,i=1;
    while(number!=0){
        r=number%100;
        value=binarytodecimal(r);
        quater=quater+value*i;
        i=i*10;
        number=number/100;
    }
    return quater;
}
int binarytodecimal(int number){
    int r,value=0,i=0;
    while(number!=0){
        r=number%10;
        value=value+r*pow(2,i);
        i++;
        number=number/10;
    }
    return value;
}
