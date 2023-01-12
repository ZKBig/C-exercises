//
//  main.c
//  converse binary to octal
//
//  Created by 王峥 on 2020/3/8.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int main() {
    int binarytooctal(int number);
    int n,octal;
    printf("please enter the binary number:\n");
    scanf("%d", &n);
    printf("octal equivalent:\n");
    octal=binarytooctal(n);
    printf("%d", octal);
    putchar('\n');
    return 0;
}
int binarytooctal(int number){
    int binarytodecimal(int number);
    int r, value;
    int octal=0,i=1;
    while(number!=0){
        r=number%1000;
        value=binarytodecimal(r);
        octal=octal+value*i;
        i=i*10;
        number=number/1000;
    }
    return octal;
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
