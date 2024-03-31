#pragma once
#include <memory>
#include <vector>

class Vehicle;

enum class CarType
{
	SporsCar = 1,
	Truck
};


void AddVehicleConsoleInput(std::vector<Vehicle*>& vehicles);

void AddVehicleFileInput(std::vector<Vehicle*>& vehicles);