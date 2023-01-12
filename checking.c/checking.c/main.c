//
//  main.c
//  checking.c
//
//  Created by 王峥 on 2020/4/22.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
long get_long(void);//check whether input is a integer.
bool bad_limits(long begin, long end,long low, long high);
//check whether the upper limit and lower limit are valid or not.
double sum_squares(long a, long b);//calculate the sum of the squares integers between a and b.
int main(int argc, const char * argv[]) {
    const long MIN=-10000000L;
    const long MAX=+10000000L;
    long start;
    long stop;
    double answer;
    
    printf("This program computes the sum of the squares of"
           "integers in a range.\nThe lower bound should not "
           "be less than -10000000 and \nthe upper bound "
           "should be more than +10000000.\n Enter the "
           "limits(enter 0 for both limits to quit):\n"
           "lower limit: ");
    start=get_long();
    printf("upper limit: ");
    stop=get_long();
    while(start!=0 || stop!=0){
        if(bad_limits(start, stop, MIN, MAX))
            printf("please try again.");
        else{
            answer=sum_squares(start, stop);
            printf("The sum of the squars of the integers");
            printf("from %ld to %ld is %g\n", start, stop, answer);
        }
        printf("Enter the limits(enter 0 for both limits to quit):\n");
        printf("lower limit: ");
        start=get_long();
        printf("upper limit: ");
        stop=get_long();
    }
    printf("Done.\n");
    return 0;
}

long get_long(void){
    long input;
    char ch;
    while(scanf("%ld", &input)!=1){
        while((ch=getchar())!='\n')
            putchar(ch);   //deal with the wrong input.
        printf("is not an integer.\n Please try again:");
    }
    return input;
}

double sum_squares(long a, long b){
    double total=0;
    long i;
    for(i=a;i<=b;i++)
        total+=(double)i * (double)i;
    return total;
}

bool bad_limits(long begin, long end, long low, long high){
    bool not_good=false;
    if(begin>end){
        printf("%ld insn't smaller than %ld", begin, end);
        not_good=true;
    }
    if(begin<low || end<low){
        printf("Value must be or greater than %ld.", low);
        not_good=true;
    }
    if(begin>high || end>high){
        printf("Value must be or smaller than %ld.", high);
        not_good=true;
    }
    return not_good;
}

