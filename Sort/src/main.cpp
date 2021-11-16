#include "mainAdd.h"

#include <array>

int main(int argc, char* argv)
{
    vector<int> sampleVector(SIZE);

    for (auto &elem : sampleVector)
    {
        elem = getRandom();
    }

    displayVector(sampleVector);

    auto stop = steady_clock::now();
    auto start = steady_clock::now();
    if ( SIZE > 0) stop = steady_clock::now();
    auto nanoduration = duration_cast<nanoseconds>(SIZE * (stop - start) / 1000);
    cout << "\n" << SIZE << " comparison operations processed\t\t" << nanoduration.count() << " nanosec";

    int* a1 = new int{ 1 };
    int* a2 = new int{ 2 };
    start = steady_clock::now();
    std::swap(*a1, *a2);
    stop = steady_clock::now();
    nanoduration = duration_cast<nanoseconds>(SIZE * (stop - start) / 1000);
    cout << "\n" << SIZE << " swap operations processed\t\t\t" << nanoduration.count() << " nanosec";

    int* tmp{ nullptr };
    start = steady_clock::now();
    tmp = a1;
    a1 = a2;
    a2 = tmp;
    stop = steady_clock::now();
    nanoduration = duration_cast<nanoseconds>(SIZE * (stop - start) / 1000);
    cout << "\n" << SIZE << " my swap operations processed\t\t" << nanoduration.count() << " nanosec";
    delete a1;
    delete a2;
    tmp = a1 = a2 = nullptr;

    /// std::sort test
    vector<int> operatingVector{sampleVector};
    start = steady_clock::now();
    sort(operatingVector.begin(), operatingVector.end());
    stop = steady_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nSTD::SORT processed\t\t\t\t" << duration.count() << " microsec";

    displayVector(operatingVector, true);

    /// mySort(Selection sort) test
    operatingVector = sampleVector;
    start = steady_clock::now();
    mySort(operatingVector.begin(), operatingVector.end());
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nMySort(Selection sort) processed\t\t" << duration.count() << " microsec";

    displayVector(operatingVector, true);
    
    /// mySort(Bubble sort) test
    operatingVector = sampleVector;
    start = steady_clock::now();
    mySort(operatingVector.begin(), operatingVector.end(), 1);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nMySort(Bubble sort) processed\t\t\t" << duration.count() << " microsec";

    displayVector(operatingVector, true);
    
    /// mySort(Bubble sort (optimized)) test
    operatingVector = sampleVector;
    start = steady_clock::now();
    mySort(operatingVector.begin(), operatingVector.end(), 2);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nMySort(Bubble sort (optimized)) processed\t" << duration.count() << " microsec";

    displayVector(operatingVector, true);
    
    /// mySort(Insertion sort) test
    operatingVector = sampleVector;
    start = steady_clock::now();
    mySort(operatingVector.begin(), operatingVector.end(), 3);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nMySort(Insertion sort) processed\t\t" << duration.count() << " microsec";

    displayVector(operatingVector, true);
    
    /// mySort(Bubble sort (index)) test
    operatingVector = sampleVector;
    start = steady_clock::now();
    mySort(operatingVector.begin(), operatingVector.end(), 4);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nMySort(Bubble sort (index)) processed\t\t" << duration.count() << " microsec";

    displayVector(operatingVector, true);

    /// mySort(Bubble sort (index-swap)) test
    operatingVector = sampleVector;
    start = steady_clock::now();
    mySort(operatingVector.begin(), operatingVector.end(), 5);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nMySort(Bubble sort (index-swap)) processed\t" << duration.count() << " microsec";

    displayVector(operatingVector, true);


    //---------------------------------------------------------------------------------------------
    /// mySort(Selection sort) test
    operatingVector = sampleVector;
    start = steady_clock::now();
    mySort(operatingVector);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nMySort+(Selection sort) processed\t\t" << duration.count() << " microsec";

    displayVector(operatingVector, true);

    /// mySort(Bubble sort) test
    operatingVector = sampleVector;
    start = steady_clock::now();
    mySort(operatingVector, 1);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nMySort+(Bubble sort) processed\t\t\t" << duration.count() << " microsec";

    displayVector(operatingVector, true);

    /// mySort(Bubble sort (optimized)) test
    operatingVector = sampleVector;
    start = steady_clock::now();
    mySort(operatingVector, 2);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nMySort+(Bubble sort (optimized)) processed\t" << duration.count() << " microsec";

    displayVector(operatingVector, true);

    /// mySort(Insertion sort) test
    operatingVector = sampleVector;
    start = steady_clock::now();
    mySort(operatingVector, 3);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nMySort+(Insertion sort) processed\t\t" << duration.count() << " microsec";

    displayVector(operatingVector, true);

    cout << endl;

    return 0;
}
