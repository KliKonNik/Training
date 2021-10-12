// Exc_04.cpp
// Разработать класс «массив» (двумерный динамический массив). Методы класса: конструктор (выполняет ввод размерности массива, динамическое
// выделение памяти и ввод элементов массива), деструктор (освобождает динамически выделенную под массив память), метод печати (выполняет
// форматный вывод элементов массива в виде таблицы) и friend-метод, выполняющий решение задачи по варианту (если задачу решить нельзя, то
// сообщить об этом).
//		01. Определить сумму элементов в тех строках, которые не содержат отрицательных элементов
//		02. Определить количество строк, содержащих хотя бы один нулевой элемент
//		03. Определить номер первой из строк, не содержащих ни одного положительного элемента
//		04. Определить сумму элементов в тех столбцах, которые содержат хотя бы один положительный элемент
//		05. Определить номер первого из столбцов, содержащих хотя бы один нулевой элемент
//		06. Найти произведение элементов в тех строках, которые не содержат отрицательных элементов
//		07. Определить количество строк, среднее арифметическое элементов которых меньше заданной величины
//		08. Найти сумму модулей элементов, расположенных выше главной диагонали
//		09. Определить количество столбцов, не содержащих ни одного нулевого элемента
//		10. Найти произведение элементов в тех столбцах, которые не содержат отрицательных элементов
//		11. Определить количество строк, сумма элементов которых больше заданной величины
//		12. Определить номер первой из строк, содержащих хотя бы один положительный элемент
//		13. Определить сумму элементов в тех строках, которые содержат хотя бы один отрицательный элемент
//		14. Найти произведение элементов в тех столбцах, которые не содержат положительных элементов
//		15. Найти произведение элементов в тех строках, которые не содержат элементов, кратных 3
//		16. Определить номер первого из столбцов, не содержащих ни одного отрицательного элемента
//		17. Определить количество строк, не содержащих ни одного нулевого элемента
//		18. Определить сумму элементов в тех столбцах, которые содержат хотя бы один отрицательный элемент
//		19. Определить количество столбцов, не содержащих ни одного положительного элемента
//		20. Найти произведение отрицательных элементов, расположенных ниже главной диагонали

#pragma once

#include "Exc_03_.cpp"

// Using---------------------------------------------------

using std::setw;

// Classes-------------------------------------------------
// Class Array BEGIN---------------------------------------

template<typename T>						// T - basic numeric types only
class Array
{
	Vector<T>** m_Array{nullptr};
	int m_Rows{ 0 };
	int m_Columns{ 0 };
//		01. Определить сумму элементов в тех строках, которые не содержат отрицательных элементов
	T Run1() const;
//		02. Определить количество строк, содержащих хотя бы один нулевой элемент
	int Run2() const;
//		03. Определить номер первой из строк, не содержащих ни одного положительного элемента
	int Run3() const;
//		04. Определить сумму элементов в тех столбцах, которые содержат хотя бы один положительный элемент
	T Run4() const;
//		05. Определить номер первого из столбцов, содержащих хотя бы один нулевой элемент
	int Run5() const;
//		06. Найти произведение элементов в тех строках, которые не содержат отрицательных элементов
	T Run6() const;
//		07. Определить количество строк, среднее арифметическое элементов которых меньше заданной величины
	int Run7() const;
//		08. Найти сумму модулей элементов, расположенных выше главной диагонали
	T Run8() const;
//		09. Определить количество столбцов, не содержащих ни одного нулевого элемента
	int Run9() const;
//		10. Найти произведение элементов в тех столбцах, которые не содержат отрицательных элементов
	T Run10() const;
//		11. Определить количество строк, сумма элементов которых больше заданной величины
	int Run11() const;
//		12. Определить номер первой из строк, содержащих хотя бы один положительный элемент
	int Run12() const;
//		13. Определить сумму элементов в тех строках, которые содержат хотя бы один отрицательный элемент
	T Run13() const;
//		14. Найти произведение элементов в тех столбцах, которые не содержат положительных элементов
	T Run14() const;
//		15. Найти произведение элементов в тех строках, которые не содержат элементов, кратных 3
	T Run15() const;
//		16. Определить номер первого из столбцов, не содержащих ни одного отрицательного элемента
	int Run16() const;
//		17. Определить количество строк, не содержащих ни одного нулевого элемента
	int Run17() const;
//		18. Определить сумму элементов в тех столбцах, которые содержат хотя бы один отрицательный элемент
	T Run18() const;
//		19. Определить количество столбцов, не содержащих ни одного положительного элемента
	int Run19() const;
//		20. Найти произведение отрицательных элементов, расположенных ниже главной диагонали
	T Run20() const;
public:
	Array<T>(int rowSize = 10, int columnSize = 10 ) : m_Rows(rowSize), m_Columns(columnSize)
	{
		m_Array = new Vector<T>*[m_Rows];

		for (int i{ 0 }; i < m_Rows; i++)
			m_Array[i] = new Vector<T>(m_Columns);
	}
	Array<T>(const Array<T>&);
	~Array()
	{
		if (m_Array != nullptr)
		{
			for (int i{ 0 }; i < m_Rows; i++)
			{
				delete m_Array[i];
			}
			delete[] m_Array;
		}
	}
	void Copy(const Array<T>&);
	Array<T>& operator=(const Array<T>&);
	const Vector<T>& operator[](int) const;
	Vector<T>& operator[](int);

	void Set(bool = true);
	int GetRows() const;
	int GetColumns() const;
	void Display() const;

	template <typename U>
	friend ostream& operator<<(ostream&, const Array<U>&);
	template <typename U>
	friend void Run(const Array<U>&);
};

// Class Array methods-------------------------------------

//		01. Определить сумму элементов в тех строках, которые не содержат отрицательных элементов

template<typename T>
T Array<T>::Run1() const
{
	T result{ 0 };
	bool solved{ false };
	
	for (int i{ 0 }; i < m_Rows; i++)
	{
		if (m_Array[i]->Min() >= 0)
		{
			for (int j{0}; j < m_Columns; j++)
				result += (*this)[i][j];
			solved = true;
		}
	}

	if (!solved)
	{
		cout << "\nProccessing rows wasn't found!" << endl;
	}

	return result;
}

//		02. Определить количество строк, содержащих хотя бы один нулевой элемент
template<typename T>
int Array<T>::Run2() const
{
	return 0;
}

//		03. Определить номер первой из строк, не содержащих ни одного положительного элемента
template<typename T>
int Array<T>::Run3() const
{
	return 0;
}

//		04. Определить сумму элементов в тех столбцах, которые содержат хотя бы один положительный элемент
template<typename T>
T Array<T>::Run4() const
{
	return T();
}

//		05. Определить номер первого из столбцов, содержащих хотя бы один нулевой элемент
template<typename T>
int Array<T>::Run5() const
{
	return 0;
}

//		06. Найти произведение элементов в тех строках, которые не содержат отрицательных элементов
template<typename T>
T Array<T>::Run6() const
{
	return T();
}

//		07. Определить количество строк, среднее арифметическое элементов которых меньше заданной величины
template<typename T>
int Array<T>::Run7() const
{
	return 0;
}

//		08. Найти сумму модулей элементов, расположенных выше главной диагонали
template<typename T>
T Array<T>::Run8() const
{
	return T();
}

//		09. Определить количество столбцов, не содержащих ни одного нулевого элемента
template<typename T>
int Array<T>::Run9() const
{
	return 0;
}

//		10. Найти произведение элементов в тех столбцах, которые не содержат отрицательных элементов
template<typename T>
T Array<T>::Run10() const
{
	return T();
}

//		11. Определить количество строк, сумма элементов которых больше заданной величины
template<typename T>
int Array<T>::Run11() const
{
	return 0;
}

//		12. Определить номер первой из строк, содержащих хотя бы один положительный элемент
template<typename T>
int Array<T>::Run12() const
{
	return 0;
}

//		13. Определить сумму элементов в тех строках, которые содержат хотя бы один отрицательный элемент
template<typename T>
T Array<T>::Run13() const
{
	return T();
}

//		14. Найти произведение элементов в тех столбцах, которые не содержат положительных элементов
template<typename T>
T Array<T>::Run14() const
{
	return T();
}

//		15. Найти произведение элементов в тех строках, которые не содержат элементов, кратных 3
template<typename T>
T Array<T>::Run15() const
{
	return T();
}

//		16. Определить номер первого из столбцов, не содержащих ни одного отрицательного элемента
template<typename T>
int Array<T>::Run16() const
{
	return 0;
}

//		17. Определить количество строк, не содержащих ни одного нулевого элемента
template<typename T>
int Array<T>::Run17() const
{
	return 0;
}

//		18. Определить сумму элементов в тех столбцах, которые содержат хотя бы один отрицательный элемент
template<typename T>
T Array<T>::Run18() const
{
	return T();
}

//		19. Определить количество столбцов, не содержащих ни одного положительного элемента
template<typename T>
int Array<T>::Run19() const
{
	return 0;
}

//		20. Найти произведение отрицательных элементов, расположенных ниже главной диагонали
template<typename T>
T Array<T>::Run20() const
{
	return T();
}

//---------------------------------------------------------

template <typename T>
Array<T>::Array(const Array<T>& arr)
{
	if (m_Array != nullptr)
	{
		delete this;
	}
	m_Rows = arr.m_Rows;
	m_Columns = arr.m_Columns;
	m_Array = new Vector<T>*[m_Rows];

	for (int i{ 0 }; i < m_Rows; i++)
		m_Array[i] = new Vector<T>(m_Columns);

	Copy(arr);
}

//---------------------------------------------------------

template <typename T>
void Array<T>::Copy(const Array<T>& arr)
{
	if ((m_Rows != arr.m_Rows) || (m_Columns != arr.m_Columns))
	{
		cout << "\n\n\tError (Copy)! Arrays have different sizes!" << endl;
		return;
	}
	for (int i{ 0 }; i < m_Rows; i++)
	{
		for (int j{ 0 }; j < m_Columns; j++)
		{
			(*this)[i][j] = arr[i][j];
		}
	}
}

//---------------------------------------------------------

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& arr)
{
	if (this == &arr)
	{
		return *this;
	}

	if (m_Array != nullptr)
	{
		for (int i{ 0 }; i < m_Rows; i++)
		{
			delete m_Array[i];
		}

		delete[] m_Array;
	}

	m_Rows = arr.m_Rows;
	m_Columns = arr.m_Columns;

	m_Array = new Vector<T>*[m_Rows];

	for (int i{ 0 }; i < m_Rows; i++)
		m_Array[i] = new Vector<T>(m_Columns);

	Copy(arr);

	return (*this);
}

//---------------------------------------------------------

template <typename T>
const Vector<T>& Array<T>::operator[](int index) const
{
	if ((index < 0) || (index >= m_Rows))
	{
		cout << "\n\n\tError (const []): Out of bounds!!!" << endl;
		exit(1);
	}
	return *m_Array[index];
}

//---------------------------------------------------------

template <typename T>
Vector<T>& Array<T>::operator[](int index)
{
	if ((index < 0) || (index >= m_Rows))
	{
		cout << "\n\n\tError ([]): Out of bounds!!!" << endl;
		exit(1);
	}
	return *m_Array[index];
}

//---------------------------------------------------------

template<typename T>
void Array<T>::Set(bool rndset)
{
	for (int i{ 0 }; i < m_Rows; i++)
	{
		m_Array[i]->Set(rndset);
	}
}

//---------------------------------------------------------

template<typename T>
int Array<T>::GetRows() const
{
	return m_Rows;
}

//---------------------------------------------------------

template<typename T>
int Array<T>::GetColumns() const
{
	return m_Columns;
}

//---------------------------------------------------------

template<typename T>
void Array<T>::Display() const
{
	cout << *this;
}

// Class Array END-----------------------------------------

// Class Array's Friends-----------------------------------

template <typename U>
ostream& operator<<(ostream& ostrm, const Array<U>& arr)
{
	ostrm << setiosflags(ios_base::fixed) << setprecision(2);

	// Head of the Array table
	ostrm << "\n+----+";
	for (int i{ 0 }; i < (arr.m_Columns * 10); i++)
	{
		ostrm << "-";
	}
	ostrm << '+' << endl;
	ostrm << "|Rows|";
	for (int i{ 0 }; i < (((arr.m_Columns * 10) / 2) - 4); i++)
	{
		ostrm << " ";
	}
	ostrm << "Columns";
	for (int i{ ((arr.m_Columns * 10) / 2) + 3 }; i < (arr.m_Columns * 10); i++)
	{
		ostrm << " ";
	}
	ostrm << '|' << endl;
	ostrm << "|    |";
	for (int i{ 0 }; i < arr.m_Columns; i++)
	{
		ostrm << setw(10) << (i + 1);
	}
	ostrm << '|' << endl;
	ostrm << "+----+";
	for (int i{ 0 }; i < (arr.m_Columns * 10); i++)
	{
		ostrm << "-";
	}
	ostrm << '+' << endl;

	// Body of the Array table
	for (int i{ 0 }; i < arr.m_Rows; i++)
	{
		ostrm << '|' << setw(4) << (i + 1) << '|';
		for (int j{ 0 }; j < arr.m_Columns; j++)
		{
			ostrm << setw(10) << arr[i][j];
		}
		ostrm << '|' << endl;
	}
	ostrm << "+----+";
	for (int i{ 0 }; i < (arr.m_Columns * 10); i++)
	{
		ostrm << "-";
	}
	ostrm << '+' << endl;

	return ostrm;
}

//---------------------------------------------------------

template <typename U>
void Run(const Array<U>& arr)
{
	int task{ 0 };

	cout << "Enter task number: ";
	cin >> task;
	cin.ignore(256, '\n');

	switch (task)
	{
	case 1: cout << "\nResult = " << arr.Run1() << endl;	break;
	case 2: cout << "\nResult = " << arr.Run2() << endl;	break;
	case 3: cout << "\nResult = " << arr.Run3() << endl;	break;
	case 4: cout << "\nResult = " << arr.Run4() << endl;	break;
	case 5: cout << "\nResult = " << arr.Run5() << endl;	break;
	case 6: cout << "\nResult = " << arr.Run6() << endl;	break;
	case 7: cout << "\nResult = " << arr.Run7() << endl;	break;
	case 8: cout << "\nResult = " << arr.Run8() << endl;	break;
	case 9: cout << "\nResult = " << arr.Run9() << endl;	break;
	case 10: cout << "\nResult = " << arr.Run10() << endl;	break;
	case 11: cout << "\nResult = " << arr.Run11() << endl;	break;
	case 12: cout << "\nResult = " << arr.Run12() << endl;	break;
	case 13: cout << "\nResult = " << arr.Run13() << endl;	break;
	case 14: cout << "\nResult = " << arr.Run14() << endl;	break;
	case 15: cout << "\nResult = " << arr.Run15() << endl;	break;
	case 16: cout << "\nResult = " << arr.Run16() << endl;	break;
	case 17: cout << "\nResult = " << arr.Run17() << endl;	break;
	case 18: cout << "\nResult = " << arr.Run18() << endl;	break;
	case 19: cout << "\nResult = " << arr.Run19() << endl;	break;
	case 20: cout << "\nResult = " << arr.Run20() << endl;	break;
	default:
		cout << "\n\tERROR! Solve of the task #" << task << " is not found." << endl;
	}
}

//---------------------------------------------------------

int main()
{
	Array<double> arr1(5, 5);

	char answer{ 'N' };

	do
	{
		system("cls");

		cout << "\nDo you want to generate new array values? (y/n): ";
		cin >> answer;
		cin.ignore(256, '\n');

		if(toupper(answer) == 'Y')
			arr1.Set(true);

		cout << "\nArr1:" << arr1 << endl;

		Run(arr1);
			
		cout << "\nOnce more? (y/n): ";
		cin >> answer;
		cin.ignore(256, '\n');
	} while (toupper(answer) == 'Y');



	cout << endl;
	return 0;
}