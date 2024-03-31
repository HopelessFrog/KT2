
#pragma once
#include <string>

class Vehicle
{
protected:
    double weight;
    double enginePower;
    double speed;

public:
    Vehicle(double weight, double enginePower, double speed)
        : weight{ weight }, enginePower{ enginePower }, speed{ speed } {}

    virtual  std::string GetData() const = 0;

    virtual ~Vehicle() {}


    virtual double GetWeight() const;
    virtual double GetEnginePower() const;
    virtual double GetSpeed() const;
    virtual void SetWeight(double value);
    virtual void SetEnginePower(double value);
    virtual void SetSpeed(double value);
};


