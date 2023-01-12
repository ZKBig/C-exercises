//
//  main.c
//  invert4.c(15)
//
//  Created by 王峥 on 2020/4/26.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#define N 4
char * itobs(int, char *);
void show_bstr(const char *);
int invert_end(int num, int bits);

int main(int argc, const char * argv[]) {
    char bin_str[CHAR_BIT * sizeof(int)+1];
    int number;
    puts("Enter integers and see them in binary: \n");
    while(scanf("%d", &number)!=EOF)
    {
        itobs(number, bin_str);
        printf(" %d is\n", number);
        show_bstr(bin_str);
        putchar('\n');
        number=invert_end(number,N);
        printf("Inverting the last %d bits gives\n", N);
        show_bstr(itobs(number, bin_str));
        putchar('\n');
    }
    puts("BYE!\n");
    return 0;
}

char * itobs(int n, char * p){
    int i;
    const static int size=CHAR_BIT * sizeof(int);
    for(i=size-1; i>=0; n>>=1, i--)
        p[i]=(01 & n)+'0';
    p[size]='\0';
    return p;
}

int invert_end(int num, int bits){
    int mask=0;
    int bitval=1;
/*create mask code*/
    while (bits-->0)
    {
        mask |=bitval;
        bitval <<=1;
    }
    return num ^ mask;
}

void show_bstr(const char * str){
    int i=0;
    while(str[i])
    {
        putchar(str[i]);
        if(++i % 4==0 && str[i])
            putchar(' ');
    }
}
