typedef struct stcomplex
{
    double real;
    double imag;
}Complex;

Complex Cxcreate(double , double);
Complex Cxaddition(Complex , Complex);
Complex Cxmultiplication(Complex, Complex);
Complex Cxdivision(const Complex , const Complex);
Complex Cxconjugate(Complex);
Complex Cxsqrt(Complex);
Complex Cxinverse(Complex);
double Cxarg(Complex);
double Cxmod(const Complex);
