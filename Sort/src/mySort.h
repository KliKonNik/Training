#pragma once

template<class RandomIt>
void mySort(RandomIt startIt, RandomIt endIt, short method = 0)
{
    switch (method)
    {
    case 1:         // Bubble sort
        for (auto it0{ startIt }; it0 != (endIt - 1); ++it0)
        {
            for (auto it1{ startIt }; it1 != (endIt - (it0 - startIt) - 1); ++it1)
            {
                if (*it1 > *(it1 + 1))
                    std::swap(*it1, *(it1 + 1));
            }
        }
        break;
    case 2:         // Bubble sort (optimized)
        for (auto it0{ startIt }; it0 != endIt; ++it0)
        {
            for (auto it1{ endIt - 1 }; it1 != it0; --it1)
            {
                if (*(it1 - 1) > *it1)
                    std::swap(*(it1 - 1), *it1);
            }
        }
        break;
    case 3:         // Insertion sort
    {
        auto operatingIt{ startIt };
        bool goFlag{ true };
        for (auto it0{ startIt + 1 }; it0 != endIt; ++it0)
        {
            operatingIt = it0;
            goFlag = true;
            for (auto it1{ it0 }; it1 != startIt; --it1)
            {
                if (*operatingIt < *(it1 - 1))
                {
                    std::swap(*operatingIt, *(it1 - 1));
                    operatingIt = it1 - 1;
                }
                else goFlag = false;
                if (!goFlag) break;
            }
        }
    }
    break;
    default:        // Selection sort
        for (auto it{ startIt }; it != endIt; ++it)
        {
            std::swap(*it, *(std::min_element(it, endIt)));
        }
    }
}