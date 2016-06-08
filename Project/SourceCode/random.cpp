#include "random.h"

Random::Random()
{
	normald = std::normal_distribution<float>(0,1);
	generator = std::mt19937(rd());
}

float Random::get_normald(float mean, float sd)
{
	normald = std::normal_distribution<float>(mean,sd);
	return normald(generator);
};

int Random::get_int(int min, int max)
{
	uniformd_int = std::uniform_int_distribution<int>(min,max);
	return uniformd_int(generator);
};

float Random::get_float(float min, float max)
{
	uniformd_float = std::uniform_real_distribution<float>(min,max);
	return uniformd_float(generator);
};

float Random::get_weibull(float first, float second)
{
	weibulld = std::weibull_distribution<float>(first,second);
	return weibulld(generator);
};