#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include "input.h"
#include <map>

using namespace std;

vector<int> generateRandomNumbers() {
    vector<int> randomList;
    srand(time(0));
    for (int i = 0; i < 1000000; i++)
        randomList.push_back(lrand48());
    return randomList;
}

vector<int> printDuplicate(vector<int> randomList)
{
    vector<int> duplicateVectorList;
    static unordered_set<int> s;
    for (int i = 0; i < randomList.size(); i++)
    {
        if (s.find(randomList[i]) != s.end())
        {
            duplicateVectorList.push_back(randomList[i]);
            cout << randomList[i] << "\n";
        }
        else
        {
            s.insert(randomList[i]);
        }
    }
    return duplicateVectorList;
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