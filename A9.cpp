#include<time.h>
#include <iostream>
#include <math.h>
#include<stdlib.h>
#include<sstream>
#include "boost/dynamic_bitset/dynamic_bitset.hpp"
#include<cmath>
#include<bitset>
#include<string>

using namespace std;

int main() {
    int numofSwitch;
	cout << "enter number of switches[1-10] :";
	cin >> numofSwitch;
	string str1;
	dynamic_bitset < > inputtemp(numofSwitch, 0);
    while(inputtemp.count() > numofSwitch) {
        to_string(inputtemp, str1);
    }
}