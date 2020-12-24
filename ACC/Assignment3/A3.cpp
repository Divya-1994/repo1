#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool cmp(pair<float, float>& a, pair<float, float>& b);

int main() {
    int n;
    vector<pair<float, float> > schedule; 
    cout << "\nClassroom scheduling problem\n";
    cout << "\nEnter Number of Schedule\n";
    cin >> n;
    cout << "\nEnter class interval\n";
    for(int i = 0; i < n; i++) {
        float start, end;
        cin >> start >> end;
        schedule.push_back(std::make_pair(start, end));
    }

    sort(schedule.begin(), schedule.end(), cmp);
     
    int count = 1;
    vector<pair<float, float>>::iterator it1, it2;
    for(int j = 0; j < n; j++) {
        it1 = schedule.begin();
        float end = (*it1).second;
        schedule.erase(it1);
        for (auto& it : schedule) { 
        if(it.first < end) {
            count++;
        }
    }
  }

  cout << "\nMinimum number of classroom required : "<< count << endl;
}

bool cmp(pair<float, float>& a, pair<float, float>& b) 
{ 
    return a.second < b.second; 
} 