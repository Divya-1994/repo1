#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> rates;
    int n, rate;
    cout << "\nEnter no of license\n";
    cin >> n;
    cout << "\nEnter rates\n";
    for(int i = 0; i < n; i++) {
        cin >> rate;
        rates.push_back(rate);
    }
    sort(rates.begin(), rates.end(), greater<int>());

    for(int i = 0; i < n; i++) {
        cout << rates[i] << " ";
    }

    cout << endl;
}