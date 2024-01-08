#include <stdio.h>
#include "complex.h"
#include <math.h>

Complex Cxcreate(double a, double b)
{
    Complex C;
    C.real = a;
    C.imag = b;
    return C;
}

Complex Cxaddition(Complex c1, Complex c2)
{
    Complex C;
    C.real = c1.real+ c2.real;
    C.imag = c1.imag + c2.imag;
    return C;
}

