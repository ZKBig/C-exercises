//
//  main.c
//  seekstring(13.11)
//
//  Created by 王峥 on 2020/5/8.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 255

int main(int argc, const char * argv[]) {
    FILE * fp;
    char line[LEN];
    
    if(argc!=3)
    {
        fprintf(stderr, "Usage: %s filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp=fopen(argv[2], "r"))==NULL)
    {
        fprintf(stderr, "Can't open the file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while(fgets(line, LEN, fp)!=NULL && line[0]!='\0')
    {
        if(strstr(line, argv[1]))
            fputs(line, stdout);
    }
    if(ferror(fp)!=0)
    {
        fprintf(stderr, "Can't close the file.\n");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
