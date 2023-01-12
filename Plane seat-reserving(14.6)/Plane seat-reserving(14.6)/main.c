//
//  main.c
//  SoftballTeam(14.6)
//
//  Created by 王峥 on 2020/5/10.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define LEN 20
#define MAX 12

struct name{
    char fname[LEN];
    char lname[LEN];
};

typedef struct seat{
    int num;
    bool reserve_seat;
    struct name name;
}SEAT;

char * s_gets(char * str, int n);
char showmenu(void);
void eatline(void);
void InitializeSeats(SEAT * pt, int n);
void AssignSeat(SEAT * pt, int n);
void DeleteSeat(SEAT * pt, int n);
void EmptySeatsCount(const SEAT * pt, int n);
void EmptySeatsList(const SEAT * pt, int n);
static bool SeatsAreFull(const SEAT * pt, int n);

int main(int argc, const char * argv[]) {
    SEAT jet[MAX];
    char choice;
    
    InitializeSeats(jet, MAX);
    while((choice=showmenu())!='f')
    {
        switch(choice)
        {
            case 'a': EmptySeatsCount(jet, MAX);
                break;
            case 'b': EmptySeatsList(jet, MAX);
                break;
            case 'c':
                break;
            case 'd': AssignSeat(jet, MAX);
                break;
            case 'e': DeleteSeat(jet, MAX);
                break;
            default: printf(" Error!\n");
        }
    }
    return 0;
}

char showmenu(void)
{
    int ch;
    
    puts("Please choose a function, enter its letter lable:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seat");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
    while((ch=getchar())!=EOF)
    {
        eatline();
        ch=tolower(ch);
        if(strchr("abcdef", ch)==NULL)
            printf("Please enter the choices from a, b, c, d, e or f.\n");
        else
            break;
    }
    if(ch==EOF)
        ch='f';

    return ch;
}

void eatline()
{
    while((getchar())!='\n')
        continue;
}

void InitializeSeats(SEAT * pt, int n)
{
    for(int i=0; i<n; i++)
    {
        pt[i].num=i+1;
        pt[i].reserve_seat=false;
    }
}

static bool SeatsAreFull(const SEAT * pt, int n)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        if(pt[i].reserve_seat)
            count++;
    }
    if(count==n)
        return true;
    else
        return false;
}

void EmptySeatsCount(const SEAT * pt, int n)
{
    if(SeatsAreFull(pt, n))
    {
        printf("Sorry, all seats are reserved.\n");
        exit(1);
    }
    
    int count=0;
    for(int i=0; i<n; i++)
    {
        if(pt[i].reserve_seat)
            count++;
    }
    count=n-count;
    printf("There are %d seats available.\n", count);
}

void EmptySeatsList(const SEAT * pt, int n)
{
    if(SeatsAreFull(pt, n))
    {
        printf("Sorry, all seats are reserved.\n");
        exit(1);
    }
    for(int i=0; i<n; i++)
    {
        if(!pt[i].reserve_seat)
            printf("%d ", i+1);
    }
    putchar('\n');
}

void AssignSeat(SEAT * pt, int n)
{
    int j;
    puts("Please enter the seat number:");
    while(scanf("%d", &j)==1 && j>n)
        printf("Please enter the number of seat smaller than %d:\n", n);
    eatline();
    puts("Please enter your first name:");
    s_gets(pt[j-1].name.fname, LEN);
    puts("Please enter your last nmae:");
    s_gets(pt[j-1].name.lname, LEN);
    pt[j-1].reserve_seat=true;
    puts("Reserve successfully.");
}

void DeleteSeat(SEAT * pt, int n)
{
    int j, i=0;
    puts("Please enter the seat number to be deletes:");
    while(scanf("%d", &j)==1 && j>n)
        printf("Please enter the number smaller than %d", n);
    eatline();
    pt[j-1].reserve_seat=false;
    while(pt[j-1].name.fname[i]!='\0')
    {
        pt[j-1].name.fname[i]='\0';
        i++;
    }
    while(pt[j-1].name.lname[i]!='\0')
    {
        pt[j-1].name.lname[i]='\0';
        i++;
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







