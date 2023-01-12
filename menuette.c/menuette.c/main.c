//
//  main.c
//  menuette.c
//
//  Created by 王峥 on 2020/4/22.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);
int main(int argc, const char * argv[]) {
    int choice;
    void count(void);
    while((choice=get_choice())!='q'){
        switch(choice)
        {
            case 'a': printf("Buy low, sell high.\n");
                break;
            case 'b': putchar('\a'); /*ANSI*/
                break;
            case 'c': count();
                break;
            default: printf("Program error!\n");
                break;
        }
    }
    printf("Buy.\n");
    return 0;
}

void count(void){
    int n,i;
    printf("Count how far? Enter an integer:\n");
    n=get_int();
    for(i=1;i<=n;i++)
        printf("%d ",i);
    while(getchar()!='\n')
        continue;
}

char get_choice(void){
    int ch;
    printf("Enter the letter of your choice:\n");
    printf("a. advice         b. bell\n");
    printf("c. count          q. quit\n");
    ch=get_first();
    while((ch<'a' || ch>'c')&&ch!='q'){
        printf("please respond with a, b, c, q.\n");
        ch=get_first();
    }
    return ch;
}

char get_first(void){
    int ch;
    ch=getchar();
    while(getchar()!='\n')
        continue;
    return ch;
}

int get_int(void){
    int input;
    char ch;
    while(scanf("%d", &input)!=1 ){
        while((ch=getchar())!='\n')
            putchar(ch);
        printf("is not an integer.\n Please try again:");
    }
    return input;
}


