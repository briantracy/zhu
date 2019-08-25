// main.c

#include <stdio.h>
#include <getopt.h>

#include "src/argparse.h"
#include "src/structures.h"

int main(int argc, char *argv[])
{
    command_line_args args;

    if (parse_args(argc, argv, &args) != 0) {
        fprintf(stderr, "error: could not parse command line arguments");
        return 1;
    }

    printf("[%s]\n", args.outfile_name);
    printf("[%d, %d]\n", args.picture_size.height, args.picture_size.width);
    return 0;
}
