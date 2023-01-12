//
//  main.c
//  fields.c(15. bit field)
//
//  Created by 王峥 on 2020/4/26.
//  Copyright © 2020 王峥. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
/* the types of line*/
#define SOLID 0
#define DOTTED 1
#define DASHED 2
/*three-primary colors*/
#define BLUE 4
#define GREEN 2
#define RED 1
/*the mixed color*/
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN    (GREEN |BLUE)
#define WHITE   (RED | GREEN | BLUE)

const char * colors[8]={"black", "red", "green", "yellow",
                       "blue", "magenta", "cyan", "white"};

struct box_props{
    bool opaque: 1;
    unsigned int fill_color: 3;
    unsigned int :4;
    bool show_border: 1;
    unsigned int border_color: 3;
    unsigned int border_style: 2;
    unsigned int: 2;
};

void show_settings(const struct box_props * p);

int main(int argc, const char * argv[]) {
    struct box_props box={ true, YELLOW, true, GREEN, DASHED};
    printf("Original box settings:\n");
    show_settings(&box);
    
    box.opaque=false;
    box.fill_color=WHITE;
    box.border_color=MAGENTA;
    box.border_style=SOLID;
    printf("\nModified box settings.\n");
    show_settings(&box);
    
    return 0;
}

void show_settings(const struct box_props * p){
    printf("Box is %s.\n",
           p->opaque==true? "opaque" : "transparent");
    printf("The fill color is %s.\n",
           colors[p->fill_color]);
    printf("Border %s.\n",
           p->show_border==true? "shown" : "not shown");
    printf("The border color is %s.\n",
           colors[p->border_color]);
    printf("The border is ");
    switch (p->border_style)
    {
        case SOLID: printf("solid.\n");
            break;
        case DOTTED: printf("dotted.\n");
            break;
        case DASHED: printf("deshed.\n");
            break;
        default: printf("unknown type.\n");
    }
}

