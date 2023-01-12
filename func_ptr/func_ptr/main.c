//
//  main.c
//  func_ptr
//
//  Created by 王峥 on 2020/5/9.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char * s_gets(char * st, int n);
char showmenu(void);
void eatline(void);
void show(void (*fp)(char *), char * str);
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *);

int main(int argc, const char * argv[]) {
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pfun)(char *);   //protorype a function pointer
    
    puts("Enter a string(empty line to stop):");
    while(s_gets(line, LEN)!=NULL && line[0]!='\0')
    {
        while((choice=showmenu())!='n')
        {
            switch(choice)
            {
                case 'u': pfun=ToUpper; break;
                case 'l': pfun=ToLower; break;
                case 't': pfun=Transpose; break;
                case 'o': pfun=Dummy; break;
            }
            strcpy(copy, line);
            show(pfun, copy);
        }
        puts("Enter a string(empty line to quit):");
    }
    puts("Bye.");
    
    return 0;
}

char showmenu(void)
{
    char ans;
    puts("Enter menu choice:");
    puts("u) uppercase              l) lowercase");
    puts("t) transposed case        o) original case");
    puts("n) next string");
    ans=getchar();
    ans=tolower(ans);
    eatline();
    while(strchr("ulton", ans)==NULL)
    {
        puts("Please enter a u, l, t, o, or n:");
        ans=tolower(getchar());
        eatline();
    }
    return ans;
}

void eatline(void)
{
    while(getchar()!='\n')
        continue;
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

void Transpose(char * str)
{
    while(* str)
    {
        if(islower(*str))
            *str=toupper(*str);
        else if(isupper(*str))
            *str=tolower(*str);
        str++;
    }
}

void Dummy(char * str){}

void show(void (*fp)(char *), char * str)
{
    (*fp)(str);
    puts(str);
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    
    ret_val=fgets(st, n, stdin);
    if(ret_val)
    {
        find=strchr(st, '\n');
        if(find)
            *find='\0';
        else
            eatline();
    }
    return ret_val;
}
