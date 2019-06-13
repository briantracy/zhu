// engine.c

#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "complex.h"

char mand(double x, double y);
int test();

int test() {
    printf("%c\n", mand(-1,0));
    return -1;
}


int main(int argc, char *argv[]) {
    //return test();


  int width = atoi(argv[1]), height = atoi(argv[2]);
  double l = -2, r = 1, t = 1, b = -1;

  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      double x = l + ((double)w / (double)width) * (r - l);
      double y = t - ((double)h / (double)height) * (t - b);
      //printf("(%.2f, %.2f)", x, y);
      printf("%c", mand(x, y));
    }
    printf("\n");
  }

}

inline char mand(double x, double y) {
    complex_t z = (complex_t) { .real = 0, .imag = 0 };
    complex_t c = (complex_t) { .real = x, .imag = y };
    int itermax = 256;
    for (int i = 0; i < itermax; i++) {
        z = add(multiply(z, z), c);
        if (mag_squared(z) > 4.0) {
            return ' ';
        }
    }
    return '*';
}


/*
  assert(argc == 3);

  const int width = atoi(argv[1]);
  const int height = atoi(argv[2]);

  assert(width > 0);
  assert(height > 0);

  printf("Generating fractal with [%d, %d]\n", width, height);

  char *mem = malloc(sizeof(char) * width * height);
  assert(mem != NULL);
*/
