#include <stdio.h>
#include "complex.h"
#include <math.h>
#include <stdlib.h>

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

Complex Cxmultiplication(Complex c1, Complex c2)
{
    Complex C;
    C.real = (c1.real*c2.real) - (c1.imag*c2.imag);
    C.imag = (c1.imag*c2.real) + (c1.real*c2.imag);
    return C;
}

Complex Cxdivision(const Complex c1, const Complex c2)
{
    Complex C;
    C = Cxmultiplication(c1, Cxinverse(c2));
    return C;
}

Complex Cxconjugate(Complex C)
{
    Complex Cconj;
    Cconj.real = (Cxmod(C)*Cxmod(C))*(Cxinverse(C).real);
    Cconj.imag = (Cxmod(C)*Cxmod(C))*(Cxinverse(C).imag);
    return Cconj;
}

Complex Cxinverse(Complex C)
{
    Complex Cinv;
    Cinv.real = C.real/(Cxmod(C)*Cxmod(C));
    Cinv.imag = C.imag/(Cxmod(C)*Cxmod(C)*-1);
    return Cinv;
}

Complex Cxsqrt(Complex C)
{
    Complex Crt;
    Crt.real = sqrt((Cxmod(C)+C.real)/2.0);
    Crt.imag = sqrt((Cxmod(C)-C.real)/2.0)*(C.imag/C.real)*(C.imag/abs(C.imag));
    return Crt;
}

double Cxarg(Complex C)
{
    double arg;
    arg = atan((C.imag/C.real));
    return arg;
}

double Cxmod(Complex C)
{
    double mod;
    mod = sqrt((C.real*C.real) + (C.imag*C.imag));
    return mod;
}

