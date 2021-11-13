#pragma once

#include <vector>

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
    case 4:         // Bubble sort on indexes
    {
        auto coll = startIt;
        auto tmp = startIt;
        size_t size = endIt - startIt;
        for (size_t i0{ 0 }; i0 < size; ++i0)
        {
            for (size_t i1{ 0 }; i1 < size - i0 - 1; ++i1)
            {
                if (coll[i1] > coll[i1 + 1])
                {
                    std::swap(coll[i1], coll[i1 + 1]);
                }
            }
        }
    }
    break;
    case 5:         // Bubble sort on indexes + swap
    {
        auto coll = startIt;
        auto tmp = *startIt;
        size_t size = endIt - startIt;
        for (size_t i0{ 0 }; i0 < size; ++i0)
        {
            for (size_t i1{ 0 }; i1 < size - i0 - 1; ++i1)
            {
                if (coll[i1] > coll[i1 + 1])
                {
                    tmp = coll[i1];
                    coll[i1] = coll[i1 + 1];
                    coll[i1 + 1] = tmp;
                }
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

template<class T>
void mySort(std::vector<T>& v, short method = 0)
{
    switch (method)
    {
    case 1:         // Bubble sort
        for (size_t i0{ 0 }; i0 < v.size(); ++i0)
        {
            for (size_t i1{ 0 }; i1 < v.size() - i0 -1; ++i1)
            {
                if (v[i1] > v[i1 + 1])
                    std::swap(v[i1], v[i1 + 1]);
            }
        }
        break;
    case 2:         // Bubble sort (optimized)
        for (size_t i0{ 0 }; i0 < v.size(); ++i0)
        {
            for (size_t i1{ v.size() - 1 }; i1 > i0; --i1)
            {
                if (v[i1 - 1] > v[i1])
                    std::swap(v[i1 - 1], v[i1]);
            }
        }
        break;
    case 3:         // Insertion sort
    {
        T* operatingVal{ &v[0] };                                        
        bool goFlag{ true };
        for (size_t i0{ 1 }; i0 < v.size(); ++i0)
        {
            operatingVal = &v[i0];
            goFlag = true;
            for (size_t i1{ i0 }; i1 > 0; --i1)
            {
                if (*operatingVal < v[i1 - 1])
                {
                    std::swap(*operatingVal, v[i1 - 1]);
                    operatingVal = &v[i1 - 1];
                }
                else goFlag = false;
                if (!goFlag) break;
            }
        }
    }
    break;
    default:        // Selection sort
        for (size_t i{ 0 }; i < v.size(); ++i)
        {
            std::swap(v[i], *(std::min_element(v.begin() + i, v.end())));
        }
    
    }
}