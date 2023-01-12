//
//  main.c
//  studentgrade(14.5)
//
//  Created by 王峥 on 2020/5/10.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20
#define CSIZE 4

struct name{
    char fname[LEN];
    char lname[LEN];
};

struct student{
    struct name name;
    float grades[4];
    float average;
};

void eatline(void);
char * s_gets(char * str, int n);
void InputGrade(struct student *p);
void ComputeAver(struct student *p);
void Output(struct student *p);
void Wholeaverage(struct student *p);

int main(int argc, const char * argv[]) {
    struct student pupil[CSIZE]={
        {.name={"Wang" "Zhengyi"}},
        {.name={"Kuang" "Yuqiang"}},
        {.name={"Bai" "Xiaokang"}},
        {.name={"Liu" "Lulu"}}
    };
    
    InputGrade(pupil);
    ComputeAver(pupil);
    Output(pupil);
    
    
    
    return 0;
}

void InputGrade(struct student *p)
{
    char *name[CSIZE];
    float grades[CSIZE];
    int n=0;
    
    puts("Please enter the name of the student:");
    puts("type [enter] at the bi=eginning of the line to stop.");
    while(s_gets(name[n], 20)!=NULL && name[n]!='\0')
    {
        int j=0;
        puts("Now enter three scores:");
        for(int i=0; i<3; i++)
            scanf("%f", &grades[i]);
        while(strcmp(name[n], strcat(p[j].name.fname,
                                     p[j].name.lname))!=0)
            j++;
        for(int i=0; i<3; i++)
            p[j].grades[i]=grades[i];
        n++;
        eatline();
        puts("Please enter the next student name:");
    }
}

void eatline()
{
    while((getchar())!='\n')
        continue;
}

void ComputeAver(struct student *p)
{
    float aver, count=0;
    for(int n=0; n<CSIZE; n++)
    {
        for(int i=0; i<3; i++)
        {
            count+=p[n].grades[i];
        }
        printf("%s %s  %0.2f.\n", p[n].name.fname,
               p[n].name.lname, aver=count/3);
    }
}

void Output(struct student *p)
{
    for(int i=0; i<CSIZE; i++)
    {
        printf("%s %s  %0.2f %0.2f %0.2f  %0.2f",
               p[i].name.fname, p[i].name.lname,
               p[i].grades[0], p[i].grades[1], p[i].grades[2],
               p[i].average);
    }
}

void WholeAver(struct student *p)
{
    float count=0,sum=0;
    for(int i=0; i<CSIZE; i++)
    {
        for(int j=0; j<3; j++)
        {
            count+=p[i].grades[j];
        }
        sum+=count;
    }
    printf("The average grades of the whole class is %0.2f",
           sum/(CSIZE * 3));
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









