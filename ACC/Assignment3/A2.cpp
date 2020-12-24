#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

/* Maximum revenue in billboard*/

int main() {
    int M, n, t, TotalRev = 0;
    float mile, revenue;
    map<int, int> mileRevPair;
    map<float, int> mileAvgPair;
    vector<float> revByWt;
    cout << "\nEnter maximum miles\n";
    cin >> M;
    cout << "\nEnter number of Billboard\n";
    cin >> n;
    cout << "\nEnter minimum distance between billboard\n";
    cin >> t;
    cout << "\nEnter billboard location and revenue pair wise\n";
    for(int i = 0; i < n; i++) {
        cin >> mile >> revenue;
        mileRevPair.insert(pair<int, int>(mile, revenue));
        float f = (revenue/mile);
        revByWt.push_back(f);
        mileAvgPair.insert(pair<float, int>(revenue/mile, mile));
    }
    int prevMile = 0;
    for(int i = 0; i < revByWt.size();) {
        //*max_element(revByWt.begin(), revByWt.end());
        vector<float> newVec = std::vector<float>(revByWt.begin() + i, revByWt.end());;
        copy(revByWt.begin() + i, revByWt.end(), newVec.begin());
        int pos = max_element(newVec.begin(),newVec.end()) - newVec.begin();
        mile = mileAvgPair[newVec[pos]];
        revenue = mileRevPair[mile];
        if(mile - prevMile >= t || i == 0) {
            TotalRev += revenue;
            prevMile = mile;
        }
        i = i + pos + 1;
    }

    cout << "\nMaximum revenue earned : " << TotalRev << endl;
    
}