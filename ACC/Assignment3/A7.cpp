#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


float knapsackGreedy(vector<float> value, vector<float> weight, float max, float n);
float knapsackOpt(vector<float> value, vector<float> weight, float max, float n);
void result(float res);
int main()
{ 
  float max, n;
  vector<float> value, weight;
  cout<<"\nProgram for Ratio of greedy Fractional knapsack and optimal knapsack\n";
  cout<<"\nEnter the maximum capacity of knapsack:\n";
  cin>>max;
  cout<<"\nEnter the number of item: \n";
  cin>>n;
  cout<<"\nEnter the values of item,according to per unit value in descending order:\n";
  for(int i=0; i<n; i++)
  {
    float val = 0;
    cin >> val;
    value.push_back(val);
  }
  cout<<"Enter the values of weight according to value of item:\n";
  for(int i=0; i<n; i++)
  {
    float wt = 0;
    cin >> wt;
    weight.push_back(wt);
  }
  float optimalKS = knapsackOpt(value, weight, max, n);
  float greedyKS = knapsackGreedy(value, weight, max, n);
  result(optimalKS/greedyKS);
  return 0;

}

float knapsackGreedy(vector<float> value, vector<float> weight, float max, float n)
{ 
   float wtSum = 0, i = 0, rem;
   float valSum = 0;
    while((wtSum <= max) && (weight[i] <= max - wtSum))
    {   
        wtSum = wtSum + weight[i];
        valSum = valSum + value[i];
        i++;
    }
    rem=max-wtSum;
    if(wtSum < max)
    {
       wtSum = wtSum + rem;
       valSum = valSum + ((rem * value[i])/weight[i] );
    }
}

float knapsackOpt(vector<float> value, vector<float> weight, float max, float n) {
    vector<float> valDensity;
    for(int i =0; i < n; i++) {
        valDensity.push_back(value[i]/weight[i]);
    }
   float wtSum=0,i=0,rem;
   float valSum=0;
   int pos;
    while((wtSum <= max) && (weight[i] <= max-wtSum))
    {   pos = max_element(valDensity.begin(),valDensity.end()) - valDensity.begin();
        wtSum = wtSum + weight[pos];
        valSum = valSum + value[pos];
        valDensity[pos] = 0;
    }
    pos = max_element(valDensity.begin(),valDensity.end()) - valDensity.begin();
    rem = max - wtSum;
    if(wtSum<max)
    {
       wtSum = wtSum + rem;
       valSum = valSum + ((rem * value[pos])/weight[pos]);
    }

}

void result(float res) {
    cout << "Result 1 : " <<res << endl;
}