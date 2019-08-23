// structures.h

#ifndef _STRUCTURES_H
#define _STRUCTURES_H


typedef struct {
    unsigned int width, height;
} picture_size;

typedef struct {
    double top, bottom, left, right;
} frame;

typedef struct {
    picture_size picture_size;
    frame frame;
    char *outfile_name;
    char *fractal_name;
} command_line_args;

#endif
