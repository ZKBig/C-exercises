//
//  main.c
//  mall
//
//  Created by 王峥 on 2020/4/29.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>                   //provide prototype of rand() and srand()
#include <time.h>                     //provide prototype of time()
#include "queue.h"
#define MIN_PER_HR 60.0

bool newcustomer (double x);          //whether there is new customer?
Item customertime (long when);        //set the coefficient of cunstomer

int main(void)
{
    queue line;
    Item temp;                        //the data of new customer
    int hours;                        //the simulation of hours
    int perhour;                      //the customers per hour
    long cycle, cyclelimit;           //loop counter and the limit of counter
    long turnaways=0;                 //the number of customers who turn away due to the queue is full
    long customers=0;                 //the number of customers who join in the queue
    long served=0;                    //the number of customers who consult with the barrister
    long sum_line=0;                  //the accumulaiton length of the queue
    int wait_time=0;                  //the time betweem now and the barrister is free
    double min_per_cust;              //the average time of customers coming here
    long line_wait=0;                 //the sum of the waiting time of the queue
    
    InitializeQueue(&line);
    srand((unsigned int)time(0));     //the random initializaiton of rand()
    puts("case study: Barrister");
    puts("Enter the number of simulaiton hours:");
    scanf("%d", &hours);
    cyclelimit=MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust=MIN_PER_HR/perhour;
    
    for(cycle=0; cycle<cyclelimit; cycle++)
    {
        if(newcustomer(min_per_cust))
        {
            if(QueueIsFull(&line))
                turnaways++;
            else
            {
                customers++;
                temp=customertime(cycle);
                AddQueue(temp, &line);
            }
        }
        if(wait_time<=0 && !QueueIsEmpty(&line))
        {
            DeQueue(&temp, &line);
            wait_time=temp.processtime;
            line_wait+=cycle-temp.arrive;
            served++;
        }
        if(wait_time>0)
            wait_time--;
        sum_line+=QueueItemCount(&line);
    }
    
    if(customers>0)
    {
        printf("customers accepted: %ld\n", customers);
        printf("  customers served: %ld\n", served);
        printf("          turnaway: %ld\n", turnaways);
        printf("average queue size: %0.2f\n", (double)sum_line/cyclelimit);
        printf(" average wait time: %0.2f\n", (double)line_wait/served);
    }
    else
    {
        puts("No customers.");
    }
    EmptyTheQueue(&line);
    
    return 0;
}

bool newcustomer(double x)
{
    if(rand()*x/RAND_MAX<1)
        return true;
    else
        return false;
}

Item customertime(long when)
{
    Item cust;
    
    cust.processtime=rand()%3+1;
    cust.arrive=when;
    
    return cust;
}
