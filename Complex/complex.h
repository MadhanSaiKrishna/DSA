typedef struct stcomplex
{
    double real;
    double imag;
}Complex;

Complex Cxcreate(double , double);
Complex Cxaddition(Complex , Complex);
Complex Cxmultiplication(Complex, Complex);
Complex Cxdivision(Complex , Complex);
Complex Cxconjugate(Complex);
Complex Cxsqrt(Complex);
double Cxarg(Complex);
double Cxmod(const Complex);
