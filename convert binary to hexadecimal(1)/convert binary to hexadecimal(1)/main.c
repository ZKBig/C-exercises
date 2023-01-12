//
//  main.c
//  convert binary to hexadecimal(1)
//
//  Created by 王峥 on 2020/3/8.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
int main() {
    void binarytohexadecimal(int number);
    int n;
    printf("please enter the binary number:\n");
    scanf("%d", &n);
    printf("hexadecimal equivalent:\n");
    binarytohexadecimal(n);
    putchar('\n');
    return 0;
}
void binarytohexadecimal(int number){
    int binarytodecimal(int number);
    int n;
    n=binarytodecimal(number);
    void strrev(char array[]);
    char hexa[15];
    int r,i=0;
    while(n!=0){
        r=n%16;
        if(r>9)hexa[i]=r+55;
        else hexa[i]=r+48;
        n=n/16;
        i++;}
    hexa[i]='\0';
    strrev(hexa);
    return;
}
void strrev(char array[]){
    unsigned long k,i;
    char temp;
    k=strlen(array);
    for(i=0;i<k;i++,k--){
        temp=array[k-1];
        array[k-1]=array[i];
        array[i]=temp;
    }
    printf("%s", array);
    return ;
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








