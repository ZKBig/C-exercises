//
//  main.c
//  manybook(14.3)
//
//  Created by 王峥 on 2020/5/9.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAXTITLE 40
#define MAXAUTHO 40
#define MAXBKS 100

struct book{
    char title[MAXTITLE];
    char author[MAXAUTHO];
    float value;
};

void eatline(void);
char * s_gets(char * str, int n);
void showinsequence(const struct book * flum, int n);
void showinletters(struct book * flum[], int n);
void showinprices(struct book * flum[], int n);

int main(int argc, const char * argv[]) {
    struct book library[MAXBKS];
    struct book * book[MAXBKS];
    int count=0;
    
    puts("Please enter the book title:");
    puts("Press [enter] at the start of the line to stop.");
    while(count<MAXBKS && s_gets(library[count].title, MAXTITLE)!=NULL
          && library[count].title[0]!='\0')
    {
        printf("Now enter the auther:\n");
        s_gets(library[count].author, MAXAUTHO);
        printf("Please enter the value.\n");
        scanf("%f", &library[count].value);
        book[count]=&library[count];
        count++;
        eatline();
        if(count<MAXBKS)
            printf("Enter the next title:\n");
    }
    
    showinsequence(library, count);
    showinletters(book, count);
    showinsequence(*book, count);
    showinprices(book, count);
    showinsequence(*book, count);
    return 0;
}

void eatline(void)
{
    while(getchar()!='\n')
        continue;
}

void showinsequence(const struct book * flum, int n)
{
    int index;
    if(n>0)
    {
        puts("Here is the list of books:");
        puts("TITLE               AUTHOR              PRICE");
        for(index=0; index<n;index++, flum++)
            printf("%s %20s %20.2f\n",flum->title, flum->author, flum->value);
    }
}

void showinletters(struct book * flum[], int n)
{
    int top, seek;
    struct book * temp;
    
    for(top=0; top<n-1; top++)
    {
        for(seek=top+1; seek<n; seek++)
        {
            if(strcmp(flum[top]->title,flum[seek]->title )<0)
            {
                temp=flum[top];
                flum[top]= flum[seek];
                flum[seek]= temp;
            }
        }
    }
}

void showinprices(struct book * flum[], int n)
{
    int top, seek;
    struct book * temp;
    
    for(top=0; top<n-1; top++)
    {
        for(seek=top+1; seek<n; seek++)
        {
            if(flum[top]->value<flum[seek]->value)
            {
                temp=flum[top];
                flum[top]= flum[seek];
                flum[seek]= temp;
            }
        }
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
