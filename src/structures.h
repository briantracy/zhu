// structures.h

#ifndef _STRUCTURES_H
#define _STRUCTURES_H

#include <limits.h>

typedef struct {
    unsigned int width, height;
} picture_size;

typedef struct {
    double top, bottom, left, right;
} frame;

typedef struct {
    picture_size picture_size;
    frame frame;
    char outfile_name[PATH_MAX];
    char fractal_name[64];
} command_line_args;

#endif
