#include "DPM.h"

int main () {
	//define an instance of the DPM solver
	DPM coll2p;
	//set global parameters
	coll2p.k = 10000;
	coll2p.gam = 2;
	coll2p.dt = 1e-4;
	coll2p.tMax = 0.5;
	//initialize two particles with radius, mass, position, velocity
	coll2p.particles.push_back({0.05,0.5,{0.3,0.5,0.5},{ 1,0,0}});
	coll2p.particles.push_back({0.05,0.5,{0.7,0.5,0.5},{-1,0,0}});
	//start the dpm solver
	coll2p.solve();
	return 0;
}
