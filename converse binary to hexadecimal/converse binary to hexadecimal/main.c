//
//  main.c
//  converse binary to hexadecimal
//
//  Created by 王峥 on 2020/3/8.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main(void) {
    void hexadecimal(unsigned long n);
    unsigned long number;
    printf("Enter an intager number(q to auit);\n");
    while(scanf("%lu", &number)==1){
        printf("hexadecimal equivalent:\n");
        hexadecimal(number);
        putchar('\n');
        printf("Enter an intager number(q to auit);\n");
        }
    printf("done.\n");
    
    return 0;
}
void hexadecimal(unsigned long n){
    void strrev(char array[]);
    char hexa[15];
    int r,i=0;
    while(n!=0){
        r=n%16;
        if(r>9){
            hexa[i]=r+55;
        }else{
            hexa[i]=r+48;
        }
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

