
//
//  main.c
//  guess number(E.8.5)
//
//  Created by 王峥 on 2020/4/26.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int guess=50;
    int response;
    int upper_limit=100, lower_limit=1;
    printf("Pick an integer from 1 to 100. I will try to guess");
    printf("it.\n Respond with a y if my guess is right and with");
    printf("\n an g if it is greater than your number and an s if");
    printf("\n it is smaller than your number.");
    printf("Uh……is your number %d?\n ", guess);
    while((response=getchar())!='y'){
        if(response=='g'){
            upper_limit=guess;
            guess=(lower_limit+upper_limit)/2;
        }
        else if(response=='s'){
            lower_limit=guess;
            guess=(upper_limit+lower_limit)/2;
        }
        printf("Well, then, is it %d?", guess);
        while(getchar()!='\n')
              continue;
    }
    printf("I knew I could do it.\n");
    return 0;
}


