//
//  main.c
//  join_chk(strncat)
//
//  Created by 王峥 on 2020/5/1.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define SIZE 30
#define BUGSIZE 13
char * s_gets(char * st, int n);

int main(int argc, const char * argv[]) {
    char flower[SIZE];
    char addon[]="s mell like old shoes.";
    char bug[BUGSIZE];
    unsigned int available;
    
    puts("What is your favourite flower?");
    s_gets(flower, SIZE);
    if((strlen(addon)+strlen(flower)+1)<+SIZE)
        strcat(flower, addon);
    puts(flower);
    puts("What is your favourite bug?");
    s_gets(bug, BUGSIZE);
    available=BUGSIZE-strlen(bug)-1;
    strncat(bug, addon, available);
    puts(bug);
    
    return 0;
}

char * s_gets(char * st, int n)
{
    char * pq;
    int i=0;
    
    pq=fgets(st, n, stdin);
    if(pq)
    {
        while(st[i]!='\n' && st[i]!='\0')
            i++;
        if(st[i]=='\n')
            st[i]='\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return pq;
}
