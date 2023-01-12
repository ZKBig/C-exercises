//
//  main.c
//  average letters in a word(E. 8. 4)
//
//  Created by 王峥 on 2020/4/26.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main(int argc, const char * argv[]) {
    int ch;
    double average;
    int letter=0, word=0;
    bool inword=false;
    while((ch=getchar())!=EOF){
        if(isalpha(ch)){
            letter++;
        }
        else if(!isspace(ch)&&!ispunct(ch)&&!inword){
            word++;
            inword=true;
        }
        else if(isspace(ch)&&inword){
            inword=false;
        }
    }
    average=(double)letter / (double)word;
    printf("The average word number of input is %lf.\n",average);
    return 0;
}
