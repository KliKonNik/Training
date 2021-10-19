// vehicle.cpp

#pragma once

#include "vehicle.h"
// Class Vehicle definition--------------------------------

Vehicle::~Vehicle()
{
	if(GetTracking())
		cout << "\n\tDestructor of Vehicle!" << endl;
}

//---------------------------------------------------------

bool Vehicle::GetTracking()
{
	return m_Tracking;
}

// Class Automobile definition-----------------------------

Automobile::Automobile(g_en_EngineType et, float ep, int w) :
	m_EngineType(et),
	m_EnginePower(ep),
	m_Wheels(w)
{
	if (GetTracking())
		cout << "\n\tConstructor of Automobile!" << endl;
}

//---------------------------------------------------------

Automobile::~Automobile()
{
	if (GetTracking())
		cout << "\n\tDestructor of Automobile!" << endl;
}

//---------------------------------------------------------

void Automobile::SetEngineType(g_en_EngineType et)
{
	m_EngineType = et;		
}

//---------------------------------------------------------

void Automobile::SetEnginePower(float ep)
{
	m_EnginePower = ep;
}

//---------------------------------------------------------

void Automobile::SetWheels(int w)
{
	m_Wheels = w;
}

//---------------------------------------------------------

void Automobile::Set(g_en_EngineType et, float ep, int w)
{
	m_EngineType = et;
	m_EnginePower = ep;
	m_Wheels = w;
}

//---------------------------------------------------------

g_en_EngineType Automobile::GetEngineType() const
{
	return m_EngineType;
}

//---------------------------------------------------------

float Automobile::GetEnginePower() const
{
	return m_EnginePower;
}

//---------------------------------------------------------

int Automobile::GetWheels() const
{
	return m_Wheels;
}

//---------------------------------------------------------

void Automobile::Display() const
{
	cout << "Automobile:\nEngine type: ";
	switch (m_EngineType)
	{
	case g_en_EngineType::DIESEL: cout << "diesel"; break;
	case g_en_EngineType::GAS: cout << "diesel"; break;
	case g_en_EngineType::PETROL: cout << "diesel"; break;
	default:
		cout << "no data";
	}
	cout << "\nEngine power: " << m_EnginePower << "\nWheels: " << m_Wheels;
}

// Class Plane definition----------------------------------

Plane::Plane(g_en_EngineType et, float tv, int w) :
	m_EngineType(et),
	m_TankVolume(tv),
	m_Wings(w)
{
	if (GetTracking())
		cout << "\n\tConstructor of Plane!" << endl;
}

//---------------------------------------------------------

Plane::~Plane()
{
	if (GetTracking())
		cout << "\n\tDestructor of Plane!" << endl;
}

//---------------------------------------------------------

void Plane::SetEngineType(g_en_EngineType et)
{
	m_EngineType = et;
}

//---------------------------------------------------------

void Plane::SetTankVolume(float tv)
{
	m_TankVolume = tv;
}

//---------------------------------------------------------

void Plane::SetWings(int w)
{
	m_Wings = w;
}

//---------------------------------------------------------
void Plane::Set(g_en_EngineType et, float tv, int w)
{
	m_EngineType = et;
	m_TankVolume = tv;
	m_Wings = w;
}

//---------------------------------------------------------

g_en_EngineType Plane::GetEngineType() const
{
	return m_EngineType;
}

//---------------------------------------------------------

float Plane::GetTankVolume() const
{
	return m_TankVolume;
}

//---------------------------------------------------------

int Plane::GetWings() const
{
	return m_Wings;
}

//---------------------------------------------------------

void Plane::Display() const
{
	cout << "Plane:\nEngine type: ";
	switch (m_EngineType)
	{
	case g_en_EngineType::DIESEL: cout << "diesel"; break;
	case g_en_EngineType::KEROSENE: cout << "kerosene"; break;
	case g_en_EngineType::REACTIVE: cout << "reactive"; break;
	default:
		cout << "no data";
	}
	cout << "\nTank Volume: " << m_TankVolume << "\nWings: " << m_Wings;
}

// Class Car definition------------------------------------

Car::Car(g_en_EngineType et, float ep, int w) :
	Automobile(et, ep, w)
{
	if (GetTracking())
		cout << "\n\tConstructor of Car!" << endl;
}

//---------------------------------------------------------

Car::~Car()
{
	if (GetTracking())
		cout << "\n\tDestructor of Car!" << endl;
}

//---------------------------------------------------------

string Car::WhoAmI() const
{
	return "car";
}

//---------------------------------------------------------

void Car::Display() const
{
	cout << "\nDisplay from Car: " << endl;
	Automobile::Display();
}

// Class Truck definition----------------------------------

Truck::Truck(g_en_EngineType et, float ep, int w) :
	Automobile(et, ep, w)
{
	if (GetTracking())
		cout << "\n\tConstructor of Truck!" << endl;
}

//---------------------------------------------------------

Truck::~Truck()
{
	if (GetTracking())
		cout << "\n\tDestructor of Truck!" << endl;
}

//---------------------------------------------------------

string Truck::WhoAmI() const
{
	return "truck";
}

//---------------------------------------------------------

void Truck::Display() const
{
	cout << "\nDisplay from Truck: " << endl;
	Automobile::Display();
}

// Class Passenger definition------------------------------

Passenger::Passenger(g_en_EngineType et, float tv, int w):
	Plane(et, tv, w)
{
	if (GetTracking())
		cout << "\n\tConstructor of Passenger!" << endl;
}

//---------------------------------------------------------

Passenger::~Passenger()
{
	if (GetTracking())
		cout << "\n\tDestructor of Passenger!" << endl;
}

//---------------------------------------------------------

string Passenger::WhoAmI() const
{
	return "passenger";
}

//---------------------------------------------------------

void Passenger::Display() const
{
	cout << "\nDisplay from Passenger: " << endl;
	Plane::Display();
}

// Class Military definition-------------------------------

Military::Military(g_en_EngineType et, float tv, int w):
	Plane(et, tv, w)
{
	if (GetTracking())
		cout << "\n\tConstructor of Military!" << endl;
}

//---------------------------------------------------------

Military::~Military()
{
	if (GetTracking())
		cout << "\n\tDestructor of Military!" << endl;
}

//---------------------------------------------------------

string Military::WhoAmI() const
{
	return "military";
}

//---------------------------------------------------------

void Military::Display() const
{
	cout << "\nDisplay from Military: " << endl;
	Plane::Display();
}
