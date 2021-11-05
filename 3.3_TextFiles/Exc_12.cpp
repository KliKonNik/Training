// Exc_12.cpp
// К программе EMPL_IO из этой главы добавьте возможность поиска работника в списке, хранящемся в файле, по номеру. При нахождении совпадения, нужно
// вывести данные об этом работнике на экран. Пользователь должен иметь возможность запустить функцию поиска нажатием клавиши 'f'. У пользователя
// спрашивается номер работника. Подумайте над вопросом, какой должна быть эта функция — статической, виртуальной или какой-то еще? Поиск и вывод на
// экран не должны пересекаться с данными в памяти.
// 
// ПРИМЕЧАНИЕ------------------------------------------------------------------------------------------------------------------
// Не пытайтесь прочитать файл, созданный программой EMPL_IO. Классы в программах разные благодаря методу find() в новой программе, и проблемы,
// которые могут возникнуть в случае, если их данные смешаются, уже обсуждались в этой главе. Вам может понадобиться включить параметр RTTI в
// компиляторе. Чтобы не возникало вопросов, следуйте указаниям, данным в приложении В «Microsoft Visual C++» и в приложении Г «Borland C++
// Builder» (выбирайте то, что для вас актуальней).

#include <fstream>
#include <iostream>
using namespace std;

//---------------------------------------------------------

constexpr int g_c_Len = 32;
constexpr int g_c_MaxEpl = 100;

//---------------------------------------------------------

enum class g_ec_Employee_Type { tmanager, tscientist, tlaborer, tunknown };

// Class Employee BEGIN------------------------------------

class Employee
{
private:
	char m_Name[g_c_Len]{ "\0" };
	unsigned long m_Number{ 0 };
	static int m_s_CurrentCount;
	static Employee* m_s_ArrayEmp[];
protected:
	virtual void Copy(const Employee& obj) = 0;
public:
	virtual void GetData()
	{
		cin.ignore(10, '\n');
		cout << "Enter the employee's name: "; cin >> m_Name;
		cout << "Enter the personnel number: "; cin >> m_Number;
	}
	virtual void PutData()
	{
		cout << "\n  Name: " << m_Name;
		cout << "\n  Number: " << m_Number;
	}
	virtual Employee& operator=(const Employee& obj);
	static void Add();
	static void Display();
	static void Write();
	static void Read();
	static void Find();
};

// Class Employee Static variables-------------------------

int Employee::m_s_CurrentCount;
Employee* Employee::m_s_ArrayEmp[g_c_MaxEpl];

// Class Employee END--------------------------------------

// Class Manager BEGIN-------------------------------------

class Manager : public Employee
{
private:
	char m_Title[g_c_Len]{ "\0" };
	double m_GolfClubDues{ 0.0 };
public:
	virtual void GetData()
	{
		Employee::GetData();
		cout << "Enter the title: "; cin >> m_Title;
		cout << "Enter Golf Club dues: "; cin >> m_GolfClubDues;
	}
	virtual void PutData()
	{
		Employee::PutData();
		cout << "\n  Title: " << m_Title;
		cout << "\n  Golf club dues: " << m_GolfClubDues;
	}
protected:
	virtual void Copy(const Employee& obj)
	{
		Employee* temp = const_cast<Employee*>(&obj);

		strcpy_s(m_Title, reinterpret_cast<Manager*>(temp)->m_Title);
		m_GolfClubDues = reinterpret_cast<Manager*>(temp)->m_GolfClubDues;
	}
};

// Class Manager END---------------------------------------

// Class Scientist BEGIN-----------------------------------

class Scientist : public Employee
{
private:
	int m_Publications{ 0 };
public:
	virtual void GetData()
	{
		Employee::GetData();
		cout << "Enter the number of publications: "; cin >> m_Publications;
	}
	virtual void PutData()
	{
		Employee::PutData();
		cout << "\n  Number of publications: " << m_Publications;
	}
protected:
	virtual void Copy(const Employee& obj)
	{
		Employee* temp = const_cast<Employee*>(&obj);

		m_Publications = reinterpret_cast<Scientist*>(temp)->m_Publications;
	}
};

// Class Scientist END-------------------------------------

// Class Laborer BEGIN-------------------------------------

class Laborer : public Employee
{
protected:
	virtual void Copy(const Employee& obj)
	{}
};

// Class Laborer END---------------------------------------

// Others methods------------------------------------------

g_ec_Employee_Type GetType(const Employee* ptrObj)
{
	if (typeid(*ptrObj) == typeid(Manager))
		return g_ec_Employee_Type::tmanager;
	else if (typeid(*ptrObj) == typeid(Scientist))
		return g_ec_Employee_Type::tscientist;
	else if (typeid(*ptrObj) == typeid(Laborer))
		return g_ec_Employee_Type::tlaborer;
	else
	{
		cout << "\nError (GetType)! Error! Worker type is unknown\n";
		exit(1);
	}
	return g_ec_Employee_Type::tunknown;
}

//---------------------------------------------------------

// Class Employee methods----------------------------------

Employee& Employee::operator=(const Employee& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	strcpy_s(m_Name, obj.m_Name);
	m_Number = obj.m_Number;

	Copy(obj);

	return (*this);
}

//---------------------------------------------------------

void Employee::Add()
{
	char ch;

	cout << "\nEnter the Employee ('m' - manager, 's' - scientist, 'l' - laborer): ";
	cin >> ch;

	switch (toupper(ch))
	{
	case 'M': m_s_ArrayEmp[m_s_CurrentCount] = new Manager; break;
	case 'S': m_s_ArrayEmp[m_s_CurrentCount] = new Scientist; break;
	case 'L': m_s_ArrayEmp[m_s_CurrentCount] = new Laborer; break;
	default: cout << "\nError (Add)! Type worker is unknown!\n";
	}
	m_s_ArrayEmp[m_s_CurrentCount++]->GetData();
}

//---------------------------------------------------------

void Employee::Display()
{
	for (int i = 0; i < m_s_CurrentCount; i++)
	{
		cout << (i + 1);

		switch (GetType(m_s_ArrayEmp[i]))
		{
		case g_ec_Employee_Type::tmanager: cout << " Type: Manager"; break;
		case g_ec_Employee_Type::tscientist: cout << " Type: Scientist"; break;
		case g_ec_Employee_Type::tlaborer: cout << " Type: Laborer"; break;
		default: cout << " Type: Unknown";
		}

		m_s_ArrayEmp[i]->PutData();
		cout << endl;
	}
}

//---------------------------------------------------------

void Employee::Write()
{
	int size{ 0 };

	cout << "Writing " << m_s_CurrentCount << " workers...\n";

	ofstream outFile;
	g_ec_Employee_Type eType;

	outFile.open("EMPLOY.DAT", ios::binary | ios::trunc);

	if (!outFile)
	{
		cout << "\nError (Write): File cannot be opened!\n";
		return;
	}

	for (int i = 0; i < m_s_CurrentCount; i++)
	{
		eType = GetType(m_s_ArrayEmp[i]);

		outFile.write((char*)&eType, sizeof(eType));

		switch (eType)
		{
		case g_ec_Employee_Type::tmanager: size = sizeof(Manager); break;
		case g_ec_Employee_Type::tscientist: size = sizeof(Scientist); break;
		case g_ec_Employee_Type::tlaborer: size = sizeof(Laborer); break;
		}

		outFile.write((char*)(m_s_ArrayEmp[i]), size);

		if (!outFile)
		{
			cout << "\nError (Write): File write error!\n";
			return;
		}
	}
    outFile.close();

}

//---------------------------------------------------------

void Employee::Read()
{
	int size;
	g_ec_Employee_Type eType{ g_ec_Employee_Type::tunknown };
	ifstream inFile;
	Employee* ptrTempEmployee;

	inFile.open("EMPLOY.DAT", ios::binary);

	if (!inFile)
	{
		cout << "\nError (Read): File cannot be opened!\n";
		return;
	}

	m_s_CurrentCount = 0;

	while (true)
	{
		inFile.read((char*)&eType, sizeof(g_ec_Employee_Type));

		if (inFile.eof())
			break;

		if (!inFile)
		{
			cout << "\nError (Read): File read error!\n";
			return;
		}

		delete m_s_ArrayEmp[m_s_CurrentCount];

		switch (eType)
		{
		case g_ec_Employee_Type::tmanager:
			m_s_ArrayEmp[m_s_CurrentCount] = new Manager;
			ptrTempEmployee = new Manager;
			size = sizeof(Manager);
			break;
		case g_ec_Employee_Type::tscientist:
			m_s_ArrayEmp[m_s_CurrentCount] = new Scientist;
			ptrTempEmployee = new Scientist;
			size = sizeof(Scientist);
			break;
		case g_ec_Employee_Type::tlaborer:
			m_s_ArrayEmp[m_s_CurrentCount] = new Laborer;
			ptrTempEmployee = new Laborer;
			size = sizeof(Laborer);
			break;
		default:
			cout << "\nError (Read): Unknown type!\n";
			return;
		}

		inFile.read((char*)(ptrTempEmployee), size);

		(*m_s_ArrayEmp[m_s_CurrentCount]) = (*ptrTempEmployee);

		delete ptrTempEmployee;

		if (!inFile)
		{
			cout << "\nError (Read): File opening is impossible!\n";
			return;
		}

		m_s_CurrentCount++;
	}
	cout << "Loading " << m_s_CurrentCount << " workers...\n";
    inFile.close();
}

//---------------------------------------------------------

void Employee::Find()
{
	int size;
	int intLookingFor{ -1 };
	g_ec_Employee_Type eType{ g_ec_Employee_Type::tunknown };
	ifstream inFile;
	Employee * ptrTempEmployeeCut, * ptrTempEmployeeFull;

	inFile.open("EMPLOY.DAT", ios::binary);

	if (!inFile)
	{
		cout << "\nError (Read): File cannot be opened!\n";
		return;
	}

	cout << "Enter the employee's number to search: ";
	cin >> intLookingFor;

	while (true)
	{
		inFile.read((char*)&eType, sizeof(g_ec_Employee_Type));

		if (inFile.eof())
			break;

		if (!inFile)
		{
			cout << "\nError (Read): File read error!\n";
			return;
		}

		switch (eType)
		{
		case g_ec_Employee_Type::tmanager:
			ptrTempEmployeeCut = new Manager;
			ptrTempEmployeeFull = new Manager;
			size = sizeof(Manager);
			break;
		case g_ec_Employee_Type::tscientist:
			ptrTempEmployeeCut = new Scientist;
			ptrTempEmployeeFull = new Scientist;
			size = sizeof(Scientist);
			break;
		case g_ec_Employee_Type::tlaborer:
			ptrTempEmployeeCut = new Laborer;
			ptrTempEmployeeFull = new Laborer;
			size = sizeof(Laborer);
			break;
		default:
			cout << "\nError (Read): Unknown type!\n";
			return;
		}

		inFile.read((char*)(ptrTempEmployeeCut), size);

		if (ptrTempEmployeeCut->m_Number == intLookingFor)
		{
			(*ptrTempEmployeeFull) = (*ptrTempEmployeeCut);
			cout << "\nResult:\n";
			switch (GetType(ptrTempEmployeeFull))
			{
			case g_ec_Employee_Type::tmanager: cout << "Manager:"; break;
			case g_ec_Employee_Type::tscientist: cout << "Scientist:"; break;
			case g_ec_Employee_Type::tlaborer: cout << "Laborer:"; break;
			default: cout << "\tUnknown\n";
			}

			ptrTempEmployeeFull->PutData();
			cout << endl;
			delete ptrTempEmployeeCut;
			delete ptrTempEmployeeFull;
			return;
		}

		delete ptrTempEmployeeCut;
		delete ptrTempEmployeeFull;

		if (!inFile)
		{
			cout << "\nError (Read): File opening is impossible!\n";
			return;
		}

	}
	cout << "Employee with the number " << intLookingFor << " was not found...\n";
    inFile.close();
}

//---------------------------------------------------------

int main()
{
	char choice{ 'X' };

	while(true)
	{
		system("cls");
		cout << "\n'a' - add new employee"
			<< "\n'd' - display info about all employees"
			<< "\n'w' - write all data to file"
			<< "\n'r' - read all data from file"
			<< "\n'f' - search employee in the file by number"
			<< "\n'x' - exit"
			<< "\nWhat do you choice?: ";
		cin >> choice;

		switch (toupper(choice))
		{
		case 'A':
			Employee::Add();
			break;
		case 'D':
			Employee::Display();
			break;
		case 'W':
			Employee::Write();
			break;
		case 'R':
			Employee::Read();
			break;
		case 'F':
			Employee::Find();
			break;
		case 'X':
			exit(0);
			break;
		default:
			cout << "\nUnknown command!\n\n";
		}
		system("pause");
	}

	cout << endl;
	return 0;
}