#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <ctime>
#include <chrono>
#include <map>
#include "input.h"

using namespace std;

vector<int> printDuplicates(vector<int> randomList);

int main()
{
    vector<int> randomList;

    // to generarte random numbers
    randomList = generateRandomNumbers();

    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double> elapsed_seconds;

    start = std::chrono::system_clock::now();

    vector<int> duplicateVectorList = printDuplicates(randomList);

    end = std::chrono::system_clock::now();

    elapsed_seconds = end - start;

    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time for printing duplicates: " << elapsed_seconds.count() << "s\n";

    if (!duplicateVectorList.empty())
    {
        start = std::chrono::system_clock::now();

        vector<int> outPutVector = checkIfDuplicateAndRoundOff(randomList);

        end = std::chrono::system_clock::now();

        elapsed_seconds = end - start;

        std::time_t end_time = std::chrono::system_clock::to_time_t(end);

        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time to round of duplicates: " << elapsed_seconds.count() << "s\n";
    }
}

vector<int> printDuplicates(vector<int> randomList)
{
    vector<int> duplicateList;
    static unordered_set<int> set;
    for (int i = 0; i < randomList.size(); i++)
    {
        if (set.find(randomList[i]) != set.end())
        {
            duplicateList.push_back(randomList[i]);
            cout << randomList[i] << "\n";
        }
        else
        {
            set.insert(randomList[i]);
        }
    }
    return duplicateList;
}