//
//  main.c
//  addaword(13.9)
//
//  Created by 王峥 on 2020/5/7.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(int argc, const char * argv[]) {
    FILE * fp;
    char words[MAX];
    long count=1;
    
    if((fp=fopen("wordy", "a+"))==NULL)
    {
        fprintf(stderr, "Can't open \" wordy \"file.\n");
        exit(EXIT_FAILURE);
    }
    //read the original data
    while(fscanf(fp, "%ld %s", &count, words)>0);
    
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of the line to stop.");
    while((fscanf(stdin, "%40s", words)==1) && words[0]!='#')
    {
        fprintf(fp, "%ld %s\n", ++count, words);
    }
    
    puts("File cotents:");
    rewind(fp);
    if(fscanf(fp, "%ld %s", &count, words)==2)
    {
        fprintf(stdout, "%ld %s", count, words);
    }
    puts("Done.");
    if(fclose(fp)!=0)
        fprintf(stderr, "Error closing file\n");
    
    return 0;
}
