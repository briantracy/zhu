// zhu -- argparse.c

#include <getopt.h>
#include <string.h>

#include "argparse.h"
#include "structures.h"

int parse_args(int argc, char *argv[], command_line_args *args)
{
    static struct option options[] = {
        {"outfile", required_argument, NULL, 'o'},
        {"date", required_argument, NULL, 'd'},
        {0, 0, 0, 0}
    };

    char ch;
    while ((ch = getopt_long(argc, argv, "o:d:", options, NULL)) != -1) {
        switch (ch) {
        case 'o':
            strcpy(args->outfile_name, optarg);
            break;
        case 'd':
            break;
        }
    }


    return 0;
}
