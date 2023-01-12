//
//  main.c
//  Fibonacci
//
//  Created by 王峥 on 2020/2/22.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>

int main() {
    int f1=1, f2=1;
    int i;
    for(i=1;i<=20;i++){
        printf("%12d%12d", f1, f2);
        if(i%2==0){
            printf("\n");
        }
        f1=f1+f2;
        f2=f2+f1;
    }
    
    return 0;
}
