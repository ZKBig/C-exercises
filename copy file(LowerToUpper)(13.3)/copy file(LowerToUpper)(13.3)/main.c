//
//  main.c
//  copy file(LowerToUpper)(13.3)
//
//  Created by 王峥 on 2020/5/7.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NAME 20

int main(int argc, const char * argv[]) {
    FILE * fp;
    int ch;
    char file[NAME];
    
    puts("PLease enter the name of the file to invert:");
    scanf("%40s", file);
    if((fp=fopen(file, "r"))==NULL)
    {
        printf("Can't open %s.\n",file);
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp))!=EOF)
    {
        if(islower(ch))
        {
            ch=toupper(ch);
        }
    }
    fclose(fp);
    return 0;
}
