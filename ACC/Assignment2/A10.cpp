#include<iostream>
#include <chrono>
#include "input.h"

using namespace std;

void countSort(vector<int> arr, int size);
int Max(vector<int> array, int size);

int main(int argc, char *argv[]){
	int n;
    cout << "\nEnter size of array\n";
    cin >> n;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::nanoseconds elapsed_seconds;
    std::time_t end_time;
    vector<int> randNos = generateRandomNumbers(n);
    randNos = checkIfDuplicateAndRoundOff(randNos);
	
    cout << "\nCOUNTING SORT\n";
    start = chrono::high_resolution_clock::now();
	countSort(randNos, n);
    end = chrono::high_resolution_clock::now();
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
    elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        cout << "finished computation at " << std::ctime(&end_time)
             << "elapsed time: " << elapsed_seconds.count() << " ns\n"
             << endl;
	return 0;
}

void countSort(vector<int> arr, int size){
	int out[size+1];
	int max = Max(arr, size);
	int count[max+1];
	for(int i = 0; i<=max; i++)
		count[i] = 0;
	for(int i = 1; i <=size; i++)
		count[arr[i]]++;
	for(int i = 1; i<=max; i++)
		count[i] += count[i-1];
	for(int i = size; i>=1; i--){
		out[count[arr[i]]] = arr[i];
		count[arr[i]] -= 1;
	}
	for(int i = 1; i<=size; i++){
		arr[i] = out[i];
	}
}

int Max(vector<int> array, int size){
	int max = array[1];
		for(int i = 2; i<=size; i++){
			if(array[i] > max)
				max = array[i];
		}
	return max; 
}