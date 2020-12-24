#include <iostream>
#include <bits/stdc++.h>
#include <vector>


using namespace std;

bool cmp(pair<float, float>& a, pair<float, float>& b);
string getActualTime(float f);

int main() {
    vector<pair<float, float> > schedule;
    int n;
    cout << "\nActivity Selection using 24 hr Clock\n";
    cout << "\nEnter Number of schedule\n";
    cin >> n;
    cout << "\nEnter schedule pair wise eg 7AM 9PM\n";
    for(int i = 0; i < n; i++) {
        string start, end;
        float s,e;
        cin >> start >> end;
        if(start.find("PM") != std::string::npos) {
            s = stof(start.substr(0, start.find("PM")));
            s += 12;
            if(s == 24) {
                s = 0;
            }
        } else {
            s = stof(start.substr(0, start.find("AM")));
        }
        if(end.find("PM") != std::string::npos) {
            e = stof(end.substr(0, end.find("PM")));
            e += 12;
            if(e == 24) {
                e = 0;
            }
        } else {
            e = stof(end.substr(0, end.find("AM")));
        }
        schedule.push_back(std::make_pair(s, e));
    }

    sort(schedule.begin(), schedule.end(), cmp);

    vector<pair<float, float>>::iterator it1, it2;
    cout << "\nActivities selected : \n";
    it1 = schedule.begin();
    float s = (*it1).first;
    float e = (*it1).second;
    string str1 = getActualTime(s);
    string str2 = getActualTime(e);
    cout << str1 <<" "<< str2 <<endl;
    schedule.erase(it1);
    for (auto& it : schedule) { 
        //if(!((s <= it.first) && (it.first <= e)) && !((s <= it.second) && (it.second <= e))) {
            if(it.first > e) {
            str1 = getActualTime(it.first);
            str2 = getActualTime(it.second);
            cout << str1 << " "<< str2 <<endl;
            e = it.second;
        }
    }
}

bool cmp(pair<float, float>& a, pair<float, float>& b) 
{ 
    return a.second < b.second; 
} 

string getActualTime(float f) {
    string str1;
    if(f > 12) {
        f = f-12;
        str1 = to_string(f) + "PM";
    } else {
        str1 = to_string(f) + "AM";
    }
    return str1;
}