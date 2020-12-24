#include<iostream>
#include <chrono>
#include<time.h>
#include <math.h>
#include<stdlib.h>
#include<sstream>
#include "boost/dynamic_bitset/dynamic_bitset.hpp"
#include<cmath>
#include<bitset>
#include<string>

using namespace std;
using namespace boost;
//-------------------------------------------------------------------------------------
int btod(int);
string gtob(string);
string btog(string);
int main(int argc, char ** argv) {
	int numofbulb;
	cout << "enter number of switches[1-10] :";
	cin >> numofbulb;
	string str1;
	string str2;
	dynamic_bitset < > inputtemp(numofbulb, 0);
	while(inputtemp.count() > numofbulb) {
        to_string(inputtemp, str1);
		string gray1 = btog(str1);
		int next = btod(stoll(str1)) + 1;
		dynamic_bitset < > nextInput(numofbulb, next);
		to_string(nextInput, str2);
		string gray2 = btog(str2);
		int len1 = gray1.length();
		int len2 = gray2.length();
		while(len1 != 0 && len2 != 0) {
			if(gray1.at(len1) != gray2.at(len2)) {
				cout << len1;
			} else {
				len1--;
				len2--;
			}
		}

    }
	
}


char xor_c(char a, char b) {
	return (a == b) ? '0' : '1';
}
char flip(char c) {
	return (c == '0') ? '1' : '0';
}
string btog(string binary) {
	string gray = "";

	gray += binary[0];

	for (int i = 1; i < binary.length(); i++) {
		gray += xor_c(binary[i - 1], binary[i]);
	}

	return gray;
}
string gtob(string gray) {
	string binary = "";

	binary += gray[0];

	for (int i = 1; i < gray.length(); i++) {
		if (gray[i] == '0')
		binary += binary[i - 1];

		else
		binary += flip(binary[i - 1]);
	}

	return binary;
}
int btod(int n) {
	int num = n;
	int dec_value = 0;

	int base = 1;

	int temp = num;
	while (temp) {
		int last_digit = temp % 10;
		temp = temp / 10;

		dec_value += last_digit * base;

		base = base * 2;
	}

	return dec_value;
}