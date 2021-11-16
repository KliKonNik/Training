#include "mainAdd.h"

int getRandom(int rangeMin, int rangeMax)
{
    static std::mt19937_64 randomGenerator{ std::random_device()() };

    std::uniform_int_distribution<int> random(rangeMin, rangeMax);

    return random(randomGenerator);
}

void displayVector(const vector<int> v, bool sorted)
{
    if (SIZE <= 20)
    {
        cout << "\n" << (sorted ? "Sorted" : "Original") << " Vector : ";
        cout << endl;

        for (auto elem : v)
        {
            cout << elem << ' ';
        }

        cout << endl;
    }
}