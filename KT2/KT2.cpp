#include <iostream>
#include <vector>

#include "CheckValue.h"
#include "Input.h"
#include "SportsCar.h"
#include "Truck.h"
#include "Output.h"

enum class Options
{
	Show = 1,
	Add,
	FileOutput,
	Clear,
	Exit
};

enum class Type
{
	Console = 1,
	File
};




int main()
{
	std::cout << "var 1 kr 2 " << std::endl;

	std::vector<Vehicle*> vehicles;

	while (true)
	{
		std::cout << "1 - Show vehicles\n2 - Add vehicle\n3 - File output\n4 - Clear list\n5 - Exit" << std::endl;

		Options choice = static_cast<Options>(CheckMenuItem(5));

		Type choiceT;

		switch (choice)
		{
		case Options::Show:
			if (vehicles.size() == 0)
			{
				std::cout << "First enter the vehicles" << std::endl;
				continue;
			}
			for (int i = 0; i < vehicles.size(); i++)
				std::cout << vehicles[i]->GetData();
			break;
		case Options::Add:
			std::cout << "1 - Console input\n2 - File input" << std::endl;
			choiceT = static_cast<Type>(CheckMenuItem(2));
			switch (choiceT)
			{
			case Type::Console:
				AddVehicleConsoleInput(vehicles);
				InitialFileOutput(vehicles);
				break;
			case Type::File:
				AddVehicleFileInput(vehicles);
				break;
			}
			break;
		case Options::FileOutput:
			if (vehicles.size() == 0)
			{
				std::cout << "First enter the vehicles" << std::endl;
				continue;
			}
			FileOutput(vehicles);
			break;
		case Options::Clear:
			vehicles.clear();
			break;
		case Options::Exit:
			return 0;
		}
	}
}
