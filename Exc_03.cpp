// Exc_03.cpp
// 1. Разработать класс «вектор» (одномерный динамический массив). Методы класса: конструкторы, деструктор и методы преобразования массива
// в соответствии с вариантом.
// 2. Ввести 2 массива по 10 элементов, используя различные конструкторы.
// 3. Один из массивов отсортировать (четные варианты – по убыванию, нечетные – по возрастанию), найти минимальное, среднее и максимальное
// значение массива.
// 4. Для второго массива выполнить задание по варианту
//		01. Найти произведение элементов массива, расположенных между максимальным и минимальным элементами.
//		02. Заменить все отрицательные элементы массива их квадратами.
//		03. Найти сумму элементов массива, расположенных после минимального элемента.
//		04. Преобразовать массив так, чтобы в первой половине располагались элементы, стоявшие в нечетных позициях, а во второй половине – в четных.
//		05. Найти сумму элементов массива, расположенных после максимального элемента.
//		06. Заменить все положительные элементы массива на минимальный элемент.
//		07. Найти сумму модулей элементов массива, расположенных после минимального по модулю элемента.
//		08. Преобразовать массив таким образом, чтобы элементы, равные нулю, располагались после всех остальных.
//		09. Найти произведение элементов массива, расположенных после последнего положительного элемента.
//		10. Заменить все нулевые элементы массива на наибольший отрицательный элемент.
//		11. Найти сумму элементов массива, расположенных после первого положительного элемента.
//		12. Заменить все отрицательные элементы массива на максимальный элемент.
//		13. Преобразовать массив так, чтобы сначала располагались отрицательные элементы, а потом – положительные(0 считать положительным).
//		14. Найти произведение элементов массива, расположенных до минимального элемента.
//		15. Найти произведение элементов массива, расположенных между максимальным по модулю и минимальным по модулю элементами.
//		16. Заменить все положительные элементы массива их корнями.
//		17. Найти произведение модулей элементов массива, расположенных после максимального по модулю элемента.
//		18. Преобразовать массив так, чтобы сначала располагались элементы в интервале[а, b], а потом – все остальные.
//		19. Найти произведение элементов массива, расположенных между первым и вторым отрицательными элементами.
//		20. Заменить все четные элементы массива на наименьший положительный элемент.

#include <iostream>
#include <iomanip>
#include <typeinfo>

// Using---------------------------------------------------

using std::cout;
using std::cin;
using std::endl;
using std::swap;
using std::ostream;
using std::istream;
using std::setprecision;
using std::setiosflags;
using std::resetiosflags;
using std::ios_base;


// Consts--------------------------------------------------

template <typename T>
T Abs(T arg)
{
	return (arg < 0) ? -arg : arg;
}

// Classes-------------------------------------------------
// Class Vector BEGIN--------------------------------------

template <typename T>						// T - basic numeric types only
class Vector {
private:
	T* m_Vect{nullptr};
	int m_Size{0};
//		01. Найти произведение элементов массива, расположенных между максимальным и минимальным элементами.
	void Run1();
//		02. Заменить все отрицательные элементы массива их квадратами.
	void Run2();
//		03. Найти сумму элементов массива, расположенных после минимального элемента.
	void Run3();
//		04. Преобразовать массив так, чтобы в первой половине располагались элементы, стоявшие в нечетных позициях, а во второй половине – в четных.
	void Run4();
//		05. Найти сумму элементов массива, расположенных после максимального элемента.
	void Run5();
//		06. Заменить все положительные элементы массива на минимальный элемент.
	void Run6();
//		07. Найти сумму модулей элементов массива, расположенных после минимального по модулю элемента.
	void Run7();
//		08. Преобразовать массив таким образом, чтобы элементы, равные нулю, располагались после всех остальных.
	void Run8();
//		09. Найти произведение элементов массива, расположенных после последнего положительного элемента.
	void Run9();
//		10. Заменить все нулевые элементы массива на наибольший отрицательный элемент.
	void Run10();
//		11. Найти сумму элементов массива, расположенных после первого положительного элемента.
	void Run11();
//		12. Заменить все отрицательные элементы массива на максимальный элемент.
	void Run12();
//		13. Преобразовать массив так, чтобы сначала располагались отрицательные элементы, а потом – положительные(0 считать положительным).
	void Run13();
//		14. Найти произведение элементов массива, расположенных до минимального элемента.
	void Run14();
//		15. Найти произведение элементов массива, расположенных между максимальным по модулю и минимальным по модулю элементами.
	void Run15();
//		16. Заменить все положительные элементы массива их корнями.
	void Run16();
//		17. Найти произведение модулей элементов массива, расположенных после максимального по модулю элемента.
	void Run17();
//		18. Преобразовать массив так, чтобы сначала располагались элементы в интервале[а, b], а потом – все остальные.
	void Run18();
//		19. Найти произведение элементов массива, расположенных между первым и вторым отрицательными элементами.
	void Run19();
//		20. Заменить все четные элементы массива на наименьший положительный элемент.
	void Run20();

public:
	Vector<T>(int size = 10) : m_Size(size)
	{
		m_Vect = new T[m_Size];
	}
	Vector<T>(const Vector<T>&);
	~Vector()
	{
		if (m_Vect != nullptr)
		{
			delete[] m_Vect;
		}
	}
	void Set(bool rndset);					// true - random set, false - manual set
	void Display() const;
	int GetSize() const;
	void Copy(const Vector<T>&);
	void Insert(T, int);
	T Extract(int);
	void Run(int);
	T Min(bool modulo = false) const;
	T Max(bool modulo = false) const;
	long double Average()const;
	void Sort(bool growup = true);			// sorts by grow <true> - up, <false> - down
	Vector<T>& operator=(const Vector<T>&);
	const T& operator[](int) const;
	T& operator[](int);

	template <typename U>
	friend ostream& operator<<(ostream&, const Vector<U>&);
};

// Class Vector methods------------------------------------
//		01. Найти произведение элементов массива, расположенных между максимальным и минимальным элементами.
template <typename T>
void Vector<T>::Run1()
{
	T min{ Min() };
	T max{ Max() };
	T result{ 1 };
	bool solved{ false };
	int indexMin{ 0 }, indexMax{ 0 };

	for (int i{ 0 }; i < m_Size; i++)
	{
		if (m_Vect[i] == min)
			indexMin = i;
		if (m_Vect[i] == max)
			indexMax = i;
	}

	if (indexMin > indexMax)
		swap(indexMin, indexMax);

	for (int i{ indexMin + 1 }; i < indexMax; i++)
	{
		result *= m_Vect[i];
		solved = true;
	}

	if (solved)
	{
		cout << "\nMultiplication of numbers between Min(" << min << ") and Max(" << max << "): " << result << endl;
	}
	else
	{
		cout << "\nThere're not any elements between Min(" << min << ") and Max(" << max << ")!" << endl;
	}
}

//---------------------------------------------------------
//		02. Заменить все отрицательные элементы массива их квадратами.
template <typename T>
void Vector<T>::Run2()
{
	for (int i{ 0 }; i < m_Size; i++)
	{
		if (m_Vect[i] < 0)
			m_Vect[i] *= m_Vect[i];		
	}
}

//---------------------------------------------------------
//		03. Найти сумму элементов массива, расположенных после минимального элемента.
template <typename T>
void Vector<T>::Run3()
{
	T min{ Min() };
	T result{ 0 };
	bool solved{ false };
	int indexMin{ 0 };

	for (int i{ 0 }; i < m_Size; i++)
	{
		if (m_Vect[i] == min)
			indexMin = i;
	}

	for (int i{ indexMin + 1 }; i < m_Size; i++)
	{
		result += m_Vect[i];
		solved = true;
	}

	if (solved)
	{
		cout << "\nAddition of numbers following Min(" << min << "): " << result << endl;
	}
	else
	{
		cout << "\nThere're no elements following Min(" << min << ")!" << endl;
	}
}

//---------------------------------------------------------
//		04. Преобразовать массив так, чтобы в первой половине располагались элементы, стоявшие в нечетных позициях, а во второй половине – в четных.
template <typename T>
void Vector<T>::Run4()
{
	Vector<T> temp{ *this };

	for (int i{ 0 }; i < m_Size; i++)
	{
		if (i % 2)
		{
			m_Vect[i / 2] = temp[i];
		}
		else
		{
			m_Vect[(m_Size / 2) + (i / 2)] = temp[i];
		}
	}
}

//---------------------------------------------------------
//		05. Найти сумму элементов массива, расположенных после максимального элемента.
template <typename T>
void Vector<T>::Run5()
{
	T max{ Max() };
	T result{ 0 };
	bool solved{ false };
	int indexMax{ 0 };

	for (int i{ 0 }; i < m_Size; i++)
	{
		if (m_Vect[i] == max)
			indexMax = i;
	}

	for (int i{ indexMax + 1 }; i < m_Size; i++)
	{
		result += m_Vect[i];
		solved = true;
	}

	if (solved)
	{
		cout << "\nAddition of numbers following Max(" << max << "): " << result << endl;
	}
	else
	{
		cout << "\nThere're no elements following Max(" << max << ")!" << endl;
	}
}

//---------------------------------------------------------
//		06. Заменить все положительные элементы массива на минимальный элемент.
template <typename T>
void Vector<T>::Run6()
{
	T min{ Min() };

	for (int i{ 0 }; i < m_Size; i++)
	{
		if (m_Vect[i] > 0)
			m_Vect[i] = min;
	}
}

//---------------------------------------------------------
//		07. Найти сумму модулей элементов массива, расположенных после минимального по модулю элемента.
template <typename T>
void Vector<T>::Run7()
{
	T min{ Min(true) };
	T result{ 0 };
	bool solved{ false };
	int indexMin{ 0 };

	for (int i{ 0 }; i < m_Size; i++)
	{
		if (Abs(m_Vect[i]) == min)
			indexMin = i;
	}

	for (int i{ indexMin + 1 }; i < m_Size; i++)
	{
		result += Abs(m_Vect[i]);
		solved = true;
	}

	if (solved)
	{
		cout << "\nAddition of numbers following Min(" << min << ") by modulo: " << result << endl;
	}
	else
	{
		cout << "\nThere're no elements following Min(" << min << ") by modulo!" << endl;
	}
}

//---------------------------------------------------------
//		08. Преобразовать массив таким образом, чтобы элементы, равные нулю, располагались после всех остальных.
template <typename T>
void Vector<T>::Run8()
{
	int i{ m_Size - 1 };

	for (int j{ 0 }; j < i; j++)
	{
		if (m_Vect[j] == 0)
		{
			Insert(Extract(j), m_Size - 1);
			i--;
		}
	}
}

//---------------------------------------------------------
//		09. Найти произведение элементов массива, расположенных после последнего положительного элемента.
template <typename T>
void Vector<T>::Run9()
{
	T result{ 1 };
	bool solved{ false };
	int indexLast{ 0 };

	for (int i{ m_Size - 1 }; i >= 0; i--)
	{
		if (m_Vect[i] >= 0)
		{
			indexLast = i;
			break;
		}
	}

	for (int i{ indexLast + 1 }; i < m_Size; i++)
	{
		result *= m_Vect[i];
		solved = true;
	}

	if (solved)
	{
		cout << "\nMultiplication of numbers following the last positive (" << m_Vect[indexLast] << "): " << result << endl;
	}
	else
	{
		cout << "\nThere're no elements following the last positive (" << m_Vect[indexLast] << ")!" << endl;
	}
}

//---------------------------------------------------------
//		10. Заменить все нулевые элементы массива на наибольший отрицательный элемент.
template <typename T>
void Vector<T>::Run10()
{
	T maxNegative{ Min() };

	for (int i{ 0 }; i < m_Size; i++)
	{
		if ((m_Vect[i] < 0) && (maxNegative < m_Vect[i]))
			maxNegative = m_Vect[i];
	}

	for (int i{ 0 }; i < m_Size; i++)
	{
		if (m_Vect[i] == 0)
			m_Vect[i] = maxNegative;
	}
}

//---------------------------------------------------------
//		11. Найти сумму элементов массива, расположенных после первого положительного элемента.
template <typename T>
void Vector<T>::Run11()
{
	T result{ 0 };
	bool solved{ false };
	int indexFirst{ 0 };

	for (int i{ 0 }; i < m_Size; i++)
	{
		if (m_Vect[i] >= 0)
		{
			indexFirst = i;
			break;
		}
	}

	for (int i{ indexFirst + 1 }; i < m_Size; i++)
	{
		result += m_Vect[i];
		solved = true;
	}

	if (solved)
	{
		cout << "\nAddition of numbers following the first positive (" << m_Vect[indexFirst] << "): " << result << endl;
	}
	else
	{
		cout << "\nThere're no elements following the first positive (" << m_Vect[indexFirst] << ")!" << endl;
	}
}

//---------------------------------------------------------
//		12. Заменить все отрицательные элементы массива на максимальный элемент.
template <typename T>
void Vector<T>::Run12()
{
	T max{ Max() };

	for (int i{ 0 }; i < m_Size; i++)
	{
		if (m_Vect[i] < 0)
			m_Vect[i] = max;
	}
}

//---------------------------------------------------------
//		13. Преобразовать массив так, чтобы сначала располагались отрицательные элементы, а потом – положительные(0 считать положительным).
template <typename T>
void Vector<T>::Run13()
{
	//Sort();
	Vector<T> temp{ *this };
	int i{ 0 };
	bool step{ false };

	while (temp.m_Size != 0)
	{
		for (int j{ 0 }; j < temp.m_Size; j++)
		{
			if (step)
			{
				if (temp[j] >= 0)
				{
					m_Vect[i++] = temp.Extract(j--);
				}
			}
			else
			{
				if (temp[j] < 0)
				{
					m_Vect[i++] = temp.Extract(j--);
				}
			}
		}
		step = true;
	}
}

//---------------------------------------------------------
//		14. Найти произведение элементов массива, расположенных до минимального элемента.
template <typename T>
void Vector<T>::Run14()
{
	T result{ 1 };
	bool solved{ false };
	int indexMin{ 0 };
	T min{ Min() };

	for (int i{ 0 }; i < m_Size; i++)
	{
		if (m_Vect[i] == min)
		{
			indexMin = i;
			break;
		}
	}

	for (int i{ 0 }; i < indexMin; i++)
	{
		result *= m_Vect[i];
		solved = true;
	}

	if (solved)
	{
		cout << "\nMultiplication of numbers preceding the minimal (" << m_Vect[indexMin] << "): " << result << endl;
	}
	else
	{
		cout << "\nThere're no elements preceding the minimal (" << m_Vect[indexMin] << ")!" << endl;
	}
}

//---------------------------------------------------------
//		15. Найти произведение элементов массива, расположенных между максимальным по модулю и минимальным по модулю элементами.
template <typename T>
void Vector<T>::Run15()
{
	T min{ Min(true) };
	T max{ Max(true) };
	T result{ 1 };
	bool solved{ false };
	int indexMin{ 0 }, indexMax{ 0 };

	for (int i{ 0 }; i < m_Size; i++)
	{
		if (Abs(m_Vect[i]) == min)
			indexMin = i;
		if (Abs(m_Vect[i]) == max)
			indexMax = i;
	}

	if (indexMin > indexMax)
		swap(indexMin, indexMax);

	for (int i{ indexMin + 1 }; i < indexMax; i++)
	{
		result *= m_Vect[i];
		solved = true;
	}

	if (solved)
	{
		cout << "\nMultiplication of numbers between Min(" << min << ") and Max(" << max << "): " << result << endl;
	}
	else
	{
		cout << "\nThere're not any elements between Min(" << min << ") and Max(" << max << ")!" << endl;
	}
}

//---------------------------------------------------------
//		16. Заменить все положительные элементы массива их корнями.
template <typename T>
void Vector<T>::Run16()
{
	for (int i{ 0 }; i < m_Size; i++)
	{
		if (m_Vect[i] > 0)
			m_Vect[i] *= m_Vect[i];
	}
}

//---------------------------------------------------------
//		17. Найти произведение модулей элементов массива, расположенных после максимального по модулю элемента.
template <typename T>
void Vector<T>::Run17()
{
	T result{ 1 };
	bool solved{ false };
	int indexMax{ 0 };
	T max{ Max(true) };

	for (int i{ 0 }; i < m_Size; i++)
	{
		if (Abs(m_Vect[i]) == max)
		{
			indexMax = i;
			break;
		}
	}

	for (int i{ indexMax + 1 }; i < m_Size; i++)
	{
		result *= Abs(m_Vect[i]);
		solved = true;
	}

	if (solved)
	{
		cout << "\nMultiplication of numbers following the mudulo maximal (" << m_Vect[indexMax] << "): " << result << endl;
	}
	else
	{
		cout << "\nThere're no elements following the mudulo maximal (" << m_Vect[indexMax] << ")!" << endl;
	}
}

//---------------------------------------------------------
//		18. Преобразовать массив так, чтобы сначала располагались элементы в интервале[а, b], а потом – все остальные.
template <typename T>
void Vector<T>::Run18()
{
	int a{ -1 }, b{ -1 };

	do {
		cout << "Enter the interval [a, b] between 0 and " << (m_Size - 1) << " (like: a b) : ";
		cin >> a >> b;

		if (cin.good()) {
			if (a >= m_Size) a = -1;
			if (b >= m_Size) b = -1;
			cin.ignore(256, '\n');
		}
		else
		{
			a = -1;
			b = -1;
			cin.clear();
			cin.ignore(256, '\n');
		}
	} while ((a < 0) || (b < 0));

	if (a > b) swap(a, b);

	Vector<T> temp{ *this };
	int i{ 0 };


	for (int j{ a }; j <= b; j++)
	{
		m_Vect[i++] = temp[j];
	}
	for (int j{ a }; j <= b; j++)
	{
		(void)temp.Extract(a);
	}
	for (int j{ 0 }; j < temp.m_Size; j++)
	{
		m_Vect[i++] = temp[j];
	}
}

//---------------------------------------------------------
//		19. Найти произведение элементов массива, расположенных между первым и вторым отрицательными элементами.
template <typename T>
void Vector<T>::Run19()
{
	T result{ 1 };
	bool solved{ false };
	bool found{ false };
	int indexFirst{ -1 }, indexSecond{ -1 };

	for (int i{ 0 }; i < m_Size; i++)
	{
		if (m_Vect[i] < 0)
		{
			if(found)
			{
				indexSecond = i;
				break;
			}
			else
			{
				indexFirst = i;
				found = true;
			}
		}
	}

	for (int i{ indexFirst + 1 }; i < indexSecond; i++)
	{
		result *= m_Vect[i];
		solved = true;
	}

	if (solved)
	{
		cout << "\nMultiplication of numbers between the First negative(" << m_Vect[indexFirst] << ") and the Second negative(" << m_Vect[indexSecond] << "): " << result << endl;
	}
	else
	{
		cout << "\nThere're not any elements between the First negative(" << m_Vect[indexFirst] << ") and the Second negative(" << m_Vect[indexSecond] << ")!" << endl;
	}
}

//---------------------------------------------------------
//		20. Заменить все четные элементы массива на наименьший положительный элемент.
template <typename T>
void Vector<T>::Run20()
{
	T minPositive{ Max() };

	for (int i{ 0 }; i < m_Size; i++)
	{
		if ((m_Vect[i] > 0) && (minPositive > m_Vect[i]))
			minPositive = m_Vect[i];
	}
	for (int i{ 0 }; i < m_Size; i += 2)
	{
		m_Vect[i] = minPositive;
	}
}

//---------------------------------------------------------

template <typename T>
Vector<T>::Vector(const Vector<T>& v)
{
	if (m_Vect != nullptr)
	{
		delete[] m_Vect;
	}
	m_Size = v.m_Size;
	m_Vect = new T[m_Size];

	Copy(v);
}

//---------------------------------------------------------

template <typename T>
void Vector<T>::Set(bool rndset)
{
	if (rndset)
	{
		char choice{ 'Y' };
		cout << "Would you fill the vector in zero? (y/n): ";
		cin >> choice;

		if (toupper(choice) == 'Y')
		{
			for (int i{ 0 }; i < m_Size; i++)
			{
				m_Vect[i] = 0;
			}
		}
		else
		{
			srand(static_cast<unsigned int>(time(NULL)));

			for (int i{ 0 }; i < m_Size; i++)
			{
				m_Vect[i] = static_cast<T>(rand() % 100);
				if ((typeid(T) == typeid(float)) || (typeid(T) == typeid(double)) || (typeid(T) == typeid(long double)))
				{
					m_Vect[i] += static_cast<T>(rand() % 100) / 100;
				}
				if (!((typeid(T) == typeid(unsigned short int)) || (typeid(T) == typeid(unsigned int)) || (typeid(T) == typeid(unsigned long int)) || (typeid(T) == typeid(unsigned long long int))))
				{
					m_Vect[i] *= ((rand() % 2) ? 1 : -1);
				}
				m_Vect[i] *= ((rand() % 5) ? 1 : 0);
			}
		}
	}
	else
	{
		cout << "Enter " << m_Size << ((m_Size > 1) ? " elements " : " element ") << " of type \'" << typeid(T).name() << '\''
			<< "\n(separated by space. Example: 10 20 30 .....):" << endl;
		for (int i{ 0 }; i < m_Size; i++)
		{
			cin >> m_Vect[i];
		}
	}
}

//---------------------------------------------------------

template <typename T>
void Vector<T>::Display() const
{
	for (int i{ 0 }; i < m_Size; i++)
	{
		cout << m_Vect[i] << ' ';
	}
}

//---------------------------------------------------------

template<typename T>
int Vector<T>::GetSize() const
{
	return m_Size;
}

//---------------------------------------------------------

template <typename T>
void Vector<T>::Copy(const Vector<T>& v)
{
	if (m_Size != v.m_Size)
	{
		cout << "\n\n\tError (Copy)! Vectors have different sizes!" << endl;
		return;
	}
	for (int i{ 0 }; i < m_Size; i++)
	{
		m_Vect[i] = v.m_Vect[i];
	}
}

//---------------------------------------------------------

template<typename T>
void Vector<T>::Insert(T element, int index)
{
	if ((index < 0) || (index > m_Size))
	{
		cout << "\n\n\tError (Insert): Out of bounds!!!" << endl;
	}
	Vector<T> temp{ *this };

	delete[] m_Vect;
	m_Size++;

	m_Vect = new T[m_Size];

	for (int i{ 0 }; i < m_Size; i++)
	{
		if (i < index)
			m_Vect[i] = temp[i];
		else if (i == index)
			m_Vect[i] = element;
		else
			m_Vect[i] = temp[i - 1];
	}
}

//---------------------------------------------------------

template<typename T>
T Vector<T>::Extract(int index)
{
	Vector<T> temp(*this);

	if ((index < 0) || (index >= m_Size))
	{
		cout << "\n\n\t Error (Extract): Out of bounds!\n" << endl;
		exit(1);
	}

	T res{ m_Vect[index] };
	delete[] m_Vect;
	m_Size--;
	m_Vect = new T[m_Size];

	for (int i{ 0 }; i < temp.m_Size; i++)
	{
		if (i == index) continue;
		if (i < index)
		{
			if(i < m_Size)							// This check is here to avoid Warning C6386 (at this stage 'i' is always less than m_Size)
				m_Vect[i] = temp[i];
		}
		else
		{
			m_Vect[i - 1] = temp[i];
		}
	}
	return res;
}

//---------------------------------------------------------

template<typename T>
void Vector<T>::Run(int task)
{
	switch (task)
	{
	case 1:Run1(); break;
	case 2:Run2(); break;
	case 3:Run3(); break;
	case 4:Run4(); break;
	case 5:Run5(); break;
	case 6:Run6(); break;
	case 7:Run7(); break;
	case 8:Run8(); break;
	case 9:Run9(); break;
	case 10:Run10(); break;
	case 11:Run11(); break;
	case 12:Run12(); break;
	case 13:Run13(); break;
	case 14:Run14(); break;
	case 15:Run15(); break;
	case 16:Run16(); break;
	case 17:Run17(); break;
	case 18:Run18(); break;
	case 19:Run19(); break;
	case 20:Run20(); break;

	default:
		cout << "\n\tERROR! Solve of the task #" << task << " is not found." << endl;
	}
}

//---------------------------------------------------------

template<typename T>
T Vector<T>::Min(bool modulo) const
{
	if (modulo)
	{
		T min{ Abs(m_Vect[0]) };
		for (int i{ 0 }; i < m_Size; i++)
		{
			if (min > Abs(m_Vect[i]))
				min = Abs(m_Vect[i]);
		}

		return min;
	}
	else
	{
		T min{ m_Vect[0] };
		for (int i{ 0 }; i < m_Size; i++)
		{
			if (min > m_Vect[i])
				min = m_Vect[i];
		}

		return min;
	}
}

//---------------------------------------------------------

template<typename T>
T Vector<T>::Max(bool modulo) const
{
	if (modulo)
	{
		T max{ Abs(m_Vect[0]) };
		for (int i{ 0 }; i < m_Size; i++)
		{
			if (max < Abs(m_Vect[i]))
				max = Abs(m_Vect[i]);
		}

		return max;
	}
	else
	{
		T max{ m_Vect[0] };
		for (int i{ 0 }; i < m_Size; i++)
		{
			if (max < m_Vect[i])
				max = m_Vect[i];
		}

		return max;
	}
}

//---------------------------------------------------------

template<typename T>
long double Vector<T>::Average() const
{
	long double res{ 0 };
	for (int i{ 0 }; i < m_Size; i++)
	{
		res += m_Vect[i];
	}

	return res / m_Size;
}

//---------------------------------------------------------

template<typename T>
void Vector<T>::Sort(bool growup)			// sorts by grow <true> - up, <false> - down
{
	if (m_Size <= 0)
	{
		cout << "\n\n\tError (Sort)! Vector is empty!" << endl;
		return;
	}
	if (growup)
	{
		for (int i = 0; i < m_Size - 1; i++)
		{
			for (int j = i + 1; j < m_Size; j++)
			{
				if (m_Vect[i] > m_Vect[j])
				{
					swap(m_Vect[i], m_Vect[j]);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < m_Size - 1; i++)
		{
			for (int j = i + 1; j < m_Size; j++)
			{
				if (m_Vect[i] < m_Vect[j])
				{
					swap(m_Vect[i], m_Vect[j]);
				}
			}
		}
	}
}

//---------------------------------------------------------

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if (this == &v)
	{
		return *this;
	}

	if (m_Vect != nullptr)
	{
		delete[] m_Vect;
	}

	m_Size = v.m_Size;
	m_Vect = new T[m_Size];

	Copy(v);

	return (*this);
}

//---------------------------------------------------------

template <typename T>
const T& Vector<T>::operator[](int index) const
{
	if ((index < 0) || (index >= m_Size))
	{
		cout << "\n\n\tError (const []): Out of bounds!!!" << endl;
		exit(1);
	}
	return m_Vect[index];
}

//---------------------------------------------------------

template <typename T>
T& Vector<T>::operator[](int index)
{
	if ((index < 0) || (index >= m_Size))
	{
		cout << "\n\n\tError ([]): Out of bounds!!!" << endl;
		exit(1);
	}
	return m_Vect[index];
}

// Class Vector END----------------------------------------

template <typename U>
ostream& operator<<(ostream& ostrm, const Vector<U>& obj)
{

	for (int i{ 0 }; i < obj.m_Size; i++)
	{
		ostrm << obj.m_Vect[i] << ' ';
	}
	
	return ostrm;
}

//---------------------------------------------------------

int main()
{
	char answer{ 'N' };
	int choice{ 4 };
	Vector<int> v1;
	Vector<float> v2(10);

	cout << "Autofill Vector #1. ";
	v1.Set(true);
	
	cout << "\nAutofill Vector #2. ";
	v2.Set(true);

	system("cls");

	cout << "\nVector #1 before:\n" << v1 << endl;
	
	cout << "Minimum: " << v1.Min() << endl;
	cout << "Maximum: " << v1.Max() << endl;
	cout << "Average: " << v1.Average() << endl;

	v1.Sort();
	cout << "\nVector #1 sorted by grow up:\n" << v1 << endl;
	v1.Sort(false);
	cout << "\nVector #1 sorted by grow down:\n" << v1 << endl;

	system("pause");

	cout << setiosflags(ios_base::fixed) << setprecision(2);
	do
	{
		system("cls");

		cout << "Which proccess do you want to test (1-20): ";
		cin >> choice;
		cin.ignore(256, '\n');
		cout << "Vector #2 before:\n" << v2 << endl;
		v2.Run(choice);
		cout << "\nVector #2 after:\n" << v2 << endl;

		cout << "\nOnce more? (y/n): ";
		cin >> answer;
		cin.ignore(256, '\n');
	} while (toupper(answer) != 'N');

	cout << endl;
	return 0;
}