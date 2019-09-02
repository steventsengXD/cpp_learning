/*comments must be enclosed this way*/
//or comment out this way


#include <iostream>  //include standard lib for I/O, eg, math lib is <math.h>
#include <math.h>
using namespace std; // Lets the program access declarations in namespace std

//Declaring a function, cant put in main(){}
double f(double x) {
  return (x*x);
}

int main() //A complete program in cpp must have a fct called main
{
  string name;
  cout<<"What is your name? \n";
  cin>>name;
  cout<<"Hello "<<name<<"! \n";

  int n, m; //declaring variables that are integers, can double, float
  double sum=0.0; //declaring an initializing a vardiable but dont have to init
  cout << "Can you give me two integers: \n";
  cin>>n>>m;
  sum=n+m;
  float d;
  d=n*m;
  cout<<"The product of the integers is: " << d <<". \n";
  cout<<"The sum of the integers is: "<<sum<<". \n";

  if(m>n){
    cout<<"And btw, you're a loser. \n";
  }
  else{
    cout<<"And btw, you're stupid. \n";
  }

  for (int i=0;i<=m;i++) cout<<i<<"\n";

  cout<<"The first integer squared is: "<<f(n)<<".\n";

  if(f(n)>15){
    cout<<"And you're still a loser!\n";
  }

  n-=1; //This is the same as n=n-1 and better
  n++; //This first uses the value n and then increments it by 1
  ++n; //Increments the value of n by 1 then takes the new value

  char x;
  double y;

  cout<<"What option do you want, A or B? \n";
  cin>>x;

  switch(x){
    case 'A':
    case 'a':
    y=1.55;
    break;

    case 'B':
    case 'b':
    y=1.75;
    break;

    default:
    cout<<name<<" you're crazy! \n";
  }


  /*return 0; //exit status of program  */
}
