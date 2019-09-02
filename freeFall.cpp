#include "DPM.h"

int main () {
	//define an instance of the DPM solver
	DPM freeFall;
	//set global parameters
	freeFall.k = 10000;
	freeFall.gam = 20;
	freeFall.dt = 1e-4;
	freeFall.tMax = 2.0;
	freeFall.gravity = {0,0,-9.8};
	//initialize particle with radius, mass, position, velocity
	freeFall.particles.push_back({0.05,0.5,{0.5,0.5,0.5},{0,0,0}});
	//initialize wall with normal and position
	freeFall.walls.push_back({{0,0,-1},{0,0,0}});
	//start the dpm solver
	freeFall.solve();
	return 0;
}
