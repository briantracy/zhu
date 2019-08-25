// engine.c
int x;
#if 0

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
    int f = open("./file.data", O_RDWR);
    char x[4] = { 1, 2, 3, 4 };
    write(f, x, 4);
    printf("%c\n", mand(-1,0));
    return -1;
}

int test2();
int test2() {
    
    return 0;
}

int main(int argc, char *argv[]) {
    int fdes = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fdes == -1) {
        perror("open");
        return 1;
    }
    if (ftruncate(fdes, 4096) == -1) {
        perror("ftruncate");
    }
    char *addr = mmap(NULL, 4096,PROT_READ| PROT_WRITE, MAP_SHARED, fdes, 0);
    if (addr == NULL) {
        perror("mmap");
        return 1;
    }
    
    printf("got mapping at %p\n", addr);
    addr[0] = 'H';
    addr[1] = 'E';
    addr[2] = 'L';
    addr[3] = '\n';


    return 0;
  return test();


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
#endif
