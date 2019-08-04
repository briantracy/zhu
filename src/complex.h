// complex.h

#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <math.h>

typedef struct {
  double real, imag;
} complex_t;


inline double magnitude(complex_t arg) {
    return sqrt(arg.real * arg.real + arg.imag * arg.imag);
}

inline double mag_squared(complex_t arg) {
    return arg.real * arg.real + arg.imag * arg.imag;
}

inline complex_t add(complex_t a, complex_t b) {
    return (complex_t) { 
        .real = a.real + b.real,
        .imag = a.imag + b.imag
    };
}

inline complex_t multiply(complex_t a, complex_t b) {
    return (complex_t) {
        .real = a.real * b.real - a.imag * b.imag,
        .imag = a.real * b.imag + a.imag * b.real
    };
}

#endif // _COMPLEX_H
