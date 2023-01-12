//
//  main.c
//  wordcnt
//
//  Created by 王峥 on 2020/4/22.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
int main(int argc, const char * argv[]) {
    int c;//the returned value of getchar is int.
    char prev;
    int n_lines=0;
    long n_chars=0L;
    int n_words=0;
    int p_lines=0;
    bool inword=false; //if c is in the word, inword=true.
    printf("Enter text to be analyzed:\n");
    prev='\n';
    while((c=getchar())!=EOF){
        n_chars++;
        if(c=='\n')
            n_lines++;
        if(!isspace(c)&&!inword)
            inword=true;
            n_words++;
        if(isspace(c)&&inword)
            inword=false;
        prev=c;
    }
    if (prev!='\n')
        p_lines=1;
    printf("characters=%ld, words=%d, lines=%d, partial lines=%d.\n",n_chars, n_words, n_lines, p_lines);
    return 0;
}
