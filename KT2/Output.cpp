#include "Output.h"

#include <iostream>

#include "CheckFile.h"
#include "SportsCar.h"
#include "Truck.h"


void ConsoleOutput(std::vector<Vehicle*>& vehicles)
{
	for (int i = 0; i < vehicles.size(); i++)
		std::cout << vehicles[i] ->GetData() << std::endl;
}


void FileOutput(std::vector<Vehicle*>& vehicles)
{
	std::ofstream fileRecorder = CheckFileOutput();

	for (int i = 0; i < vehicles.size(); i++)
	{
		fileRecorder << vehicles[i]->GetData();
	}

}

void InitialFileOutput(std::vector<Vehicle*>& vehicles)
{
	std::cout << "Save initial data ?\n1 - Yes\n2 - No" << std::endl;
	if (CheckMenuItem(2) != 1)
		return;
	std::ofstream fileRecorder = CheckFileOutput();

	std::string sportsCarMark = "SportsCar";
	std::string truckMark = "Truck";

	fileRecorder << vehicles.size() << std::endl;

	for (int i = 0; i < vehicles.size(); i++)
	{
		std::string name = typeid(*vehicles[i]).name();
		if (name == typeid(SportsCar).name())
		{
			fileRecorder << sportsCarMark << std::endl;;
			fileRecorder << (vehicles[i])->GetWeight() << std::endl;
			fileRecorder << (vehicles[i])->GetEnginePower() << std::endl;
			fileRecorder << (vehicles[i])->GetSpeed() << std::endl;
			fileRecorder << (reinterpret_cast<SportsCar*>(vehicles[i]))->GetModel() << std::endl;
			fileRecorder << (reinterpret_cast<SportsCar*>(vehicles[i]))->GetAccelerationTo100() << std::endl;
			

		}
		else if (name == typeid(Truck).name())
		{
			fileRecorder << truckMark << std::endl;
			fileRecorder << (vehicles[i])->GetWeight() << std::endl;
			fileRecorder << (vehicles[i])->GetEnginePower() << std::endl;
			fileRecorder << (vehicles[i])->GetSpeed() << std::endl;
			fileRecorder << (reinterpret_cast<Truck*>(vehicles[i]))->GetModel() << std::endl;
			fileRecorder << (reinterpret_cast<Truck*>(vehicles[i]))->GetCapacity() << std::endl;
		}
	

	}
	fileRecorder.close();
}