//
//  main.c
//  ASCII print(E.8.2)
//
//  Created by 王峥 on 2020/4/26.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int ch,i=0;
    while((ch=getchar())!=EOF){
        if(ch=='\n')
        {   putchar('\\');
            putchar('n');
            printf("%d\t ", ch);
        }
        else if(ch=='\t')
        {   putchar('\\');
            putchar('t');
            printf("%d\t ", ch);
        }
        //在ASCII中，空格前面的字符都是非打印字符，用^来表示
        else if(ch<' '){
            putchar('^');
            putchar(ch+64);
            printf("%d\t ", ch);
        }
        else{
            printf("%c %d", ch, ch);
        }
        if(i++==9){
            printf("\n");
            i=0;
        }
    }
    return 0;
}
