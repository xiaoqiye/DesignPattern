#pragma once
#include "CCar.h"
#include "CCarFactory.h"
#include <iostream>
#include <map>

class CCarFactoryData
{
public:
	~CCarFactoryData() {}

	static CCarFactoryData* getOrCreateInstance()
	{
		static CCarFactoryData* pCarFactoryData = NULL;

		if (!pCarFactoryData)
		{
			pCarFactoryData = new CCarFactoryData();
		}

		return pCarFactoryData;
	}

	CCar* createCar(const std::string& vSig)
	{
		if (!__isCarFactoryRegistered(vSig)) return NULL;
		CCar* pCar = m_CarFactoryMap[vSig]->_createCarV();
		_ASSERT(pCar);
		pCar->setCarCreationSig(vSig);
		return pCar;
	}

	void registerCarFactory(CCarFactory<CCar>* vCarFactory, const std::string& vSig)
	{
		m_CarFactoryMap[vSig] = vCarFactory;
	}
private:
	std::map<std::string, CCarFactory<CCar>*> m_CarFactoryMap;

	bool __isCarFactoryRegistered(const std::string& vSig) const
	{
		return m_CarFactoryMap.find(vSig)!=m_CarFactoryMap.end();
	}

protected:
	CCarFactoryData() {}
};