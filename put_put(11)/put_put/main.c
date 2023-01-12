//
//  main.c
//  put_put
//
//  Created by 王峥 on 2020/5/1.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
void put1(const char * );
int put2(const char * );

int main(int argc, const char * argv[]) {
    put1("If I'd as much money,");
    put1("as I could spent.\n");
    printf("I count %d characters.\n", put2("I never would cry old chris to mend."));
    
    return 0;
}

void put1(const char * pq)
{
    while(*pq)
        putchar(*pq++);
}

int put2(const char * pq)
{
    int count=0;
    while(*pq)
    {
        putchar(*pq++);
        count++;
    }
    putchar('\n');
    
    return count;
}
