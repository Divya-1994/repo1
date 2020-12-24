#include <iostream>
#include <vector>

using namespace std;


int main() {

    cout << "\nKnapsack implementation on same weight items\n";
    vector<int> profits;
    int weight, capacity, N;
    cout << "\nEnter capacity of knapsack\n";
    cin >> capacity;
    cout << "\nEnter weight\n";
    cin >> weight;
    cout << "\nEnter no of items entered in knapsack\n";
    cin >> N;
    cout << "\nEnter profits for each item\n";
    int profit;
    for(int i = 0; i< N ; i++) {
        cin >> profit;
        profits.push_back(profit);
    }
    int limit = capacity/weight;
    if(limit > N) {
        limit = N;
    }

    cout << "\nThe objects of knapsack resulting in maximum profit are :- " << "\n\n";

    int size = N;
    for(int i = 0; i < limit; i++) {
        for(int j = 0; j < size; j++) {
           if(profits[j] > profits[j+1]) {
               swap(profits[j], profits[j+1]);
           }
        }
        cout << profits[size] << " ";
        size = size - 1;
    }

    cout << endl;
        
}