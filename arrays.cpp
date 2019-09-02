#include <iostream>  //include standard lib for I/O, eg, math lib is <math.h>
#include <math.h>
using namespace std; // Lets the program access declarations in namespace std

/*double f(double x) {
  return (x*x);
}*/

//Horners algorithm for polynomial function by rewriting in nested form
//a is the array for the coefficients
//n is the order of the poly + 1

double horner(double* a, int n, double x){
  double u=a[n];
  for (int i=n-1; i>=0;i--) u=u*x+a[i];
  return u;
}


int main() //A complete program in cpp must have a fct called main
{

  // Defines and initiates an array
  int v[5]={1,2,3,4,5};

  // cout<<"Give a five element array: \n";

  //This gives the number of bytes allocated to the array
  cout<<sizeof(v)<<"\n";

  //This gives the size of one element in the array
  cout<<sizeof(*v)<<"\n";

  int len;
  len=sizeof(v)/sizeof(*v);

  //Dividing the two will give you the length of the array
  cout<<len<<"\n";

  double a[3] = {1,4,4};
  int x=1;
  cout<<horner(a,3,x)<<"\n";

  cout<<pow(9,2)<<"\n";

  //Initializing a 2x2 array
  int array22[2][2]={{1,2},{3,4}};
  cout<<array22;

  return 0;


}
