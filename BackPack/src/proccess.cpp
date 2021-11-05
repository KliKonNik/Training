#include "proccess.h"

Proccess::Proccess(int maxWeight_, int maxPrice_)
    : _maxWeight(maxWeight_),
    _maxPrice(maxPrice_)
{
}

void Proccess::init()
{
    _flat = Collection(getItemsAmountFromUser(), _maxWeight, _maxPrice);
    _backpack = BackPack(getCapacityFromUser());
}

void Proccess::display() const
{
    using std::cout;

    cout << "\nList of the items in the flat:\n";
    _flat.display();
    cout << "\nList of the items in the backpack:\n";
    _backpack.display();
}

void Proccess::execute()
{
    _flat.sort([](const auto& a, const auto& b) -> bool { return (a.getUnitPrice() < b.getUnitPrice()); });

    for (auto item{ _flat.rbegin() }; item != _flat.rend(); ++item)
        _backpack.putIn(*item);
}

double Proccess::getCapacityFromUser() const
{
    using std::cout;
    using std::cin;
    using std::ios;

    double capacity{ 0 };
    
    while (true)
    {
        system("cls");
        cout << "Enter a backpack capacity (in kg): ";
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

int Proccess::getItemsAmountFromUser() const
{
    using std::cout;
    using std::cin;
    using std::ios;

    int amount{ 0 };
    
    while (true)
    {
        system("cls");
    
        cout << "Enter amount of items (in pieces): ";
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

