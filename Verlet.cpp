#include "Vec3D.h"
#include <vector>
#include <fstream>
#include <cmath>

int main() {
	//initialise variables
	Vec3D gravity = {0,0,-9.8}; //gravitational acceleration
	double m = 0.5; //particle mass
	double nu = 0.1; //air drag coefficient
	double dt = 0.01; //time step
	double tMax = 1; //final time
	Vec3D r = {0,0,0};  //initial position
	Vec3D v = {4.9,0,4.9};  //initial velocity
	Vec3D f = gravity * m - v * nu;
	std::ofstream file("data"); //output file
	file << "time\tposition\tvelocity\n"; //write output file header
			
	//time loop
	for (double t=0; t<=tMax; t+=dt) {
		//integrate using Velocity-Verlet
		v += f*(0.5*dt/m);
		f = gravity * m - v * nu;
		r += v*dt;
		v += f*(0.5*dt/m);
		//write output
		file << t << "\t" << r << "\t" << v << "\n";
		std::cout << t << "\t" << r << "\t" << v << "\n";
	} 

	return 0;
}
