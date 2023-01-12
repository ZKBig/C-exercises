//
//  main.c
//  showchar
//
//  Created by 王峥 on 2020/4/22.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
void display(char c, int lines, int width);
int main(int argc, const char * argv[]) {
    int ch;
    int rows, cols;
    printf("Enter a character and two integers:\n");
    while((ch=getchar())!=EOF){
        if(scanf("%d %d", &rows, & cols)!=2)
            break;
        display((char)ch, rows, cols);
        while(getchar()!='\n')
            continue;
        printf("Enter another charater and two integers:\n");
    }
    return 0;
}
void display(char c, int lines, int width){
    int row, col;
    for(row=1;row<=lines;row++){
        for(col=1;col<=width;col++)
            putchar(c);
        putchar('\n');}
}
