#include "Car.h"


std::string Car::GetData() const
{
	return "\nModel: " + model + "\nWeight: " + std::to_string(weight) + " tons " +
		+"\nEngine Power: " + std::to_string(enginePower) + " HP " +
		+"\nSpeed: " + std::to_string(speed) + " km/h ";
}

std::string Car::GetModel() const
{
	return model;
}


void Car::SetModel(std::string value)
{
	if (value != model)
		value = model;
}

