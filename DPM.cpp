#include "DPM.h"
#include <vector>
#include <fstream>
#include <cmath>

int main() {

    //declare an instance of the DPM solver
    DPM myProb;

    //set global params
    myProb.tMax=1.0;

    myProb.dt=1e-4;
    myProb.gam=20;
    myProb.k=1e4;
    myProb.gravity={0,0,-9.8};

    //initialize two particles with radius, mass, position, velocity
    //push_back adds the element at the end of the vector after the last element
    myProb.particles.push_back({0.05,0.5,{0.5,0.5,0.5},{-0.5,-0.5,0}});
    myProb.particles.push_back({0.05,0.5,{0,0,0},{0.5,0.5,0}});



    //start the DPM solver
    myProb.solve();

	return 0;
}
