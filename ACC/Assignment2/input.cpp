#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include "input.h"
#include <map>

using namespace std;

vector<int> generateRandomNumbers(int n) {
    vector<int> randomList;
    srand(time(0));
    for (int i = 0; i < n; i++)
        randomList.push_back(lrand48());
    return randomList;
}

vector<int> checkIfDuplicateAndRoundOff(vector<int> randomList)
{
    static map<int, int> elemFrequency;
    static vector<int> outputList;
    vector<int> tempVector;
    // Iterate over the vector and store the frequency of each element in map
    for (int elem : randomList)
    {
        if (elemFrequency.find(elem) != elemFrequency.end())
        {
            // if duplicate found then add 1 in element and check for duplicate
            tempVector.clear();
            tempVector.push_back(elem + 1);
            checkIfDuplicateAndRoundOff(tempVector);
        }
        else
        {
            elemFrequency.insert(std::pair<int, int>(elem, 1));
            outputList.push_back(elem);
        }
    }
    return outputList;
}