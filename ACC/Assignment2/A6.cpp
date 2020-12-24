#include <iostream>
#include <vector>
#include <chrono>
#include "input.h"

using namespace std;

void quickSort(vector<int> &arr, int low, int high);
int partition(vector<int> &arr, int low, int high);
void randPos(vector<int> &arr, int low, int high);

int main()
{
     int n = 10;;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::nanoseconds elapsed_seconds;
    std::time_t end_time;
    while(n > 0) {
        vector<int> randNumber = generateRandomNumbers(2048);
        randNumber = checkIfDuplicateAndRoundOff(randNumber);
        cout << "\nQuick Sort using PROBABILISTIC QUICKSORT\n";
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

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high) {
        randPos(arr, low, high);
        int pos = partition(arr, low, high);
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}
    

int partition(vector<int> &arr, int low, int high)
{
    // pivot
    int pivot = arr[high]; 
   
    // Index of smaller element
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 

void randPos(vector<int> &arr, int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    // Swap A[random] with A[high]
    swap(arr[random], arr[high]);
}
 


