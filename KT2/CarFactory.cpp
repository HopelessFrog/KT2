#include "CarFactory.h"

SportsCar* CarFactory::CreateSportCar(double _weight, double _enginePower, double _speed, const std::string& _model,
                                      double _accelerationTo100)
{
	return new SportsCar(_weight, _enginePower, _speed, _model, _accelerationTo100);
}

Truck* CarFactory::CreateTruck(double _weight, double _enginePower, double _speed, const std::string& _model,
                               double _capacity)
{
   return 	new Truck(_weight, _enginePower, _speed, _model, _capacity);
}
