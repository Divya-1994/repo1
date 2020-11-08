#include <iostream>
#include <stdio.h>
#include <sys/time.h>
#include <vector>
#include <map>
#include "input.h"

using namespace std;

int main() {
    vector<int> randomList;
    long timediff;
    struct timeval tpStart, tpend, now;

    randomList = generateRandomNumbers();

    gettimeofday(&tpStart, NULL);
    checkIfDuplicateAndRoundOff(randomList);
    gettimeofday(&tpend, NULL);

    timediff = 1000000*(tpend.tv_sec - tpStart.tv_sec) + tpend.tv_usec - tpStart.tv_usec;

    cout << "time difference " << timediff << " microseconds "<< endl;

}

