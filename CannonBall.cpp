#include "Vec3D.h"
#include <fstream>

struct cannonBall {
	const Vec3D gravity = {0,0,-9.8}; //gravitational acceleration
	double m; //particle mass
	double nu; //air drag coefficient
	double dt; //time step
	double tMax; //final time
	Vec3D r;  //position
	Vec3D v;  //velocity
	
	//member function with the integration routine 
	void solve() {
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
	}
};

int main() {
	//initialise variables
	cannonBall C;
	C.m = 0.5; //particle mass
	C.nu = 0.1; //air drag coefficient
	C.dt = 0.01; //time step
	C.tMax = 1; //final time
	C.r = {0,0,0};  //initial position
	C.v = {4.9,0,4.9};  //initial velocity
	//call the integration routine
	C.solve();
	return 0;
}
