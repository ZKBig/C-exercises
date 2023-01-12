//
//  main.c
//  linked list
//
//  Created by 王峥 on 2020/3/3.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student)
struct Student{
    long num;
    float score;
    struct Student * link;
};
int n;
int main() {
    struct Student * head;
    struct Student * creatnode(void);
    int length(struct Student * head);
    void insertnode(struct Student * head);
    void print(struct Student * head);
    void delete(struct Student * head);
    head=creatnode();
    print(head);
    return 0;
}
//creat anew link.
struct Student * creatnode(void){
    struct Student * root, *p1, *p2;
    printf("please enter the school number and the score:\n");
    p1=p2=(struct Student *)malloc(LEN);
    scanf("%ld,%f",&p1->num,&p1->score);
    root=NULL;
    while(p1->num!=0){
        n=n+1;
        if(n==1){
            root=p1;
        }
        else{
            p2->link=p1;}
        p2=p1;
        p1=(struct Student *)malloc(LEN);
        scanf("%ld,%f",&p1->num,&p1->score);
        }
    p2->link=NULL;
    return(root);
}
//find the length of the link.
int length(struct Student * head){
    struct Student *p;
    int count=0;
    p=head;
    while(p!=NULL){
        count++;
        p=p->link;
    }
    return count;
}
//insert a new node in the middle of the link.
void insertnode(struct Student * head){
    int length(struct Student * head);
    struct Student * temp, *p;
    int n,len,i=1;
    printf("The exact position of the inserted node :\n ");
    scanf("%d",&n);
    len=length(head);
    if(n>len){
        printf("error.");
        printf("current list is having %d nodes.", len);}
    else{
        p=head;
        temp=(struct Student *)malloc(LEN);
        printf("please enter the inserted information:\nschool number:\nscore\n");
        scanf("%ld, %f",&temp->num,&temp->score);
        temp->link=NULL;
        while(i<n-1){
            p=p->link;
            i++;
        }
        temp->link=p->link;//right hand.
        p->link=temp;//left hand.
    }
}
//display the list.
void print(struct Student * head){
    struct Student * temp;
    printf("\nNow, these %d records are:\n", n);
    temp=head;
    if(temp==NULL){
        printf("No nodes in the list.\n");
    }
    else if(temp!=NULL){
        printf("school number:%ld, score:%5.1f\n", temp->num, temp->score);
        temp=temp->link;}
}
//delete the nodes.
void delete(struct Student * head){
    int length(struct Student * head);
    struct Student * temp;
    int loc = 0,len;
    len=length(head);
    printf("please enter the number of the node to delete:%d\n",loc);
    scanf("%d", &loc);
    if(loc>len){
        printf("invalid location");
    }
    else if(loc==1){
        temp=head;
        head=temp->link;
        temp->link=NULL;//important.
        free(temp);
    }else{
        struct Student * p=head,*q;
        int i=1;
        while(i<loc-1){
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;//important.
        free(q);
    }
}


    

