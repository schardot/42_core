#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

typedef struct v_list
{
    void *connection;
    void *window;
    void *img;
    void *wallimage;
    void *playerimage;
    void *coinimage;
    void *exitimage;
} gamedata;

#endif