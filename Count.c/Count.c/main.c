//
//  main.c
//  Count.c
//
//  Created by 王峥 on 2020/4/26.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int ch,count=0;
    while((ch=getchar())!=EOF){
        count++;
    }
    printf("%d", count);
    return 0;
}
