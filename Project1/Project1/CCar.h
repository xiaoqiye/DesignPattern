#pragma once
#include <iostream>
#include <string>
#include "CCarFactory.h"

//²úÆ·
class CCar
{
public:
	CCar() {}
	~CCar() {}

	virtual void driveV() {}

	void setCarCreationSig(const std::string& vSig)
	{
		m_CarCreationSig = vSig;
	}
private:
	std::string m_CarCreationSig;
};

CCarFactory<CBenz> TheCreator1("BENZ_SIG");
class CBenz :public CCar
{
public:
	virtual void driveV() override
	{
		std::cout << "Driving Benz..." << std::endl;
	}
};

CCarFactory<CBMW> TheCreator2("BMW_SIG");
class CBMW :public CCar
{
public:
	virtual void driveV() override
	{
		std::cout << "Driving BMW..." << std::endl;
	}
};