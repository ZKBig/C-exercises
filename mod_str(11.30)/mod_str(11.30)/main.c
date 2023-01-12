//
//  main.c
//  mod_str(11.30)
//
//  Created by 王峥 on 2020/5/1.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81
void ToUpper(char * str);
void ToLower(char * str);
int Count(const char * str);

int main(int argc, const char * argv[]) {
    char * find;
    char line[LIMIT];
    
    puts("Please enter a line");
    fgets(line, LIMIT, stdin);
    find=strchr(line, '\n');
    if(find)
        * find='\0';
    while(getchar()!='\n')
        continue;
    ToUpper(line);
    puts(line);
    ToLower(line);
    puts(line);
    printf("That line has %d punctuation character.\n", Count(line));
        
    return 0;
}

void ToUpper(char * str)
{
    while(* str)
    {
        *str=toupper(*str);
        str++;
    }
}

void ToLower(char * str)
{
    while(* str)
    {
        *str=tolower(*str);
        str++;
    }
}

int Count(const char * str)
{
    int ch=0;
    while(* str)
    {
        if(ispunct(* str))
            ch++;
        
        str++;
    }
    return ch;
}
