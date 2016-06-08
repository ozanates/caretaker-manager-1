#ifndef RANDOM_H

#define RANDOM_H

#include <random>

class Random
{
	std::random_device rd;
	std::mt19937 generator;
	std::normal_distribution<float> normald;
	std::uniform_int_distribution<int> uniformd_int;
	std::uniform_real_distribution<float> uniformd_float;
	std::weibull_distribution<float> weibulld; //use 3*d(3.0,2.0) for 2-10, use 3*d(3.0,1.0) for 0-5, use 3*d(3.0,0.5) for 0-3

public:
	Random();
	float get_normald(float mean, float sd);
	int get_int(int min, int max);
	float get_float(float min, float max);
	float get_weibull(float first, float second);
};

#endif