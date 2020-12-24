#include <iostream>
#include <vector>

using namespace std;

int main() {
    float totalDistance, n;
    vector<float> distances;
    cout << "\nMinimize Number of STOP travelling from Jammu to Delhi\n";
    cout << "\nEnter Total Distances that could be covered\n";
    cin  >> totalDistance;
    cout << "\nEnter total count of Petrol Pump\n";
    cin >> n;
    cout << "\nEnter distances between Gas Tank\n";
    for(int i = 0; i < n; i++) {
        int d;
        cin >> d;
        distances.push_back(d);
    }
    int count = 0;
    float sum = 0.0;
    cout << "\nGas Tank position at which need to stop\n";
    for(int j = 0; j < n; j++) {
        if(totalDistance - sum >= distances[j])
            sum += distances[j];
        else {
            cout << j << " ";
            sum = 0;
            count++;
        }
    }
    cout << "\n\nTotal Minimum Number Of Stops : "<< count <<endl << endl;
}