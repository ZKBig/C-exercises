//
//  main.c
//  invert numbers to images(13.12)
//
//  Created by 王峥 on 2020/5/8.
//  Copyright © 2020 王峥. All rights reserved.
//创建文本文件,内含20行,每行30个整数.这些整数都在0~9之间,用空格分开.该文件是用数字表示一张
//图片,0~9表示逐渐增加的灰度.编写一个程序把文件中的内容读入一个20X30的int数组中.一种把这些
//数字转换为图片的粗略方法是:该程序使用数组中的值初始化一个20X31的字符数组,用值0对应空格字符
//,1对应点字符,以此类推.数字越大表示字符所占空间越大.例如,用#表示9.每行的最后一个字符(第31个)
//是空字符,这样该数组包含了20个字符串.最后程序显示最终的图片(即,打印所有的字符串),并将结果
//储存在文本文件中.例如,下面是开始的数据.
/* 文件中的内容:
 0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0
 0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0
 0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0
 5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
 8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
 9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9
 8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
 5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
 0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
 0 0 0 0 2 2 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
 0 0 0 0 3 3 0 0 0 0 0 0 5 8 9 9 8 5 0 5 6 1 1 1 1 6 5 0 0 0
 0 0 0 0 4 4 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
 0 0 0 0 5 5 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
 */

#include <stdio.h>
#include <stdlib.h>
#define FNAME "no12.rtf"
#define FARGE "no121.rtf"
#define LEN 30

int main(int argc, const char * argv[]) {
    int num[20][LEN];
    char str[20][LEN+1];
    FILE * fa, * fb;
    
    char STR[11]=" .':~*=&%#";
    
    if((fa=fopen(FNAME, "r"))==NULL)
    {
        fprintf(stderr, "Can't open the file %s.\n", FNAME);
        exit(EXIT_FAILURE);
    }
    if((fb=fopen(FARGE, "w"))==NULL)
    {
        fprintf(stderr, "Can't open the file %s.\n", FARGE);
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<LEN; j++)
        {
            while(fscanf(fa, "%d", &num[i][j])!=1)
                fscanf(fa, "%*c");   //skip the characters.
        }
    }
    
    for(int i=0; i<20; i++)
    {
        int j;
        for(int j=0; j<LEN; j++)
        {
            str[i][j]=*(STR +num[i][j]);
        }
        str[i][j]='\0';
        fprintf(stdout, "%s\n", str[i]);
    }
    
    if(fclose(fa) || fclose(fb))
    {
        fprintf(stderr, "Close errer.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
