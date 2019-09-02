#include "Vec3D.h"
#include <fstream>

struct cannonBall { //structs are classes with public member variables
	const Vec3D gravity = {0,0,-9.8}; //gravitational acceleration
	double m; //particle mass
	double nu; //air drag coefficient
	double dt; //time step
	double tMax; //final time
	Vec3D r;  //position
	Vec3D v;  //velocity
	
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
}