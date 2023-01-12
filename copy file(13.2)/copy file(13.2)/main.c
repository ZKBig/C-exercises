//
//  main.c
//  copy file(13.2)
//
//  Created by 王峥 on 2020/5/7.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int ch;
    FILE * fa, * fb;
    
    if(argc<3)
    {
        printf("Usage: %s filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fa=fopen(argv[1], "rb"))==NULL)
    {
        printf("Can't open %s.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fb=fopen(argv[2], "wb"))==NULL)
    {
        printf("Can't open %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fa))!=EOF)
        putc(ch, fb);
    fclose(fa);
    fclose(fb);
    return 0;
}
