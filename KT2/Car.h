#pragma once
#include <iostream>

#include "Vehicle.h"
class Car :
    public Vehicle
{
protected:
    std::string model;

public:

    Car(double _weight, double _enginePower, double _speed, const std::string& _model)
        : Vehicle(_weight, _enginePower, _speed), model(_model) {}

    virtual ~Car() {}

    virtual  std::string GetData()  const  override;
    virtual std::string  GetModel() const;
    virtual void SetModel(std::string value);
};

