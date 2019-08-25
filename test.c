// test.c

#include <stdio.h>
#include <string.h>
#include "src/argparse.h"

void test(int boolean, char *name) {
    const char *ansi_red   = "\x1b[31m";
    const char *ansi_green = "\x1b[32m";
    const char *ansi_none  = "\x1b[0m";

    const char *color   = boolean ? ansi_green : ansi_red;
    const char *success = boolean ? "passed" : "failed";

    printf("%s[%s] -- test %s%s\n", color, name, success, ansi_none);
}

void test_argparse() {
    command_line_args args;
    int argc = 3;
    char *argv[] = {
        "./test", "--outfile=out.data", "--size=12x23"
    };
    parse_args(argc, argv, &args);
    test(strcmp("out.data", args.outfile_name) == 0, "processes outfile name");
    test(args.picture_size.width == 1920 && args.picture_size.height == 1080, "processes picture size");
}

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    
    test_argparse();
}



