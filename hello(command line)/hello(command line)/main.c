//
//  main.c
//  hello(command line)
//
//  Created by 王峥 on 2020/5/1.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int i,times;
    
    if(argc<2 || (times=atoi(argv[1]))<1)
        printf("Usage: %s positive-number\n", argv[0]);
    else
        for(i=0;i<times;i++)
            puts("Hello, good looking!");
    return 0;
}
