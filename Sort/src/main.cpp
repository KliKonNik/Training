#include "mainAdd.h"

int main(int argc, char* argv)
{
    vector<int> sampleVector(SIZE);

    for (auto &elem : sampleVector)
    {
        elem = getRandom();
    }

    cout << "\nOriginal Vector:";
    //displayVector(sampleVector);

    /// std::sort test
    vector<int> operatingVector{sampleVector};
    auto start = steady_clock::now();
    sort(operatingVector.begin(), operatingVector.end());
    auto stop = steady_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nSTD::SORT proccessed\t\t\t\t" << duration.count() << " microsec";

    /// mySort(Selection sort) test
    operatingVector = sampleVector;
    start = steady_clock::now();
    mySort(operatingVector.begin(), operatingVector.end());
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nMySort(Selection sort) proccessed\t\t" << duration.count() << " microsec";

    /// mySort(Bubble sort) test
    operatingVector = sampleVector;
    start = steady_clock::now();
    mySort(operatingVector.begin(), operatingVector.end(), 1);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nMySort(Bubble sort) proccessed\t\t\t" << duration.count() << " microsec";

    /// mySort(Bubble sort (optimized)) test
    operatingVector = sampleVector;
    start = steady_clock::now();
    mySort(operatingVector.begin(), operatingVector.end(), 2);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nMySort(Bubble sort (optimized)) proccessed\t" << duration.count() << " microsec";

    /// mySort(Insertion sort) test
    operatingVector = sampleVector;
    start = steady_clock::now();
    mySort(operatingVector.begin(), operatingVector.end(), 3);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nMySort(Insertion sort) proccessed\t\t" << duration.count() << " microsec\n" << endl;

    return 0;
}
