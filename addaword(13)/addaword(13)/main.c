//
//  main.c
//  addaword(13)
//
//  Created by 王峥 on 2020/5/5.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(int argc, const char * argv[]) {
    FILE * fp;
    char words[MAX];
    
    if((fp=("wordy", "a+"))==NULL)
    {
        fprintf(stderr, "Can't open \"wordy\"file.\n");
        exit(EXIT_FAILURE);
    }
    
    puts("Enter words to add to the file; press enter key at the beginning of a line to terminate.");
    while((fscanf(stdin, "%40s", words)==1) && (words[0]!='\0'))
        fprintf(fp, "%s\n", words);
    
    puts("file contents:");
    rewind(fp);
    while(fscanf(fp,"%s", words)==1)
        puts(words);
    puts("Done.");
    if(fclose(fp)!=0)
        fprintf(stderr, "Error closing file.\n");
    
    return 0;
}
