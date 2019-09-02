#include <iostream>
#include <math.h>
using namespace std;

inline double
square(double x)
{
  return x*x;
}

double f(const double x){return x*x;}
double g(const double x){return x*x*x;}

//Function pointers --> variable holding the address of a function can be
//used as a function by itself

double simpson4(const double a, const double b, double (*f)(const double))
{
  return (b-a)/6.0*(f(a)+4*f((a+b)/2.0)+f(b));
}


int main()
{
  // double pi=3.141592653589793,area;
  // int r=2,temp;
  // area=pi*r*r;
  // cout<<area<<"\n";
  // cout<<int(pi)<<endl;
  // cout<<square(5);

  cout<<simpson4(-1,2,f)<<endl;
  cout<<simpson4(-1,2,g)<<endl;

  return 0;
}
