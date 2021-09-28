// Exc_02.cpp
// Разработать класс «строка». Методы класса: конструктор, деструктор и метод, выполняющий задание в соответствии с вариантом.
//  №	Задание
//  1.	Дана строка символов. Заменить в ней каждую букву "a" на последнюю букву последовательности, подсчитать количество таких замен.
//  2.	Дана строка символов, среди которых есть хотя бы один пробел. Заменить в ней знаком "!" все запятые после первого пробела, подсчитать количество
//		таких замен.
//  3.	Дана строка символов. Если длина строки нечетная, поменять местами первую и вторую половины строки относительно центрального символа,
//		иначе вставить символы "*" в середину строки.
//  4.	Дана строка символов. Если в ней есть символ "!", то заменить все символы "!" на "?", иначе изменить порядок следования символов на обратный.
//  5.	Дана строка символов. Удалить каждый символ "*", подсчитать количество удалений.
//  6.	Дана строка символов. Если длина строки четная, заменить в ней все точки на запятые в первой половине строке, иначе удалить центральный символ.
//  7.	Дана строка символов. Заменить в ней все рядом стоящие одинаковые символы на символ "*".
//  8.	Дана строка символов. Подсчитать, сколько раз в строку входит последний символ, и заменить все пробелы на этот символ.
//  9.	Дана строка символов. Удалить из нее все парные вхождения символов. Подсчитать количество удалений.
// 10.	Дана строка символов. Удалить первую 1 / 3 часть строки, если ее длина кратна 3, в противном случае в начало строки вставить символ "+".
// 11.	Дана строка символов, среди которых есть хотя бы одна точка. Заменить в ней знаком "+" все цифры "3" до первой точки, подсчитать количество
//		таких замен.
// 12.	Дана строка символов. Если длина строки четная, заменить в ней все пробелы на точки во второй половине строке, иначе центральный символ заменить
//		на пробел.
// 13.	Дана строка символов. Подсчитать, сколько раз в строку входит первый символ, и заменить все точки на этот символ.
// 14.	Дана строка символов. Удалить средний символ, если длина строки нечетная, в противном случае в середину строки вставить символы "!!!".
// 15.	Дана строка символов. Если длина строки четная, поменять местами первую и вторую половины строки, иначе вставить символы "!!!" в начало строки.
// 16.	Дана строка символов. Подсчитать, сколько раз в строку входит первый символ. Удалить часть строки, расположенную после последнего вхождения
//		первого символа.
// 17.	Дана строка символов. Заменить в ней каждую букву "с" на первую букву последовательности, подсчитать количество таких замен.
// 18.	Дана строка символов. Если в ней есть символ "+", удалить все символы предшествующие ему. Если такого символа нет, изменить порядок
//		следования символов на обратный.
// 19.	Дана строка символов. Удалить все пробелы, подсчитать количество удалений.
// 20.	Дана строка символов. Если длина строки кратна 5, удалить последнюю 1 / 5 длины строки, в противном случае поменять местами первый и последний
//		символы строки.



#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::swap;
using std::ostream;
using std::istream;

constexpr int g_c_MaxSize = 80;

// Class String BEGIN--------------------------------------

class String
{
	char* m_Str;
	
	// methods
	void Run1();
	void Run2();
	void Run3();
	void Run4();
	void Run5();
	void Run6();
	void Run7();
	void Run8();
	void Run9();
	void Run10();
	void Run11();
	void Run12();
	void Run13();
	void Run14();
	void Run15();
	void Run16();
	void Run17();
	void Run18();
	void Run19();
	void Run20();

public:
	String()
	{
		m_Str = new char[g_c_MaxSize];
		m_Str[0] = '\0';
	}
	String(const char* pStr)
	{
		m_Str = new char[g_c_MaxSize];
		Set(pStr);
	}
	String(const String&);
	~String()
	{
		delete[] m_Str;
	}
	const char* Get() const
	{
		return m_Str;
	}

	void Set(const char*);
	const char* Reverse();
	bool Insert(char, int);
	int ReplaceChar(char, char);
	bool DeleteLetter(int);
	int DeleteChar(char);
	void DeleteSubString(int, int);
	int Length() const;
	int HowMany(char) const;
	void Run(int);

	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);
};

// Methods-------------------------------------------------
//  1.	Дана строка символов. Заменить в ней каждую букву "a" на последнюю букву последовательности, подсчитать количество таких замен.
void String::Run1()
{
	cout << "\nReplacements: " << ReplaceChar('a', m_Str[Length() - 1]);
}

//---------------------------------------------------------
//  2.	Дана строка символов, среди которых есть хотя бы один пробел. Заменить в ней знаком "!" все запятые после первого пробела, подсчитать количество
//		таких замен.
void String::Run2()
{
	int counter{ -1 };

	for (int i = 0, len = Length(); i < len; i++)
	{
		if ((m_Str[i] == ' ') && (counter == -1)) counter++;
		
		if ((m_Str[i] == ',') && (counter != -1))
		{
			m_Str[i] = '!';
			counter++;
		}
	}
	
	if (counter == -1) counter++;

	cout << "\nReplacements: " << counter;
}

//---------------------------------------------------------
//  3.	Дана строка символов. Если длина строки нечетная, поменять местами первую и вторую половины строки относительно центрального символа,
//		иначе вставить символы "*" в середину строки.
void String::Run3()
{
	if (Length() % 2)
	{
		String temp{*this};

		for (int i = 0, len = Length(); i < len; i++)
		{
			if (i < len / 2)
			{
				m_Str[i] = temp.m_Str[len / 2 + i + 1];
			}
			if (i > len / 2)
			{
				m_Str[i] = temp.m_Str[i - len / 2 - 1];
			}
		}
	}
	else
	{
		Insert('*', (Length() / 2));
	}
}

//---------------------------------------------------------
//  4.	Дана строка символов. Если в ней есть символ "!", то заменить все символы "!" на "?", иначе изменить порядок следования символов на обратный.
void String::Run4()
{
	if (!ReplaceChar('!', '?')) Reverse();
}

//---------------------------------------------------------
//  5.	Дана строка символов. Удалить каждый символ "*", подсчитать количество удалений.
void String::Run5()
{
	 cout << "\nDeleted: " << DeleteChar('*');
}

//---------------------------------------------------------
//  6.	Дана строка символов. Если длина строки четная, заменить в ней все точки на запятые в первой половине строке, иначе удалить центральный символ.
void String::Run6()
{
	if (Length() % 2)
	{
		DeleteLetter(Length() / 2);
	}
	else
	{
		for (int i = 0, len = Length() / 2; i < len; i++)
		{
			if (m_Str[i] == '.')
			{
				m_Str[i] = ',';
			}
		}
	}
}

//---------------------------------------------------------
//  7.	Дана строка символов. Заменить в ней все рядом стоящие одинаковые символы на символ "*".
void String::Run7()
{
	int j{ 0 };

	for (int i = 0, len{ Length() }; i < len - 1; i++)
	{
		if ((m_Str[i] != '*') && (m_Str[i] == m_Str[i + 1]))
		{
			j = i + 1;
			while (m_Str[i] == m_Str[j])
				j++;
			for (int k = i; k < j; k++) m_Str[k] = '*';
			i += (j - i);
		}
	}
}

//---------------------------------------------------------
//  8.	Дана строка символов. Подсчитать, сколько раз в строку входит последний символ, и заменить все пробелы на этот символ.
void String::Run8()
{
	cout << "\nCharacter \'" << m_Str[Length() - 1] << "\' is in the string " << HowMany(m_Str[Length() - 1]) << " times." << endl;
	(void)ReplaceChar(' ', m_Str[Length() - 1]);
}

//---------------------------------------------------------
//  9.	Дана строка символов. Удалить из нее все парные вхождения символов. Подсчитать количество удалений.
void String::Run9()
{
	int number{ 0 };
	int len{ Length() };

	for (int i{ 0 }; i < len; i++)
	{
		if (HowMany(m_Str[i]) == 2)
		{
			number += DeleteChar(m_Str[i]);
			len = Length();
			i -= 2;
		}
	}

	cout << "\nDeleted: " << number << endl;
}

//---------------------------------------------------------
// 10.	Дана строка символов. Удалить первую 1/3 часть строки, если ее длина кратна 3, в противном случае в начало строки вставить символ "+".
void String::Run10()
{
	if ((Length() % 3))
	{
		Insert('+', 0);
	}
	else
	{
		DeleteSubString(0, (Length() / 3));
	}
}

//---------------------------------------------------------
// 11.	Дана строка символов, среди которых есть хотя бы одна точка. Заменить в ней знаком "+" все цифры "3" до первой точки, подсчитать количество
//		таких замен.
void String::Run11()
{
	int number{ 0 };

	for (int i{ 0 }, len{ Length() }; i < len; i++)
	{
		if (m_Str[i] == '.') break;
		if (m_Str[i] == '3')
		{
			m_Str[i] = '+';
			number++;
		}
	}

	cout << "\nReplaced: " << number << endl;
}

//---------------------------------------------------------
// 12.	Дана строка символов. Если длина строки четная, заменить в ней все пробелы на точки во второй половине строке, иначе центральный символ заменить
//		на пробел.
void String::Run12()
{
	if (Length() % 2)
	{
		m_Str[Length() / 2] = ' ';
	}
	else
	{
		for (int len{ Length() }, i{ len / 2 }; i < len; i++)
		{
			if (m_Str[i] == ' ') m_Str[i] = '.';
		}
	}
}

//---------------------------------------------------------
// 13.	Дана строка символов. Подсчитать, сколько раз в строку входит первый символ, и заменить все точки на этот символ.
void String::Run13()
{
	cout << "\nCharacter \'" << m_Str[0] << "\' is in the string " << HowMany(m_Str[0]) << " times." << endl;
	(void)ReplaceChar('.', m_Str[0]);
}

//---------------------------------------------------------
// 14.	Дана строка символов. Удалить средний символ, если длина строки нечетная, в противном случае в середину строки вставить символы "!!!".
void String::Run14()
{
	if (Length() % 2)
	{
		DeleteLetter(Length() / 2);
	}
	else
	{
		int middle = Length() / 2;
		for (int i{0}; i < 3; i++)
		{
			Insert('!', middle);
		}
	}
}

//---------------------------------------------------------
// 15.	Дана строка символов. Если длина строки четная, поменять местами первую и вторую половины строки, иначе вставить символы "!!!" в начало строки.
void String::Run15()
{
	if (Length() % 2)
	{
		for (int i{ 0 }; i < 3; i++)
		{
			Insert('!', 0);
		}
	}
	else
	{
		String temp{ *this };

		for (int i = 0, len = Length(); i < len; i++)
		{
			if (i < len / 2)
			{
				m_Str[i] = temp.m_Str[len / 2 + i];
			}
			if (i >= len / 2)
			{
				m_Str[i] = temp.m_Str[i - len / 2];
			}
		}
	}
}

//---------------------------------------------------------
// 16.	Дана строка символов. Подсчитать, сколько раз в строку входит первый символ. Удалить часть строки, расположенную после последнего вхождения
//		первого символа.
void String::Run16()
{
	cout << "\nCharacter \'" << m_Str[0] << "\' is in the string " << HowMany(m_Str[0]) << " times." << endl;
	
	int i{ Length() - 1 };

	while (m_Str[i] != m_Str[0])
	{
		i--;
	}

	DeleteSubString(i + 1, Length() - i - 1);
}

//---------------------------------------------------------
// 17.	Дана строка символов. Заменить в ней каждую букву "с" на первую букву последовательности, подсчитать количество таких замен.
void String::Run17()
{
	cout << "\nReplacements: " << ReplaceChar('c', m_Str[0]);
}

//---------------------------------------------------------
// 18.	Дана строка символов. Если в ней есть символ "+", удалить все символы предшествующие ему. Если такого символа нет, изменить порядок
//		следования символов на обратный.
void String::Run18()
{
	if (HowMany('+'))
	{
		int i{ 0 };
		while (m_Str[i] != '+')
			i++;
		DeleteSubString(0, i);
	}
	else
	{
		(void)Reverse();
	}
}

//---------------------------------------------------------
// 19.	Дана строка символов. Удалить все пробелы, подсчитать количество удалений.
void String::Run19()
{
	cout << "\nDeleted: " << DeleteChar(' ');
}

//---------------------------------------------------------
// 20.	Дана строка символов. Если длина строки кратна 5, удалить последнюю 1 / 5 длины строки, в противном случае поменять местами первый и последний
//		символы строки.
void String::Run20()
{
	if ((Length() % 5))
	{
		swap(m_Str[0], m_Str[Length() - 1]);
	}
	else
	{
		DeleteSubString(Length() - (Length() / 5), (Length() / 5) + 1);
	}
}

//---------------------------------------------------------

String::String(const String& obj)
{
	m_Str = new char[g_c_MaxSize];
	Set(obj.m_Str);
}

//---------------------------------------------------------

void String::Set(const char* str)
{
	int i{ 0 };
	
	while ((i < (g_c_MaxSize - 1)) && str[i] != '\0')
	{
		m_Str[i] = str[i];
		i++;
	}

	m_Str[i] = '\0';
}

//---------------------------------------------------------

const char* String::Reverse()
{
	char* revstr = new char[g_c_MaxSize];
	
	for (int i = 0, len{ Length() }; i < len; i++)
		revstr[len - i - 1] = m_Str[i];

	revstr[Length()] = '\0';
	
	swap(m_Str, revstr);

	delete[] revstr;

	return m_Str;
}

//---------------------------------------------------------

bool String::Insert(char ch, int ind)
{
	if ((ind > Length()) || (Length() >= g_c_MaxSize - 1))
	{
		cout << "\n\n\tERROR: Insert! Out of bound!!!\n\n" << endl;
		return false;
	}
	m_Str[Length() + 1] = '\0';
	for (int i{ Length() - 1}; i >= ind; i--)
	{
		m_Str[i + 1] = m_Str[i];
	}

	m_Str[ind] = ch;

	return true;
}

//---------------------------------------------------------

int String::ReplaceChar(char what, char replaceOn)
{
	int changeCounter{ 0 };

	for (int i = 0, len{ Length() }; i < len; i++)
	{
		if (m_Str[i] == what)
		{
			m_Str[i] = replaceOn;
			changeCounter++;
		}
	}

	return changeCounter;
}

//---------------------------------------------------------

bool String::DeleteLetter(int ind)
{
	if ((ind > Length()) || (Length() <= 0))
	{
		cout << "\n\n\tERROR: DeleteLetter! Out of bound!!!\n\n" << endl;
		return false;
	}
	
	for (int i = ind, len{ Length() }; i < len; i++)
		m_Str[i] = m_Str[i + 1];

	return true;
}

//---------------------------------------------------------

int String::DeleteChar(char ch)
{
	int delCounter{ 0 };
	unsigned int i{ 0 };
	int len{ Length() };

	while (m_Str[i] != '\0')
	{
		if (m_Str[i] == ch)
		{
			DeleteLetter(i);
			i--;
			delCounter++;
		}
		i++;
	}

	return delCounter;
}

//---------------------------------------------------------

void String::DeleteSubString(int begin, int number)
{
	for (int i{ 0 }; i < number; i++)
		DeleteLetter(begin);
}

//---------------------------------------------------------

int String::Length() const
{
	int len = 0;
	while (m_Str[len] != '\0')
	{
		len++;
	}

	return len;
}

//---------------------------------------------------------

int String::HowMany(char ch) const
{
	int number{ 0 };

	for (int i{ 0 }, len{ Length() }; i < len; i++)
	{
		if (m_Str[i] == ch) number++;
	}

	return number;
}

//---------------------------------------------------------

void String::Run(int task)
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

ostream& operator<<(ostream& ostrm, const String& obj)
{
	ostrm << obj.m_Str;
	return ostrm;
}

//---------------------------------------------------------

istream& operator>>(istream& istrm, String& obj)
{
	cin >> obj.m_Str;
	return istrm;
}

// Class String END----------------------------------------

int main()
{
	String str{"abcdefg"};
	char answer{ 'N' };
	int choice{ 4 };

	cout << "Do you want to enter the string yourself (y/n): ";
	cin >> answer;
	cin.ignore(256, '\n');

	if (toupper(answer) == 'Y')
	{
		char temp[g_c_MaxSize]{ '\0' };
		cout << "Your string:" << endl;
		cin.getline(temp, g_c_MaxSize);
		str.Set(temp);
	}
	else
	{

	}

	do
	{
		system("cls");

		cout << "Which proccess do you want to test (1-20): ";
		cin >> choice;
		cin.ignore(256, '\n');
		cout << "String before:\n" << str << endl;
		str.Run(choice);
		cout << "\nString after:\n" << str << endl;

		cout << "\nOnce more? (y/n): ";
		cin >> answer;
	} while (toupper(answer) != 'N');

	cout << endl;
	return 0;
}