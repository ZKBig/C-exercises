//
//  main.c
//  manydice
//
//  Created by 王峥 on 2020/5/3.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(int argc, const char * argv[]) {
    int dice, roll;
    int sides;
    int status;
    
    srand((unsigned int)time(0));
    printf("Enter the number of sides per die, 0 to step.\n");
    while(scanf("%d", &sides)==1 && sides>0)
    {
        printf("How many dice?\n");
        if((status=scanf("%d",&dice))!=1)
        {
            if(status==EOF)
                break;
            else
            {
                printf("You should have enteren an integer.");
                printf("Let's begin again.\n");
                while(getchar()!='\n')
                    continue;
                printf("How many sides? Enter 0 to stop.\n");
                continue;
            }
        }
        roll=roll_n_dice(dice, sides);
        printf("You have rolled a %d using %d %d-sides dice.\n", roll, dice, sides);
        printf("How many sides? Enter 0 to stop.\n");
    }
    printf("The rollem() function was called %d times.\n", roll_count);
    printf("GOOD FORTUNR TO YOU.\n");
    return 0;
}
