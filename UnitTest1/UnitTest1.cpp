#include <vector>

#include "CppUnitTest.h"
#include "../KT2/CarFactory.h"
#include "../KT2/CarFactory.cpp"
#include "../KT2/SportsCar.h"
#include "../KT2/SportsCar.cpp"
#include "../KT2/Truck.h"
#include "../KT2/Truck.cpp"
#include "../KT2/Vehicle.h"
#include "../KT2/Vehicle.cpp"
#include "../KT2/Car.h"
#include "../KT2/Car.cpp"






class Vehicle;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(VehicleTest)
	{
	private:
		CarFactory* factory = new CarFactory();

	public:
		TEST_METHOD(TestSportsCar)
		{
			SportsCar* sportsCar  = factory->CreateSportCar(1400, 400, 280, "Ferrari", 123);
			Assert::AreEqual(1400.0, sportsCar->GetWeight());
			Assert::AreEqual(400.0, sportsCar->GetEnginePower());
			Assert::AreEqual(280.0, sportsCar->GetSpeed());
			Assert::AreEqual(std::string("Ferrari"), sportsCar->GetModel());
			Assert::AreEqual(123.0, sportsCar->GetAccelerationTo100());
			
		}


		TEST_METHOD(TestTruck)
		{
			Truck* truck = factory->CreateTruck(5000, 300, 120,"Kamaz", 10000);
			Assert::AreEqual(5000.0, truck->GetWeight());
			Assert::AreEqual(300.0, truck->GetEnginePower());
			Assert::AreEqual(120.0, truck->GetSpeed());
			Assert::AreEqual(std::string("Kamaz"), truck->GetModel());
			Assert::AreEqual(10000.0, truck->GetCapacity());
		}
	};
}
