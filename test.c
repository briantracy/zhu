// test.c

#include <stdio.h>
#include "src/argparse.h"

void test(int boolean, char *name) {
    const char *ansi_red   = "\x1b[31m";
    const char *ansi_green = "\x1b[32m";
    const char *ansi_none  = "\x1b[0m";

    const char *color   = boolean ? ansi_green : ansi_red;
    const char *success = boolean ? "failed" : "passed";

    printf("%s[%s] -- test %s%s\n", color, name, success, ansi_none);
}

int test_argparse() {
    return 0;
}

int main(int argc, char *argv[]) {
    
    test(0, "stack");
    test(1, "overflow");
    test(0, "yesterday");
    test(1, "world");
}



