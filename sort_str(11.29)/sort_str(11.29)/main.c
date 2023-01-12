//
//  main.c
//  sort_str(11.29)
//
//  Created by 王峥 on 2020/5/1.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define SIZE 30
#define LIM 20
#define HALT " "

void stsrt(char * string [], int num );
char * s_gets(char * st, int n);

int main(int argc, const char * argv[]) {
    char input[LIM][SIZE];
    char * ptstr[LIM];
    int ct=0;
    int k;
    
    printf("Input up to %d lines, and I will sort them.\n", LIM);
    printf("To stop, press the Enter key at a line's start.\n");
    while(ct<LIM && s_gets(input[ct], SIZE)!=NULL && input[ct][0]!='\0')
    {
        ptstr[ct]=input[ct];
        ct++;
    }
    stsrt(ptstr, ct);
    puts("\nHere's the sorted list:\n");
    for(k=0; k<ct ;k++)
        puts(ptstr[k]);

    return 0;
}

void stsrt(char * string[], int num)
{
    char * temp;
    int top, seek;
    
    for(top=0; top<num-1; top++)
    {
        for(seek=top+1; seek<num; seek++)
        {
            if(strcmp(string[top],string[seek])>0)
            {
                temp=string[top];
                string[top]=string[seek];
                string[seek]=temp;
            }
        }
    }
}
char * s_gets( char * st, int n)
{
    char * find;
    char * ret_val;
    
    ret_val=fgets(st, n, stdin);
    if(ret_val)
    {
        find=strchr(st, '\n');
        if(find)
            *find='\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return ret_val;
}

