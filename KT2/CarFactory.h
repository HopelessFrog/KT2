#pragma once
#include <string>

#include "SportsCar.h"
#include "Truck.h"

class CarFactory
{
public:
	SportsCar* CreateSportCar(double _weight, double _enginePower, double _speed, const std::string& _model,
	                          double _accelerationTo100);
	Truck* CreateTruck(double _weight, double _enginePower, double _speed, const std::string& _model, double _capacity);

};

