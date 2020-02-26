#include <string>
#include "CCar.h"
#include "CCarFactory.h"

void main()
{
	std::string CarSig = "BENZ_SIG";
	CCar *pCar = dynamic_cast<CCar*>(CCarFactoryData::getOrCreateInstance()->createCar(CarSig));
	pCar->driveV();
}