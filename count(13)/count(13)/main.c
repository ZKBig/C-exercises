//
//  main.c
//  count(13)
//
//  Created by 王峥 on 2020/5/7.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define NAME 20

int main(int argc, const char * argv[]) {
    int ch;
    FILE * fp;
    char st[NAME];
    unsigned long count=0;
    
    printf("Please enter the name of the file:\n");
    scanf("%40s", st);
    if((fp=fopen(st, "r"))==NULL)
    {
        printf("Can't open %s.\n", st);
        exit(EXIT_FAILURE);
    }
    else
    {
        while((ch=getc(fp))!=EOF)
        {
            putchar(ch);
            count++;
        }
    }
    fclose(fp);
    printf("File %s has %lu characters.\n", st, count);
    
    return 0;
}
