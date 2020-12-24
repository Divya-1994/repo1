#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<float, float>& a, pair<float, float>& b);

int main() {
    cout << "\nActivity Selection Problem ON the basis of last Activity to start\n";
    vector<pair<float, float> > schedule;
    int n;
    cout << "\nEnter Number of Schedule\n";
    cin >> n;
    cout << "\nEnter job start and finish time pair\n";
    for(int i = 0; i < n; i++) {
        float start, end;
        cin >> start >> end;
        schedule.push_back(std::make_pair(start, end));
    }
    sort(schedule.begin(), schedule.end(), cmp);

    vector<pair<float, float>>::iterator it1, it2;
    cout << "\nActivities selected : \n";
    it1 = schedule.begin();
    float s = (*it1).first;
    float e = (*it1).second;
    cout << s <<" "<<e <<endl;
    schedule.erase(it1);
    for (auto& it : schedule) { 
     if(!((s <= it.first) && (it.first <= e)) && !((s <= it.second) && (it.second <= e))) {
           cout << it.first << " "<<it.second<<endl;
      }
    }
}

bool cmp(pair<float, float>& a, pair<float, float>& b) 
{ 
    return a.first > b.first; 
}