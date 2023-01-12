//
//  main.c
//  binbit.c(15.3)
//
//  Created by 王峥 on 2020/4/26.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <limits.h> //提供CHAR_BIT定义
char * itobs(int, char *);
void show_bstr(const char *);
int main(int argc, const char * argv[]) {
    int number;
    char bin_str[CHAR_BIT * sizeof(int)+1];
    puts("Enter integers and see them in binary.");
    while(scanf("%d", &number)!=EOF){
        itobs(number, bin_str);
        printf("%d is ",number);
        show_bstr(bin_str);
        putchar('\n');
    }
    puts("BYE!\n");
    return 0;
}

char * itobs(int n, char * p){
    int i;
    const static int size=CHAR_BIT * sizeof(int);
    for(i=size-1; i>=0; i--, n>>=1)
        p[i]=(01 & n)+'0';
    p[size]='\0';
    return p;
}
/*4位一组显示二进制*/
void show_bstr(const char * str){
    int i=0;
    while(str[i])/*不是一个空字符*/
    {
        putchar(str[i]);
        if(++i % 4 ==0 && str[i])
            putchar(' ');
    }
}
