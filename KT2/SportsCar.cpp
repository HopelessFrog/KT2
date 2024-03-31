#include "SportsCar.h"

std::string SportsCar::GetData() const
{
	return  Car::GetData() + "\nAcceleration to 100 km " + std::to_string(accelerationTo100) + " sec " + "\nType: Sports Car\n";
};

double SportsCar::GetAccelerationTo100() const
{
	return  accelerationTo100;
}

void SportsCar::SetAccelerationTo100(double value)
{
	if (value != accelerationTo100)
		accelerationTo100 = value;
}
