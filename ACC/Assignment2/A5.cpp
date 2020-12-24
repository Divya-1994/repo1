#include <iostream>
#include <vector>
#include <chrono>
#include "input.h"

using namespace std;

void quickSort(vector<int> &arr, int p, int r);
int medianOfThree(vector<int> &arr, int p, int r);
int partition (vector<int> &arr, int p, int r, int q);

int main() {
    int n = 10;;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::nanoseconds elapsed_seconds;
    std::time_t end_time;
    while(n > 0) {
        vector<int> randNumber = generateRandomNumbers(1024);
        randNumber = checkIfDuplicateAndRoundOff(randNumber);
        cout << "\nQuick Sort using MEDIAN OF THREE PARTITION\n";
        start = chrono::high_resolution_clock::now();
        quickSort(randNumber, 0, randNumber.size()-1);
        end = chrono::high_resolution_clock::now();
        end_time = std::chrono::high_resolution_clock::to_time_t(end);
        elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        cout << "finished computation at " << std::ctime(&end_time)
             << "elapsed time: " << elapsed_seconds.count() << " ns\n"
             << endl;
    // printing elements
    for(int i = 0; i<10; i++) {
        cout << randNumber[i]<<" ";
    }
    cout << endl << endl;
    n--;
    }

}

void quickSort(vector<int> &arr, int p, int r) {
    if (r > p)
    {
    int q = medianOfThree(arr, p, r);
    int res = partition(arr, p, r, q);
    quickSort(arr, p, res-1);
    quickSort(arr , res+1, r);
    }
}

int medianOfThree(vector<int> &arr, int p, int r)
{
    int mid = (p + r)/2;
    if (arr[p] > arr[mid]) swap(arr[p], arr[mid]);
    if (arr[mid] > arr[r]) swap(arr[mid], arr[r]);
    if (arr[p] > arr[mid]) swap(arr[p], arr[mid]);
    return mid;
}

int partition (vector<int> &arr, int p, int r, int q)  
{   
    swap(arr[q], arr[r]);
    int pivot = arr[r];
    int i = (p - 1);// Index of smaller element  
  
    for (int j = p; j <= r-1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(arr[i], arr[j]);  
        }  
    }  
    swap(arr[i + 1], arr[r]);  
    return (i+1);  
}  