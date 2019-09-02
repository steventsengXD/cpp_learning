//Pointer is a datatype derived from a base type where the variable contains
//the memory position of another variable using * operator

//Memory position, ie, the address of a standard variable is obtained by
//the address operator &

//A pointer stores the location of something
//THus * says this varaible is a pointer and store the location of &___

//* --> pointer
//& --> give address of

//The use of pointers is mostly for pass by reference
//Eg, if you give a function a pointer, you can pass the address in to the
//function instead. A lot of functions need the actual address instead of
//the value

#include <iostream>
#include <math.h>
using namespace std;

//Function that adds 5 to an integer by use of pointers or pass by reference
void addfive(int *num)
{
  *num+=5;
}

//Function that does the same thing but without
int add5(int num)
{
  return num+5;
}



int main()
{
  int integer=5;
  int *p=&integer;
  int m1,m2,m3,m4;
  m1=integer+3;
  m2=*p+3;
  cout<<"m1 equals "<<m1<<"\n";
  cout<<"m2 equals "<<m2<<"\n";

  //Can assign value of a pointer, eg the address, to another pointer
  int *q=p;
  m3=*q+*p;
  cout<<"m3 equals "<<m3<<"\n";

  //A reference is a special form of a pointer which can only be initialized
  //with the address of an existing varaible
  int & r=integer;
  m4=r+3; //This gives m=n+3
  cout<<"m4 equals "<<m4<<"\n";

  r=m4; //r still points to integer and now integer==m4;
  cout<<"the value of our integer is now "<<integer<<"\n";

  //&integer provides the location in memory where the value is stored
  cout<<"The value of integer is stored at: "<<&integer<<"\n";

  int newnum=7,m5;
  addfive(&newnum);
  cout<<"The new number is: "<<newnum<<"\n";
  //The number is still the old number if we dont pass in the address

  // m5=add5(newnum);
  // cout<<m5;

  return 0;
}
