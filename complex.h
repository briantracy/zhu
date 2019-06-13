// complex.h
#ifndef _COMPLEX_H
#define _COMPLEX_H

typedef struct {
  double real, imag;
} complex_t;

double magnitude(complex_t);
double mag_squared(complex_t);
complex_t add(complex_t, complex_t);
complex_t multiply(complex_t, complex_t);

#endif