//
//  main.c
//  reducto(interaction)(13.6)
//
//  Created by 王峥 on 2020/5/7.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main(int argc, const char * argv[]) {
    FILE * in, * out;
    int ch;
    char infile[LEN];
    char outfile[LEN];
    int count=0;
    
    printf("Please enter the name of the file to be reduces:\n");
    scanf("%s", infile);
    if((in=fopen(infile, "r"))==NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\".\n ", infile);
        exit(EXIT_FAILURE);
    }
    strncpy(outfile, infile, LEN-5);
    outfile[LEN-5]='\0';
    strcat(outfile, ".red");
    if((out=fopen(outfile, "w"))==NULL)
    {
        fprintf(stderr, "Can't creat output file.\n");
        exit(EXIT_FAILURE);
    }
    while((ch=getc(in))!=EOF)
    {
        if(count++ %3==0)
            putc(ch, out);
    }
    if(fclose(in)!=0 || fclose(out)!=0)
        fprintf(stderr, "Error in closing files.\n");
    
    return 0;
}
