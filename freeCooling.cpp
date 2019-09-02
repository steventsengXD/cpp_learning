#include "DPM.h"

int main () {
	//define an instance of the DPM solver
	DPM freeCooling;
	//set global parameters
	freeCooling.k = 10000;
	freeCooling.gam = 0;
	freeCooling.dt = 1e-4;
	freeCooling.tMax = 1.0;
	freeCooling.gravity = {0,0,0};
	freeCooling.saveCount = 50;
	//initialize particle with radius, mass, position, velocity
	unsigned int Np = 31;
	double h = 0.6/sqrt(Np);
	for (double z=0.2+0.5*h; z<0.8; z+=h) 
	for (double x=0.2+0.5*h; x<0.8; x+=h) {
		freeCooling.particles.push_back({0.05,0.5,{x,0.5,z},{1,0,1}});
		if (freeCooling.particles.size()==Np) break;
	}
	//initialize wall with normal and position
	freeCooling.walls.push_back({{0,0,-1},{0,0,0}});
	freeCooling.walls.push_back({{0,0, 1},{0,0,1}});
	freeCooling.walls.push_back({{-1,0,0},{0,0,0}});
	freeCooling.walls.push_back({{ 1,0,0},{1,0,0}});
	//start the dpm solver
	freeCooling.solve();
	return 0;
}
