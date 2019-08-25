// zhu -- argparse.c

#include <getopt.h>
#include <stdio.h>
#include <string.h>

#include "argparse.h"
#include "structures.h"

static int parse_size_format(char *, picture_size *);

int parse_args(int argc, char *argv[], command_line_args *args)
{
    static struct option options[] = {
        {"outfile", required_argument, NULL, 'o'},
        {"size", required_argument, NULL, 's'},
        {0, 0, 0, 0}
    };

    char ch;
    while ((ch = getopt_long(argc, argv, "o:s:", options, NULL)) != -1) {
        switch (ch) {
        case 'o':
            strcpy(args->outfile_name, optarg);
            break;
        case 's':
            if (parse_size_format(optarg, &args->picture_size)) {
                fprintf(stderr, "error: invalid picture size: [%s]\n", optarg);
                return 1;
            }
            break;
        default:
            printf("optarg: [%s]\n", optarg);
        }
    }


    return 0;
}

static int parse_size_format(char *str, picture_size *size)
{
    (void)str;
    size->width = 1920;
    size->height = 1080;
    return 0;
}