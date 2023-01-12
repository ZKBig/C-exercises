//
//  main.c
//  convert a number based 10 to other bases(1)
//
//  Created by 王峥 on 2020/3/8.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main() {
    void decimaltoothers(unsigned long n, int m);
    int m;
    unsigned long number;
    printf("please enter the intager number:\n");
    scanf("%lu", &number);
    printf("please enter the base you want to convert:\n");
    scanf("%d", &m);
    decimaltoothers(number, m);
    putchar('\n');
    return 0;
}
void decimaltoothers(unsigned long n, int m){
    void strrev(char array[]);
    char number[20];
    int r,i=0;
    while(n!=0){
        r=n%m;
        if(r>9){
            number[i]=r+55;
        }else{
            number[i]=r+48;
        }
        n=n/m;
        i++;}
    number[i]='\0';
    strrev(number);
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
