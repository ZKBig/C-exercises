//
//  main.c
//  traverse(13.4)
//
//  Created by 王峥 on 2020/5/7.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int n;
    if(argc<2)
    {
        printf("Usage: %s.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("The names of the file:\n");
        for(n=0; n<=argc; n++)
        {
            printf("%s", argv[n]);
        }
    }
    return 0;
}
