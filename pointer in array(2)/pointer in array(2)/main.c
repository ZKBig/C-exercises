//
//  main.c
//  pointer in array(2)
//
//  Created by 王峥 on 2020/2/28.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#define N 10
int main() {
    void sort(int *arr, int n);
    int array[N], *p;
    int i;
    p=array;
    printf("please enter numbers:\n");
    for(i=0;i<N;i++)
        scanf("%d", p++);
    p=array;
    sort(p, 10);
    printf("The sorted numbers are:\n");
    for(p=array,i=0;i<N;i++){
        printf("%d ", *p++);
    }
    printf("\n");
    return 0;
}
void sort(int *arr, int n){
    int i, j, max,temp;
    for(i=0;i<n-1;i++){
        max=i;
        for(j=i+1;j<n;j++){
            if(*(arr+j)>*(arr+max)){
                max=j;
                temp= *(arr+i);
                *(arr+i)= *(arr+max);
                *(arr+max)=temp;
            }
        }
    }
}
