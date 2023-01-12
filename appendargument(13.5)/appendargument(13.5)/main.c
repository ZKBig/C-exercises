//
//  main.c
//  appendargument(13.5)
//
//  Created by 王峥 on 2020/5/7.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE * source, FILE * dest);

int main(int argc, const char * argv[]) {
    FILE * fa, * fb;
    int files=0;
    int ch;
    if(argc<2)
    {
        printf("Usage: %s filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        if((fa=fopen(argv[0], "a+"))==NULL)
        {
            fprintf(stderr, "Can't open %s\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        if(setvbuf(fa, NULL, _IOFBF, BUFSIZE)!=0)
        {
            fputs("Can't creat output buffer.\n", stderr);
            exit(EXIT_FAILURE);
        }
        while(argv[0]!='\0' && argv[1]!='\0')
        {
            if(strcmp(argv[0], argv[1])==0)
                fputs("Can't append file to itself.\n", stderr);
            else if((fb=fopen(argv[1], "r"))==NULL)
                fprintf(stderr, "Can't open %s.\n", argv[1]);
            else
            {
                if(setvbuf(fb, NULL, _IOFBF, BUFSIZE)!=0)
                {
                    fputs("Can't creat input buffer.\n", stderr);
                    continue;
                }
                append(fa, fb);
                if(ferror(fa)!=0)
                {
                    fprintf(stderr, "Error in reading file %s.\n", argv[0]);
                    exit(EXIT_FAILURE);
                }
                if(ferror(fb)!=0)
                {
                    fprintf(stderr, "Error in reading file %s.\n", argv[1]);
                    exit(EXIT_FAILURE);
                }
                fclose(fa);
                files++;
                printf("File %s appended.\n", argv[1]);
                puts("Next file (empty line to quit):");
            }
        }
        printf("Done appending. %d files appended.\n", files);
        rewind(fa);
        printf("%s contents:\n", argv[0]);
        while((ch=getc(fa))!=EOF)
            putchar(ch);
        puts("Done displaying.");
        fclose(fa);
    }
    return 0;
}

void append(FILE * fa, FILE * fb)
{
    size_t bytes;
    static char temp[BUFSIZE];
    
    while((bytes=fread(temp, sizeof(char), BUFSIZE, fa))>0)
        fwrite(temp, sizeof(char), BUFSIZE, fb);
}

