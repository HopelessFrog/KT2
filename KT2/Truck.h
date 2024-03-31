#pragma once
#include "Car.h"
class Truck :
    public Car
{
protected:
    double capacity;


public:
    Truck(double _weight, double _enginePower, double _speed, const std::string& _model, double _capacity)
        : Car(_weight, _enginePower, _speed, _model), capacity(_capacity) {}

    virtual ~Truck() {}

    double GetCapacity() const;
    void SetCapacity(double value);

    virtual  std::string GetData() const override;
};

