#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "\n0/1 Knapsack with increasing weight and decreasing value\n";
    int n, max;
    vector<pair<float, float> > wtValuePair;
    cout << "\nEnter number of wt value pair\n";
    cin >> n;
    cout << "\nEnter capacity of Knapsack\n";
    cin >> max;
    cout << "\nEnter weight - value pair such that maximum weight has minimum value\n";
    for(int i = 0; i < n; i++) {
        float wt, val;
        cin >> wt >> val;
        wtValuePair.push_back(make_pair(wt, val));
    }
    float wtSum = 0;
    float valSum = 0;
    vector<pair<float, float>>::iterator it;
    it = wtValuePair.begin();
    while((wtSum <= max) && ((*it).first <= max-wtSum)) {
        wtSum = wtSum + (*it).first;
        valSum = valSum + (*it).second;
        it++;
    }

    cout << "Total Value Earned : " << valSum << endl;

}