#include "collection.h"

std::mt19937_64 Collection::randomGenerator{ std::random_device()() };

Collection::Collection(int size, int maxWeight, int maxPrice)
{
    assert((size >= 0) && "The size less than zero was transfer to Collection::constructor(int = 0)");
    if (!_collection.empty()) _collection.clear();
    
    _collection.resize(size);

    if (!_collection.empty())
        for (Item& item : _collection)
        {
            item.set(getRandom(1, maxWeight), getRandom(0, maxPrice));
        }
}

std::vector<Item>::reverse_iterator Collection::rbegin()
{
    return _collection.rbegin();
}

std::vector<Item>::reverse_iterator Collection::rend()
{
    return _collection.rend();
}

void Collection::pushBack(const Item& item)
{
    _collection.push_back(item);
}

void Collection::popBack()
{
    _collection.pop_back();
}

void Collection::sort(std::function<bool(const Item&, const Item&)> comparator)
{
    std::sort(_collection.begin(), _collection.end(), comparator);
}

void Collection::display() const
{
    using std::cout;
    using std::endl;

    if (!_collection.empty())
    {
        using std::string;
        using std::ostringstream;
        using std::setiosflags;
        using std::ios_base;
        using std::setprecision;
        using std::setw;

        cout << setiosflags(ios_base::fixed);

        /// Head of the table

        /// The largest ID in the vector. Uses to calculate the width of the ID column
        int maxID = std::max_element(_collection.begin(), _collection.end(), [](const auto& a, const auto& b) { return (a.getID() < b.getID()); })->getID();
        ostringstream oString;
        oString << setiosflags(ios_base::fixed) << setprecision(0) << maxID;
        unsigned int idColumnWidth = ((oString.str().size() < 3) ? 2 : oString.str().size()) + 2;
        
        /// The largest weight in the vector. Uses to calculate the width of the Weight column
        double maxWeight = std::max_element(_collection.begin(), _collection.end(), [](const auto& a, const auto& b) { return (a.getWeight() < b.getWeight()); })->getWeight();
        oString.str("");
        oString << setiosflags(ios_base::fixed) << setprecision(3) << maxWeight;
        unsigned int weightColumnWidth = ((oString.str().size() < 6) ? 6 : oString.str().size()) + 2;

        /// The largest price in the vector. Uses to calculate the width of the Price column
        double maxPrice = std::max_element(_collection.begin(), _collection.end(), [](const auto& a, const auto& b) { return (a.getPrice() < b.getPrice()); })->getPrice();
        oString.str("");
        oString << setiosflags(ios_base::fixed) << setprecision(2) << maxPrice;
        unsigned int priceColumnWidth = ((oString.str().size() < 5) ? 5 : oString.str().size()) + 2;

        /// The largest unitprice in the vector. Uses to calculate the width of the Unit Price column
        double maxUnitPrice = std::max_element(_collection.begin(), _collection.end(), [](const auto& a, const auto& b) { return (a.getUnitPrice() < b.getUnitPrice()); })->getUnitPrice();
        oString.str("");
        oString << setiosflags(ios_base::fixed) << setprecision(2) << maxUnitPrice;
        unsigned int unitPriceColumnWidth = ((oString.str().size() < 6) ? 6 : oString.str().size()) + 2;

        /// The first table row (head top border line)
        cout << "\n\xC9";
        for (int i{ 0 }; i < idColumnWidth; ++i) cout << '\xCD';
        cout << "\xCB";
        for (int i{ 0 }; i < weightColumnWidth; ++i) cout << '\xCD';
        cout << '\xCB';
        for (int i{ 0 }; i < priceColumnWidth; ++i) cout << '\xCD';
        cout << '\xCB';
        for (int i{ 0 }; i < unitPriceColumnWidth; ++i) cout << '\xCD';
        cout << '\xBB';

        /// The second table row (heading)
        cout << "\n\xBA";
        cout << setw(idColumnWidth) << "ID ";
        cout << "\xBA";
        cout << setw(weightColumnWidth) << "Weight ";
        cout << '\xBA';
        cout << setw(priceColumnWidth) << "Price ";
        cout << '\xBA';
        cout << setw(unitPriceColumnWidth) << "uPrice ";
        cout << '\xBA';
        
        /// The third table row (head bottom border line)
        cout << "\n\xCC";
        for (int i{ 0 }; i < idColumnWidth; ++i) cout << '\xCD';
        cout << "\xCE";
        for (int i{ 0 }; i < weightColumnWidth; ++i) cout << '\xCD';
        cout << '\xCE';
        for (int i{ 0 }; i < priceColumnWidth; ++i) cout << '\xCD';
        cout << '\xCE';
        for (int i{ 0 }; i < unitPriceColumnWidth; ++i) cout << '\xCD';
        cout << '\xB9';

        /// Body of the Array table
        for (const Item& item : _collection)
        {
            cout << "\n\xBA ";
            cout << setw(static_cast<long long>(idColumnWidth - 2)) << item.getID() << " \xBA ";
            cout << setprecision(3) << setw(static_cast<long long>(weightColumnWidth - 2)) << item.getWeight() << " \xBA ";
            cout << setprecision(2) << setw(static_cast<long long>(priceColumnWidth - 2)) << item.getPrice() << " \xBA ";
            cout << setprecision(2) << setw(static_cast<long long>(unitPriceColumnWidth - 2)) << item.getUnitPrice() << " \xBA ";
        }

        /// The last table row (bottom border line)
        cout << "\n\xC8";
        for (int i{ 0 }; i < idColumnWidth; ++i) cout << '\xCD';
        cout << "\xCA";
        for (int i{ 0 }; i < weightColumnWidth; ++i) cout << '\xCD';
        cout << '\xCA';
        for (int i{ 0 }; i < priceColumnWidth; ++i) cout << '\xCD';
        cout << '\xCA';
        for (int i{ 0 }; i < unitPriceColumnWidth; ++i) cout << '\xCD';
        cout << '\xBC';
    }
    else
    {
        cout << "\nList is empty!" << endl;
    }
}

double Collection::getRandom(double rangeMin, double rangeMax)
{
    //static std::mt19937_64 randomGenerator{ std::random_device()() };      ///initializes mt19937_64 by random_device

    std::uniform_real_distribution<double> random(rangeMin, rangeMax);

    return random(randomGenerator);
}
