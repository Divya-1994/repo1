#include <iostream>
#include <vector>
#include <chrono>
#include "input.h"

using namespace std;

/*  count number of inversion */

void bruteForceTechnique(vector<int> input);
int mergeNcount(vector<int> arr, int array_size);
int mergeSort(vector<int> arr, int temp[], int left, int right);
int merge(vector<int> arr, int temp[], int left, int mid, int right);
long inv_count;
int main() {
    long n;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::milliseconds elapsed_seconds;
    std::time_t end_time;
    cout <<"\nEnter the size of array whose element will be random numbes\n";
    cin>>n;
    vector<int> randNumbers = generateRandomNumbers(n);
    randNumbers = checkIfDuplicateAndRoundOff(randNumbers);
    start = chrono::high_resolution_clock::now();
    bruteForceTechnique(randNumbers);
    cout << "\nTotal number of inversion using Brute Force " << inv_count <<endl;
    end = chrono::high_resolution_clock::now();
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
    elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "finished computation at " << std::ctime(&end_time)
             << "elapsed time: " << elapsed_seconds.count() << " ms\n"
             << endl;

    inv_count = 0;
    start = chrono::high_resolution_clock::now();
    inv_count = mergeNcount(randNumbers, randNumbers.size());
    cout << "\nTotal number of inversion using Merge Sort " << inv_count <<endl;
    end = chrono::high_resolution_clock::now();
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
    elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "finished computation at " << std::ctime(&end_time)
             << "elapsed time: " << elapsed_seconds.count() << " ms\n"
             << endl;

    return 0;
}

void bruteForceTechnique(vector<int> input) {
    for (int i = 0; i < (input.size()) - 1; i++) {
        for (int j = i + 1; j < input.size(); j++) {
            if (input[i] > input[j])
                inv_count++;
        }
    }
}

int mergeNcount(vector<int> arr, int array_size)
{
    int temp[array_size];
    return mergeSort(arr, temp, 0, array_size - 1);
}
 
int mergeSort(vector<int> arr, int temp[], 
                 int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        
        inv_count += mergeSort(arr, temp, 
                                left, mid);
        inv_count += mergeSort(arr, temp, 
                             mid + 1, right);
 
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, 
                           mid + 1, right);
    }
    return inv_count;
}
 
/*  returns inversion count in the arrays.*/
int merge(vector<int> arr, int temp[], int left,
          int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
 
    i = left;
    j = mid; 
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
 
    /* Copy the remaining elements of left subarray */
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    /* Copy the remaining elements of right subarray */
    while (j <= right)
        temp[k++] = arr[j++];
 
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

