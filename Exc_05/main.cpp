// main.cpp
// 1. Реализовать 3-уровневую иерархию классов.
// Вариант 4:
// Уровень 1				Уровень 2		Уровень 3		Методы
// Транспортное средство	Автомобиль		Грузовой		Средний расход топлива на 1 км
//											Легковой
//							Самолет			Пассажирский	Общая стоимость перелета
//											Военный
// 2. Базовый класс 1 уровня – абстрактный, содержащий чисто виртуальные функции. Классы 2 уровня – абстрактные, содержащие поля, конструкторы,
// методы и чисто виртуальные функции. Производные классы 3 уровня – конкретные классы, содержащие реализацию виртуальных методов.

#include "vehicle.h"
#include <vector>

//Using----------------------------------------------------

using std::vector;

//Consts---------------------------------------------------

constexpr int g_c_MaxSize = 16;
bool Vehicle::m_Tracking = (g_c_MaxSize <= 4)? true : false;

//---------------------------------------------------------

g_en_EngineType getEngineType(bool mod)
{
	int mode = ((mod) ? 2 : 0) + rand() % 3;
	switch (mode)
	{
	case 0:return g_en_EngineType::PETROL;
	case 1:return g_en_EngineType::GAS;
	case 2:return g_en_EngineType::DIESEL;
	case 3:return g_en_EngineType::KEROSENE;
	case 4:return g_en_EngineType::REACTIVE;
	}
	return g_en_EngineType::UNDEFINE;
};

int main()
{
	vector<Vehicle*> vVeh;
	
	srand(static_cast<unsigned>(time(0)));

	auto random = [](int n) {
		return (n + (rand() % n));
	};

	for (int i{ 0 }; i < g_c_MaxSize; i++)
	{		
		switch (rand() % 4)
		{
		case 0:
			vVeh.push_back(new Car(getEngineType(false), static_cast<float>(random(80)), 1 + random(2)));
			break;
		case 1:
			vVeh.push_back(new Truck(getEngineType(false), static_cast<float>(100 + random(100)), (4 + 2*random(2))));
			break;
		case 2:
			vVeh.push_back(new Passenger(getEngineType(true), static_cast<float>(5000 + random(1000)), random(2) - 1));
			break;
		case 3:
			vVeh.push_back(new Military(getEngineType(true), static_cast<float>(3500 + random(1000)), random(2) - 1));
			break;
		default:
			cout << "\n\n\tAttention! Something wrong with random!\n\n";
			exit(1);
		}
	}

	for (auto pObj : vVeh)
	{
		cout << endl;
		pObj->Display();
	}

	while (!vVeh.empty())
	{
		delete vVeh.back();
		vVeh.pop_back();
	}

	cout << endl;
	return 0;
}