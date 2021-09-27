// Exc_01.cpp
/*
* 1. Определить комбинированный (структурный) тип, содержащий информацию о студенте: фамилия, имя, массив из трёх оценок
* 2. Определить динамический массив структур, состоящий из N элементов (N >= 5 - вводится с клавиатуры)
* 3. Выполнить ввод элементов в массив структур
* 4. Вывести исходный массив структур на консоль, разработав функцию для форматного вывода элементов массива.
* 5. Разработать функцию для сортировки массива структур (Клименко - 8 букв, чётное, значит ...) по возрастанию (Клименко - 8 букв делить на 4,
*	 остаток = 0, значит ...) по среднему баллу по трём предметам.
* 6. Вывести изменённый массив структур на консоль, используя созданную в п. 4 функцию
* 7. Освободить динамически выделенную память под массив структур.
*/

#include <iostream>

using namespace std;

// п. 1
struct Student
{
	string m_Surname;
	string m_Name;
	int pScores[3] = {0, 0, 0};

	void Show()
	{
		cout << "\n\tSurname: " << m_Surname;
		cout << "\n\tName: " << m_Name;
		cout << "\n\tScores: ";
		for (int i = 0; i < 3; i++)
			cout << pScores[i] << ' ';
		cout << endl;
	}
};

void Display(Student*, int);
void Sort(Student*, int);

int main()
{
	int N{0};

	do {
		cout << "Enter the students count ( >= 5): ";
		cin >> N;
	} while (N < 5);

	// п. 2
	Student* group = new Student[N];

	// п. 3
	for (int i = 0; i < N; i++)
	{
		cout << "Enter data of student #" << i + 1 << ":\n\tSurname: ";
		cin >> group[i].m_Surname;
		cout << "\tName: ";
		cin >> group[i].m_Name;
		cout << "\tScore (sample: 1 2 3): ";
		for (int j = 0; j < 3; j++)
		{
			cin >> group[i].pScores[j];
		}
	}

	// п. 4
	Display(group, N);

	// п. 5
	Sort(group, N);

	// п. 6
	cout << "\n\n====================Sorted====================\n\n";
	Display(group, N);

	// п. 7
	delete[] group;

	cout << endl;
	return 0;
}

void Display(Student* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nStudent #" << i + 1 << ':';
		arr[i].Show();
	}
}

void Sort(Student* arr, int size)
{
	int Average(int*);
	void Swap(Student*, Student*);
	// of everage scores by grow up

	int minAv;

	for (int i = 0; i < size - 1; i++)
	{
		minAv = Average(arr[i].pScores);

		for (int j = i + 1; j < size; j++)
		{
			if (minAv > Average(arr[j].pScores))
			{
				minAv = Average(arr[j].pScores); 
				//swap(arr[i], arr[j]);
				Swap(&arr[i], &arr[j]);
			}
		}
	}
}

int Average(int* arr)
{
	int res = 0;

	for (int i = 0; i < 3; i++)
		res += arr[i];

	res /= 3;

	return res;
}

void Swap(Student* st1, Student* st2)
{
	Student tmp = (*st1);

	(*st1) = (*st2);
	(*st2) = tmp;
}