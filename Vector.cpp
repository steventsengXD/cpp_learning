#include "Vec3D.h"
using namespace std;

int main() {
	Vec3D v = {1,0,1}; //defines the vector v.
	Vec3D w = v * 3; //multiplies v by 3 and assigns it to w.	
	std::cout << "v * 3 = " << w << std::endl; //outputs w to the terminal.

//	std::cout << "Enter the three coordinates of vector v:" << std::endl;
//	std::cin >> v; //input v from the terminal, for example "4.3 -0.1 0".
//
//	v = v/Vec3D::length(v); //normalises the vector w.
//	std::cout << "Normalizing this vector yields " << v << std::endl; //outputs w.

    Vec3D v1={2,3,4};
    double w1 = v1 * v;


    cout<<w1<<"\n";

    double len = Vec3D::lengthSquared(v);
    cout<<len<<"\n";

    w += v1;
    cout<<w<<"\n";

    Vec3D z=w+v;
    cout<<z<<"\n";
}