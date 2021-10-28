/** Задача состоит в том, чтобы выбрать, какие предметы, имеющие вес и стоимость, поместить в рюкзак ограниченной ёмкости W, да так, чтобы
 * максимизировать общую ценность его содержимого. Мы можем определить соотношение стоимости предмета к его весу, т. е. с «жадностью» выбирать
 * предметы, имеющие высокую стоимость, но в то же время маленький вес, а затем сортировать их по этим критериям. В задаче с дробным рюкзаком
 * нам разрешено брать дробные части предмета.
 */

#include "main.h"

using std::cout;
using std::cin;
using std::ios;
using std::endl;
using std::vector;
using std::mt19937_64;

int main(int argc, char* argv)
{
    double backPackCapacity = getCapacity();
    
    int amountItems{ 100 };
    char userAnswer{ 'N' };

    system("cls");
    cout << "Would you like to enter the amount of items? (y/n): ";
    cin >> userAnswer;
    cin.ignore(1024, '\n');

    if (toupper(userAnswer) == 'Y')
    {
        amountItems = getAmount();
    }

    system("cls");
    cout << "Backpack capacity: " << backPackCapacity
        << "\nTotal amount of items: " << amountItems;

    mt19937_64 getRandom;
    std::random_device device;
    getRandom.seed(device());

    vector<Item> apartmentItems(amountItems);

    for (Item item : apartmentItems)
    {
        item.set(getRandom(), getRandom());
    }

    cout << "\nItems: ";
    for (Item item : apartmentItems)
    {
        cout << '\n' << item;
    }

    cout << endl;
    return 0;
}

double getCapacity()
{
    double capacity{ 0 };

    while (true)
    {
        system("cls");
        cout << "Enter a backpack capacity: ";
        cin >> capacity;

        if (capacity <= 0)
        {
            cout << "\n\tThe capacity must be positive!\n\nPress any button to continue...";
            system("pause > nul");
            cin.clear(ios::failbit);
        }
        if (cin.good())
        {
            cin.ignore(1024, '\n');
            break;
        }
        cin.clear();
        cin.ignore(1024, '\n');
    }

    return capacity;
}

int getAmount()
{
    int amount{ 0 };

    while (true)
    {
        system("cls");

        cout << "Enter amount of items: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "\n\tThe amount must be positive integer!\n\nPress any button to continue...";
            system("pause > nul");
            cin.clear(ios::failbit);
        }

        if (cin.good())
        {
            cin.ignore(1024, '\n');
            break;
        }
        cin.clear();
        cin.ignore(1024, '\n');
    }
    return amount;
}