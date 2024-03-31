#include "Truck.h"

std::string Truck::GetData() const
{
	return   Car::GetData() + "\nCapacity " + std::to_string(capacity) + " liters " + "\nType: Truck\n";
	
}


double Truck::GetCapacity() const
{
	return  capacity;
}

void Truck::SetCapacity(double value)
{
	if (value != capacity)
		capacity = value;
}

