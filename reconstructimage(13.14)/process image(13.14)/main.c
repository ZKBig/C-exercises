//
//  main.c
//  process image(13.14)
//
//  Created by 王峥 on 2020/5/8.
//  Copyright © 2020 王峥. All rights reserved.
//数字图像,尤其是从宇宙飞船发回的数字图像,可能会包含一些失真.为编程练习12添加消除失真
//的函数.该函数把每个值与它上下左右相邻的值作比较,如果该值与周围相邻值的差都大于1 ,
//则用所有相邻值的平均值(四舍五入为整数)代替该值.注意,边界上的点相邻的点少于4个,所以
//做特殊处理.

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
 
# define ROWS 20
# define COLS 30
# define FNAME "no12.trf"
# define FARGS "no121.trf"
# define STR " .':~*=&%#"
 
void initialize_ar(FILE * fp ,int n , int m , int ar[n][m]);
void set_st(int n , int m , char st[n][m + 1] , int ar[n][m]);
void reconstruction(int n , int m , int ar[n][m]);
 
int main(void)
{
    FILE * fp , * ft;
    int ar[ROWS][COLS] ;
    char st[ROWS][COLS + 1] ;
 
    if (!(fp = fopen(FNAME, "r")))
    {
        fprintf(stderr , "Can't open file %s.\n" ,FNAME) ;
        exit(EXIT_FAILURE);
    }
 
    if (!(ft = fopen(FARGS , "w")))
    {
        fprintf(stderr , "Can't open file %s.\n" ,FARGS);
        exit(EXIT_FAILURE);
    }
 
    initialize_ar(fp , ROWS , COLS , ar) ;
    reconstruction(ROWS , COLS ,ar) ;
    set_st(ROWS , COLS , st , ar) ;
 
    for (int i = 0 ; i < ROWS ; i++)
        fprintf(ft ,"%s\n" ,st[i] );
    
    if (fclose(fp) || fclose(ft))
    {
        fprintf(stderr , "Clossing error .\n");
        exit(EXIT_FAILURE);
    }
    
    return 0 ;
}
 
void initialize_ar(FILE * fp ,int n , int m , int ar[n][m])
{
    // 读取文件中的内容到整型数组
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < m ; j++)
            //这样做是为了确保fscanf()正确读到1个数,而不受空格和其他字符影响
            while (fscanf(fp ,"%d" , &ar[i][j]) != 1)
                fscanf(fp ,"%*c");
}
 
void set_st(int n , int m , char st[n][m + 1] , int ar[n][m])
{
    int i , j ;
 
    for (i = 0 ; i < n ; i++)
    {
        for (j = 0 ; j < m ; j++)
        {
            st[i][j] = *(STR + ar[i][j]);
        }
        st[i][j] = '\0';
    }
}
 
void reconstruction(int n , int m , int ar[n][m])
{
    int l, r, u, d;
    
    for(int i=0; i<n; i++)
    {
        l=r=u=d=1;
        int sum=0;
        int count=0;
        
        for(int j=0; j<m; j++)
        {
            if(j>0)
            {
                l=abs(ar[i][j]-ar[i][j-1])>1?1:0;
                count++;
                sum+=ar[i][j-1];
            }
            if(j<m-1)
            {
                r=abs(ar[i][j]-ar[i][j+1])>1?1:0;
                count++;
                sum +=ar[i][j+1];
            }
            if(i>0)
            {
                u=abs(ar[i-1][j]-ar[i][j])>1?1:0;
                count++;
                sum +=ar[i-1][j];
            }
            if(i<n-1)
            {
                d=abs(ar[i][j]-ar[i+1][j])>1?1:0;
                count++;
                sum +=ar[i+1][j];
            }
            if(l && r && u && d)
            {
                ar[i][j]=sum/count;
            }
        }
    }
    
}
