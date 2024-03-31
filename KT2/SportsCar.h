#pragma once
#include "Car.h"

class SportsCar :
	public Car
{
protected:
	double accelerationTo100;

public:
	SportsCar(double _weight, double _enginePower, double _speed, const std::string& _model, double _accelerationTo100)
		: Car(_weight, _enginePower, _speed, _model), accelerationTo100(_accelerationTo100)
	{
	}

	~SportsCar() override
	{
	}

	double GetAccelerationTo100() const;
	void SetAccelerationTo100(double value);

	std::string GetData() const override;
};
