#include <iostream>  //include standard lib for I/O, eg, math lib is <math.h>
#include <math.h>
using namespace std; // Lets the program access declarations in namespace std

void copy(const double x[3],double y[3])
{
  for(int i=0;i<3;i++)
    y[i]=x[i];
}

void add(const double x[3],double y[3])
{
  for(int i=0;i<3;i++)
    y[i]+=x[i];
}




int main()
{
  double aray1[2]={1,8},aray2[2];
  copy(aray1,aray2);
  cout<<aray2[0]<<","<<aray2[1]<<"\n";

  double aray3[3]={1,1,1},aray4[3]={2,3,4};
  add(aray3,aray4);
  cout<<aray4;

  return 0;
}
