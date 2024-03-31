#include "Vehicle.h"

double Vehicle::GetWeight() const { return weight; }
double Vehicle::GetEnginePower() const { return enginePower; }
double Vehicle::GetSpeed() const { return speed; }

void Vehicle::SetWeight(double value)
{
	if (weight != value)
		weight = value;
}
void Vehicle::SetEnginePower(double value)
{
	if (enginePower != value)
		enginePower = value;
}
void Vehicle::SetSpeed(double value)
{
	if (speed != value)
		speed = value;
}