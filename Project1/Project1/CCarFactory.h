#pragma once
#include "CCarFactoryData.h"
#include "CCar.h"

template <class TDerivedCar>
class CCarFactory
{
public:
	CCarFactory(const std::string& vSig)
	{
		CCarFactoryData::getOrCreateInstance->registerCarFactory(reinterpret_cast<CCarFactory<CCar>*>(this), vSig);
	}
	~CCarFactory() {}

	virtual CCar* _createCarV()
	{
		return new TDerivedCar;
	}
};