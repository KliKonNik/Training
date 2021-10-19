// vehicle.h

#pragma once

#include <iostream>
#include <string>

//Using----------------------------------------------------

using std::cout;
using std::endl;
using std::string;

// Enums---------------------------------------------------

enum class g_en_EngineType { UNDEFINE, REACTIVE, KEROSENE, DIESEL, PETROL, GAS, MUSCLE };

// Class Vehicle description-------------------------------

class Vehicle
{
	static bool m_Tracking;
public:
	Vehicle();
	virtual ~Vehicle();
	virtual string WhoAmI() const = 0;
	virtual void Display() const = 0;
	static bool GetTracking();
};

// Class Automobile description----------------------------

class Automobile : public Vehicle
{
	g_en_EngineType m_EngineType;
	float m_EnginePower;
	int m_Wheels;
public:
	Automobile(g_en_EngineType = g_en_EngineType::UNDEFINE, float = 0.0, int = 0);
	virtual ~Automobile() override;

	void SetEngineType(g_en_EngineType);
	void SetEnginePower(float);
	void SetWheels(int);
	void Set(g_en_EngineType, float, int);

	g_en_EngineType GetEngineType() const;
	float GetEnginePower() const;
	int GetWheels() const;

	virtual string WhoAmI() const override = 0;
	virtual void Display() const override;
};

// Class Plane description---------------------------------

class Plane : public Vehicle
{
	g_en_EngineType m_EngineType;
	float m_TankVolume;
	int m_Wings;
public:
	Plane(g_en_EngineType = g_en_EngineType::UNDEFINE, float = 0.0, int = 0);
	virtual ~Plane() override;
	void SetEngineType(g_en_EngineType);
	void SetTankVolume(float);
	void SetWings(int);
	void Set(g_en_EngineType, float, int);

	g_en_EngineType GetEngineType() const;
	float GetTankVolume() const;
	int GetWings() const;

	virtual string WhoAmI() const override = 0;
	virtual void Display() const override;
};

// Class Car description-----------------------------------

class Car : public Automobile
{
public:
	Car(g_en_EngineType = g_en_EngineType::UNDEFINE, float = 0.0, int = 0);
	~Car() override;

	virtual string WhoAmI() const override;
	virtual void Display() const override;
};

// Class Truck description---------------------------------

class Truck : public Automobile
{
public:
	Truck(g_en_EngineType = g_en_EngineType::UNDEFINE, float = 0.0, int = 0);
	~Truck() override;

	virtual string WhoAmI() const override;
	virtual void Display() const override;
};

// Class Passenger description-----------------------------

class Passenger : public Plane
{
public:
	Passenger(g_en_EngineType = g_en_EngineType::UNDEFINE, float = 0.0, int = 0);
	~Passenger() override;

	virtual string WhoAmI() const override;
	virtual void Display() const override;
};

// Class Military description------------------------------

class Military : public Plane
{
public:
	Military(g_en_EngineType = g_en_EngineType::UNDEFINE, float = 0.0, int = 0);
	~Military() override;

	virtual string WhoAmI() const override;
	virtual void Display() const override;
};

//---------------------------------------------------------