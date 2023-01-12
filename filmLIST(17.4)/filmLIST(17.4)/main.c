//
//  main.c
//  filmLIST(17.4)
//
//  Created by 王峥 on 2020/5/11.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
void showmovies(Item item);
char * s_gets(char * str, int n);
void eatline(void);

int main(int argc, const char * argv[]) {
    List movies;
    Item temp;
    
    InitializeList(&movies);
    if(ListIsFull(&movies))
    {
        fprintf(stderr, "No memory available.\n");
        exit(EXIT_FAILURE);
    }
    
    puts("Enter first movie title:");
    while(s_gets(temp.title, TSIZE)!=NULL && temp.title[0]!='\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        eatline();
        if(AddItemE(temp, &movies)==false)
        {
            fprintf(stderr, "Problem allocating memory.\n");
            break;
        }
        if(ListIsFull(&movies))
        {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }
    
    if(ListIsEmpty(&movies))
        printf("No data entered.\n");
    else
    {
        printf("Here is the movie list:\n");
        Traverse(&movies, showmovies);
    }
    
    putchar('\n');
    movies=InvertList(movies);
    printf("Here is the inverted movie list:\n");
    Traverse(&movies, showmovies);
    
    printf("You entered %d movies.\n", ListItemCount(&movies));
    
    EmptyTheList(&movies);
    printf("Done.\n");
    
    return 0;
}

void eatline(void)
{
    while((getchar())!='\n')
        continue;
}

void showmovies(Item item)
{
    printf("Movie: %s     Rating: %d\n", item.title, item.rating);
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
