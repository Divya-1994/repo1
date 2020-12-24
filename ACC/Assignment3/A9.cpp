#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << "\n Building tower within range of 4 miles of each home\n";
    int n, range;
    vector<int> miles;
    cout << "\nEnter total number of homes along east-west line\n";
    cin >> n;
    cout << "\nEnter range of tower\n";
    cin >> range;
    cout << "\nEnter distances between homes\n";
    for(int i = 0; i < n; i++) {
        int mile;
        cin >> mile;
        miles.push_back(mile);
    }
     // first we sort the house numbers 
    sort(miles.begin(), miles.end()); 
  
    // for count number of twoers 
    int numOfTower = 0; 
  
    // for iterate all houses 
    int i = 0; 
    while (i < n) { 
        numOfTower++;
        int loc = miles[i] + range; 
        while (i < n && miles[i] <= loc) 
            i++; 

        --i; 
        loc = miles[i] + range; 
        while (i < n && miles[i] <= loc) 
            i++; 
    } 
    cout <<"\nTotal Number of Towers : " << numOfTower <<endl; 
}