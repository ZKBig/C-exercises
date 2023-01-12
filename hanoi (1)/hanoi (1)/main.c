//
//  main.c
//  hanoi (1)
//
//  Created by 王峥 on 2020/2/26.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
int main() {
    void hanoi(int n, char A, char B, char C);
    int n;
    printf("please enter the number of disks:\n");
    scanf("%d", &n);
    printf("the steps to move %d disks:\n", n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}

void hanoi(int n, char A , char B, char C){
    if(n==1){
        printf("%c-->%c\n", A, C);
    }
    else {
        hanoi(n-1, A, C, B);
        printf("%c-->%c\n", A, C);
        hanoi(n-1, B, A, C);
    }
}
