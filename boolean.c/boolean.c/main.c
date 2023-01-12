//
//  main.c
//  boolean.c
//
//  Created by 王峥 on 2020/4/19.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    long num;
    long sum=0L;
    _Bool input_is_good;
    printf("please enter an integer to be summed");
    printf("(q to quit):");
    input_is_good=(scanf("%ld", &num)==1);
    while(input_is_good){
        sum=sum+num;
        printf("Please enter next integer(q to quit):");
        input_is_good=(scanf("%ld", &num)==1);
    }
    printf("Those integers sum to %ld.\n",sum);
    return 0;
}
