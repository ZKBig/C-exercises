//
//  main.c
//  insurance(14.4)
//
//  Created by 王峥 on 2020/5/10.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define LEN 15
#define MAX 50

struct name{
    char fname[LEN];
    char mname[LEN];
    char lname[LEN];
};

struct inform{
    char ins_num[LEN];
    struct name name;
};

char * s_gets(char * st, int n);
void output1(const struct inform * flum, int n);
void output2(struct inform flum[], int n);
void eatline(void);

int main(int argc, const char * argv[]) {
    struct inform people[MAX];
    int count=0;
    
    puts("Please enter the insurance number:");
    puts("type [enter] at the beginning of the line to stop.");
    while(s_gets(people[count].ins_num, LEN)!=NULL &&
          people[count].ins_num[0]!='\0')
    {
        puts("Now enter your first name:");
        s_gets(people[count].name.fname, LEN);
        puts("Now enter your middle name if you have:");
        puts("or type [enter] to skip:");
        s_gets(people[count].name.mname, LEN);
        puts("Now enter your last name:");
        s_gets(people[count++].name.lname, LEN);
        eatline();
        if(count<MAX)
            printf("Please enter the naxt insurance number:\n");
    }
    
    output1(people, count);
    output2(people, count);
    
    return 0;
}

void eatline()
{
    while((getchar())!='\n')
        continue;
}

void output1(const struct inform * flum, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%s,", flum[i].name.lname);
        printf(" %s", flum[i].name.fname);
        if(flum[i].name.mname[0]!='\0')
            printf(" %c.", flum[i].name.mname[0]);
        printf(" -- %s\n", flum[i].ins_num);
    }
}

void output2(struct inform flum[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%s,", flum[i].name.lname);
        printf(" %s", flum[i].name.fname);
        if(flum[i].name.mname[0]!='\0')
            printf(" %c.", flum[i].name.mname[0]);
        printf(" -- %s\n", flum[i].ins_num);
    }
}

char * s_gets(char * str, int n)
{
    char * ret_val;
    char * find;
    
    ret_val=fgets(str, n, stdin);
    if(ret_val)
    {
        find=strchr(str, '\n');
        if(find)
            *find='\0';
        else
            eatline();
    }
    return ret_val;
}
