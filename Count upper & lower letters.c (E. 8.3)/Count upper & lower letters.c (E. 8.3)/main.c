//
//  main.c
//  Count upper & lower letters.c (E. 8.3)
//
//  Created by 王峥 on 2020/4/26.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
int main(int argc, const char * argv[]) {
    int ch;
    int count=0,number=0;
    while((ch=getchar())!=EOF){
        if(isupper(ch)){
            count++;
        }
        else if(islower(ch)){
            number++;
        }
    }
    printf("There are %d upper letters and %d lower letters.\n", count, number);
    return 0;
}
