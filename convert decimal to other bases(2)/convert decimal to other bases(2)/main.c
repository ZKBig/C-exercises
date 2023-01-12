//
//  main.c
//  convert decimal to other bases(2)
//
//  Created by 王峥 on 2020/3/8.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int to_decimal(char array[], int n);
    char base[30];
    int n,NUM;
    printf("please enter the number whom you want to convert:\n");
    scanf("%s", base);
    printf("please enter the base of the entered number :\n");
    scanf("%d", &n);
    printf("The decimal number is:\n");
    NUM=to_decimal(base, n);
    printf("%d\n", NUM);
    putchar('\n');
    return 0;
}
int to_decimal(char array[], int n){
    char change(char m);
    int value,i,sum=0;
    unsigned long k=strlen(array);
    for(i=0;k>0;k--,i++){
        char m=change(array[i]);
        if(m>='0' && m<='9'){
            value=(m-'0')*pow(n,k-1);
            sum=sum+value;
        }else if(m>='A' && m<='F'){
            value=(m-'A'+10)*pow(n,k-1);
            sum=sum+value;
        }
    }
    return sum;
}
char change(char m){
    if(m>='a' && m<='f'){m=m-32;}
    return m;
}
