#include "Vec3D.h"
#include <vector>
#include <fstream>
#include <cmath>

// declaration of particle
struct Particle { //properties of a spherical particle
	double a; //radius
	double m; //mass
	Vec3D r;  //position
	Vec3D v;  //velocity
	Vec3D f;  //force
};

// declaration of wall
struct Wall {
	Vec3D n; //normal pointing into the wall
	Vec3D p; //point on the wall
};

//declare DPM solver
struct DPM {
	//global parameters
	double dt; //time step
	double tMax; //final time
	double k; //stiffness 
	double gam; //dissipation coefficient
	unsigned int saveCount = 10; //number of timestep between saves
	std::vector<Particle> particles; //vector of particles
	std::vector<Wall> walls; //vector of walls
	Vec3D gravity;
	
	//solve contains the time stepping algorithm and the output routines 
	void solve () {
		//initialise time, and counter/ofstream for data output
		double t=0;
		unsigned int counter = 0;
		std::ofstream file("data");
		while (t<tMax) {
			//set gravitational body force for all particles
			for (Particle& p : particles) {
				p.f = gravity * p.m;
			}
			//loop over all wall-particle contacts to evaluate forces
			for (Particle& p : particles)
			for (Wall& w : walls) {
				double distance = (w.p-p.r)*w.n;
				double overlap = p.a-distance;
				if (overlap>=0) {
					double vreln = p.v*w.n;
					double normalForce = k*overlap+gam*vreln; 
					p.f += w.n*(-normalForce);
				}
			}
			//loop over all contacts p=1..N, q=p+1..N to evaluate forces
			for (auto p = particles.begin();  p!=particles.end(); ++p)
			for (auto q = p+1;  q!=particles.end(); ++q) {
				// double distance = sqrt((p->r-q->r).lengthSquared());
				// double overlap = p->a+q->a-distance;
				// if (overlap>0) {
				double distanceSquared = Vec3D::lengthSquared(p->r-q->r);
				if ((p->a+q->a)*(p->a+q->a)>distanceSquared) {
					double distance = sqrt(distanceSquared); 
					double overlap = p->a+q->a-distance;
					Vec3D normal = (p->r-q->r)/distance;
					double vreln = (p->v-q->v)*normal;
					double normalForce = k*overlap+gam*vreln; 
					p->f += normal*normalForce;
					q->f += normal*(-normalForce);
				}		
			}
			//integrate position and velocity with the Euler method
			for (Particle& p : particles) {
				p.r += p.v*dt;
				p.v += p.f*(dt/p.m);
			}
			t += dt;
			//write output file in the .data format every 10th time step
			if (++counter>=saveCount) {
				//reset the counter, write time to terminal
				counter = 0;
				std::cout << "t=" << t << std::endl; 
				//write global parameters (time, number of particles, domain size)
				file << particles.size() << " " << t << " 0 0 0 1 1 1\n"; 
				for (Particle& p : particles) {
					//write particle data (position, velocity, radius)
					file << p.r << " " << p.v << " " << p.a << " 0 0 0 0 0 0 0\n";
				}
			}
		} //end time loop
		file.close();
	} //end solve
};
