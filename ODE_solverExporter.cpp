//
//  ODE_solverExporter.cpp
//  
//
//  Created by Dashiel Balnaves on 20/3/2026.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>
#include <sstream>

using state = std::vector<double>;

state f(double t, const state& s) { //pass in state vector and time t
	double x = s[0];
	double y = s[1];

	double beta = 1.0;
	double gamma = 0.2;

	return {
		y,
		-x + beta * x * x * x - gamma * y //return the adjusted state with the chosen parameters of DE
	};
}

state rk4_step(double t, const state& y, double h) {
	state k1 = f(t, y); //get state at t

	state y2 = { y[0] + 0.5*h*k1[0], y[1] + 0.5*h*k1[1] }; //state with an increment of initial solution
	state k2 = f(t + 0.5*h, y2); //actual state at time increment

	state y3 = { y[0] + 0.5*h*k2[0], y[1] + 0.5*h*k2[1] };
	state k3 = f(t + 0.5*h, y3); //another iteration of doing that

	state y4 = { y[0] + h*k3[0], y[1] + h*k3[1] };
	state k4 = f(t + h, y4); //final iteration

	return {
		y[0] + (h/6.0)*(k1[0] + 2*k2[0] + 2*k3[0] + k4[0]),
		y[1] + (h/6.0)*(k1[1] + 2*k2[1] + 2*k3[1] + k4[1]) //return approximate result of DE
	};
}

int main(int argc, char *argv[]) {
	//for testing use x0 = 0, y0 = 0.5, h = 0.05, N = 50
	std::string textfile = argv[1];
	std::stringstream stream;
	float var; //use 0 for no noise to solve system exactly
	double h; //increment
	double xinit, yinit; //initial conds
	int N; //number of increments
	stream << argv[2];
	stream >> var;
	h = std::stod(argv[3]);
	xinit = std::stod(argv[4]);
	yinit = std::stod(argv[5]);
	N = std::stoi(argv[6]); //using command line arguments to initialise
	std::ofstream file(textfile);
	std::default_random_engine gen;
	std::normal_distribution<double> noise(0.0, var);
	
	std::cout << "variance is " << var << std::endl;
	std::cout << "increment is " << h << std::endl;
	std::cout << "initial x is " << xinit << std::endl;
	std::cout << "initial y is " << yinit << std::endl;
	std::cout << "number of samples is " << N << std::endl;
	

	double t = 0.0;
	state y = {xinit, yinit};

	file << "t,x,y\n";

	for (int i = 0; i < N; i++) {
		file << t << "," << y[0] + noise(gen) << "," << y[1] + noise(gen) << "\n";
		y = rk4_step(t, y, h);
		t += h;
	}

	file.close();
}

