#include "Input.h"

#include <iostream>
#include <ostream>

#include "Car.h"
#include "CarFactory.h"
#include "CheckValue.h"
#include "SportsCar.h"
#include "Truck.h"


void AddVehicleConsoleInput(std::vector<Vehicle*>& vehicles)
{
	CarFactory* factory = new CarFactory();
	double _weight = 0;
	double _enginePower = 0;
	double _speed = 0;
	std::string _model = "";
	double _accelerationTo1000 = 0;
	double _capacity = 0;

	std::cout << "1 - Sports Car\n2 - Truck" << std::endl;

	auto type = static_cast<CarType>(CheckMenuItem(2));


	switch (type)
	{
	case CarType::SporsCar:
		std::cout << "Enter weight.";
		_weight = CheckDoubleValue();
		std::cout << "Enter engine power.";
		_enginePower = CheckDoubleValue();
		std::cout << "Enter speed.";
		_speed = CheckDoubleValue();
		std::cout << "Enter model.";
		_model = CheckStringValue();
		std::cout << "Enter acceleration to 100 km.";
		_accelerationTo1000 = CheckDoubleValue();

		vehicles.push_back(factory->CreateSportCar(_weight, _enginePower, _speed, _model, _accelerationTo1000));
		break;

	case CarType::Truck:
		std::cout << "Enter weight.";
		_weight = CheckDoubleValue();
		std::cout << "Enter engine power.";
		_enginePower = CheckDoubleValue();
		std::cout << "Enter speed.";
		_speed = CheckDoubleValue();
		std::cout << "Enter model.";
		_model = CheckStringValue();
		
		
		std::cout << "Enter capacity.";
		_capacity = CheckDoubleValue();

		vehicles.push_back(factory->CreateTruck(_weight, _enginePower, _speed, _model, _capacity));
		break;
	}
}

void AddVehicleFileInput(std::vector<Vehicle*>& vehicles)
{
	CarFactory* factory = new CarFactory();
	std::string fileName = "";
	std::ifstream file;

	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	while (true)
	{
		std::cout << "Enter file name. " << std::endl << "ENTER : ";
		std::cin >> fileName;
		try
		{
			file.open(fileName);
			std::cout << "Sucefull file open " << std::endl;
		}
		catch (const std::exception&)
		{
			std::cout << "Incorrect file name or way.Try again ." << std::endl;
			continue;
		}

		std::string sportsCarMark = "SportsCar";
		std::string truckMark = "Truck";
		int count;
		std::string typeMark;

		try
		{
			count = CheckLineInt(file);
			for (int i = 0; i < count; i++)
			{
				typeMark = CheckLineString(file);
				if (typeMark == sportsCarMark)
				{
					vehicles.push_back(factory->CreateSportCar(CheckLineDouble(file), CheckLineDouble(file),
					                                 CheckLineDouble(file), CheckLineString(file), CheckLineDouble(file)));
				}
				else if (typeMark == truckMark)
				{
					vehicles.push_back(factory->CreateTruck(CheckLineDouble(file), CheckLineDouble(file), CheckLineDouble(file),
					                             CheckLineString(file), CheckLineDouble(file)));
				}
			}
		}
		catch (std::invalid_argument iaex)
		{
			std::cout << "Incorect data " << std::endl;
			file.close();
			continue;
		}

		file.close();
		break;
	}
}
