//
//  main.c
//  prime
//
//  Created by 王峥 on 2020/2/22.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include "math.h"
int mian(){
    int i,n,k;
    printf("please enter an integer number: n=\n");
    scanf("%d", &n);
    k=sqrt(n);
    for(i=2;i<=k;i++){
        if(n%i==0){break;}}
    if(i<k){
        printf("%d is not a prime.\n",n);
    }
    else{printf("%d is a prime.\n",n);}
    return 0;
}

