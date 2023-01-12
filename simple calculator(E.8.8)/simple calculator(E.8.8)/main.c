//
//  main.c
//  simple calculator(E.8.8)
//
//  Created by 王峥 on 2020/4/26.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <math.h>
char get_choice(void);
char get_first(void);
void add(void);
void subtract(void);
void multiply(void);
void divide(void);
void power(void);
int main(int argc, const char * argv[]) {
    void numbers(void);
    int ch;
    float num;
    while((ch=get_choice())!='q')
    {
        switch(ch)
        {
            case 'a':add();
                break;
            case 'b':subtract();
                break;
            case 'c':multiply();
                break;
            case 'd':divide();
                break;
            case 'e':printf("please enter the number:\n");
                     scanf("%f", &num);
                     printf("%f\n", sqrt(num));
                break;
            case 'f':power();
                break;
            default: printf("Program error!\n");
                break;
        }
    }
    printf("BUY!\n");
    return 0;
}
char get_choice(void){
    int ch;
    printf("Enter the operation of your choice:\n");
    printf("a. add            b.subtract\n");
    printf("c. multiply       d. divide\n");
    printf("e. sqrt           f. power\n");
    printf("q. quit\n");
    ch=get_first();
    while((ch<'a' || ch>'g') && ch !='q'){
        printf(" please respond with a, b, c, d, e, f or q.\n");
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

void add(void){
    float number1, number2, add;
    int ch;
    printf("Enter first number:\n");
    while(scanf("%f", &number1)!=1){
           while((ch=getchar())!='\n')
               putchar(ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:\n");
       }
    printf("Enter second number:\n");
    while(scanf("%f", &number2)!=1){
              while((ch=getchar())!='\n')
                  putchar(ch);
           printf(" is not an number.\n");
           printf("Please enter a number, such as 2.5, -1.78E8, or 3:\n");
          }
    add=number1+number2;
    printf("%f\n", add);
    return ;
}

void subtract(void){
    float number1, number2, sub;
    int ch;
    printf("Enter first number:\n");
    while(scanf("%f", &number1)!=1){
           while((ch=getchar())!='\n')
               putchar(ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:\n");
       }
    printf("Enter second number:\n");
    while(scanf("%f", &number2)!=1){
              while((ch=getchar())!='\n')
                  putchar(ch);
           printf(" is not an number.\n");
           printf("Please enter a number, such as 2.5, -1.78E8, or 3:\n");
          }
    sub=number1-number2;
    printf("%f\n", sub);
    return ;
}

void multiply(void){
    float number1, number2, multi;
    int ch;
    printf("Enter first number:\n");
    while(scanf("%f", &number1)!=1){
           while((ch=getchar())!='\n')
               putchar(ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:\n");
       }
    printf("Enter second number:\n");
    while(scanf("%f", &number2)!=1){
              while((ch=getchar())!='\n')
                  putchar(ch);
           printf(" is not an number.\n");
           printf("Please enter a number, such as 2.5, -1.78E8, or 3:\n");
          }
    multi=number1*number2;
    printf("%f\n", multi);
    return ;
}

void divide(void){
    float number1, number2, div;
    int ch;
    printf("Enter first number:\n");
    while(scanf("%f", &number1)!=1){
           while((ch=getchar())!='\n')
               putchar(ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:\n");
       }
    printf("Enter second number:\n");
    while(scanf("%f", &number2)!=1){
        if(number2==0){
            printf("Enter a number other than 0:\n");
            continue;}
        else
              while((ch=getchar())!='\n')
                  putchar(ch);
           printf(" is not an number.\n");
           printf("Please enter a number, such as 2.5, -1.78E8, or 3:\n");
          }
    div=number1/number2;
    printf("%f\n", div);
    return ;
}

void power(void){
    float number;
    int ch,n;
    printf("Enter the number:\n");
    while(scanf("%f", &number)!=1){
           while((ch=getchar())!='\n')
               putchar(ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3:\n");
       }
    printf("please enter the power you want:\n");
    scanf("%d", &n);
    printf("%f\n", pow(number, n));
    return ;
}




