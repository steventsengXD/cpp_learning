#include <iostream>  //include standard lib for I/O, eg, math lib is <math.h>
#include <math.h>
using namespace std; // Lets the program access declarations in namespace std

double f(double x)
{
  return 1.0/x+log(x+1)-5.0;
}

double bisection(double (*f)(double), double xl, double xr, double eps)
{
  double fl=f(xl),fr=f(xr);
  if (fl*fr > 0.0)
  {
    cerr<<"fl*fr>0.0 in bisection\n";
    exit(-1);
  }
  while (fabs(xr-xl)/2.0>eps)
  {
    double xc=(xr+xl)/2.0,fc=f(xc);
    if (fl*fc<=0.0)
    {
      xr=xc;
      fr=fc;
    }
    else
    {
      xl=xc;
      fl=fc;
    }
  }
  return (xr+xl)/2.0;
}

main() //A complete prgram in cpp must have a fct called main
{
  double xl=0.1,xr=1.0,zero;
  //zero=bisection(f,xl,xr,1.0e-6);
  cout<<bisection(f,xl,xr,1.0e-6);
}
