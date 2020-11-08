#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <ctime>
#include <chrono>
#include "input.h"

using namespace std;

void insertionSort(vector<int> input, int n, int*swapCount);
void merge(vector<int> inputVector, int l, int m, int r, int* swapCount);
void mergeSort(vector<int> inputVector, int beg, int end, int* swapCount);
void quickSort(vector<int> inputVector, int low, int high, int*swapCount);
int partition (vector<int> inputVector, int low, int high, int* swapCount);
void heapSort(vector<int> inputVector, int n, int* swapCount);
void heapify(vector<int> inputVector, int n, int i, int* swapCount);
void swap(int a, int b, int* swapCout);

int main() {
    vector<int> inputVector;
    inputVector = generateRandomNumbers();
    
    inputVector = checkIfDuplicateAndRoundOff(inputVector);
    int swapCount = 0;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    cout << "COUNTING NUMBER OF SWAPS AND TIME ELAPSED ON UNSORTED DATA" << endl << endl;
    start = std::chrono::high_resolution_clock::now();
    insertionSort(inputVector, inputVector.size(), &swapCount);
    end = std::chrono::high_resolution_clock::now();
    cout << "Insertion Sort " << swapCount << endl;
    std::time_t end_time = std::chrono::high_resolution_clock::to_time_t(end);
    std::chrono::microseconds elapsed_seconds = std::chrono::duration_cast< std::chrono::microseconds >(end - start);
    cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time : " << elapsed_seconds.count() << " microsec\n" <<endl;
    swapCount = 0;

    start = std::chrono::high_resolution_clock::now();
    mergeSort(inputVector, 0, inputVector.size() - 1, &swapCount);
    end = std::chrono::high_resolution_clock::now();
    cout << "Merge Sort " << swapCount << endl;
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
    elapsed_seconds = std::chrono::duration_cast< std::chrono::microseconds >(end - start);
    cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << " microsec\n" << endl;
    swapCount = 0;

    start = std::chrono::high_resolution_clock::now();
    quickSort(inputVector, 0, inputVector.size() - 1, &swapCount);
    end = std::chrono::high_resolution_clock::now();
    cout << "Quick Sort " << swapCount << endl;
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
    elapsed_seconds = std::chrono::duration_cast< std::chrono::microseconds >(end - start);
    cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << " microsec\n" << endl;
    swapCount = 0;

    start = std::chrono::high_resolution_clock::now();
    heapSort(inputVector, inputVector.size(), &swapCount);
    end = std::chrono::high_resolution_clock::now();
    cout << "Heap Sort " << swapCount << endl;
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
    elapsed_seconds = std::chrono::duration_cast< std::chrono::microseconds >(end - start);
    cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << " microsec\n" <<endl<<endl;
    swapCount = 0;

    std::sort(inputVector.begin(), inputVector.end());

    cout << "COUNTING NUMBER OF SWAPS AND TIME ELAPSED ON SORTED DATA" << endl << endl;
    start = std::chrono::high_resolution_clock::now();
    insertionSort(inputVector, inputVector.size(), &swapCount);
    end = std::chrono::high_resolution_clock::now();
    cout << "Insertion Sort " << swapCount << endl;
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
    elapsed_seconds = std::chrono::duration_cast< std::chrono::microseconds >(end - start);
    cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << " microsec\n"<<endl;
    swapCount = 0;

    start = std::chrono::high_resolution_clock::now();
    mergeSort(inputVector, 0, inputVector.size() - 1, &swapCount);
    end = std::chrono::high_resolution_clock::now();
    cout << "Merge Sort " << swapCount << endl;
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
    elapsed_seconds = std::chrono::duration_cast< std::chrono::microseconds >(end - start);
    cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << " microsec\n"<<endl;
    swapCount = 0;

    start = std::chrono::high_resolution_clock::now();
    quickSort(inputVector, 0, inputVector.size() - 1, &swapCount);
    end = std::chrono::high_resolution_clock::now();
    cout << "Quick Sort " << swapCount << endl;
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
    elapsed_seconds = std::chrono::duration_cast< std::chrono::microseconds >(end - start);
    cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << " microsec\n"<<endl;
    swapCount = 0;
    
    start = std::chrono::high_resolution_clock::now();
    heapSort(inputVector, inputVector.size(), &swapCount);
    end = std::chrono::high_resolution_clock::now();
    cout << "Heap Sort " << swapCount << endl;
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
    elapsed_seconds = std::chrono::duration_cast< std::chrono::microseconds >(end - start);
    cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << " microsec\n" <<endl<<endl;

}

void insertionSort(vector<int> input, int n, int* swapCount)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = input[i];
        j = i - 1;

        while (j >= 0 && input[j] > key)
        {
            input[j + 1] = input[j];
            j = j - 1;
            (*swapCount)++;
        }
        input[j + 1] = key;
    }
}


void mergeSort(vector<int> inputVector, int beg, int end, int* swapCount) 
{  
    if (beg < end) 
    { 
          
        // Same as (l+r)/2, but avoids  
        // overflow for large l and h 
        int mid = beg + (end - beg) / 2; 
  
        // Sort first and second halves 
        mergeSort(inputVector, beg, mid, swapCount); 
        mergeSort(inputVector, mid + 1, end, swapCount); 
  
        merge(inputVector, beg, mid, end, swapCount); 
    }
} 

void merge(vector<int> inputVector, int l, int m, int r, int* swapCount) 
{ 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    // Create temp arrays  
    int L[n1], R[n2]; 
  
    // Copy data to temp arrays L[] and R[]  
    for(int i = 0; i < n1; i++) 
        L[i] = inputVector[l + i]; 
    for(int j = 0; j < n2; j++) 
        R[j] = inputVector[m + 1 + j]; 
  
    // Merge the temp arrays back into arr[l..r] 
      
    // Initial index of first subarray 
    int i = 0;  
      
    // Initial index of second subarray 
    int j = 0;  
      
    // Initial index of merged subarray 
    int k = l; 
      
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j])  
        { 
            inputVector[k] = L[i]; 
            i++; 
            (*swapCount)++;
        } 
        else 
        { 
            inputVector[k] = R[j]; 
            j++; 
            (*swapCount)++;
        } 
        k++; 
    } 
  
    // Copy the remaining elements of 
    // L[], if there are any  
    while (i < n1)  
    { 
        inputVector[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of 
    // R[], if there are any  
    while (j < n2) 
    { 
        inputVector[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void quickSort(vector<int> inputVector, int low, int high, int*swapCount) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(inputVector, low, high, swapCount); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(inputVector, low, pi - 1, swapCount); 
        quickSort(inputVector, pi + 1, high, swapCount); 
    } 
} 

int partition (vector<int> inputVector, int low, int high, int* swapCount) 
{ 
    int pivot = inputVector[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (inputVector[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(inputVector[i], inputVector[j], swapCount);
        } 
    } 
    swap(inputVector[i + 1], inputVector[high], swapCount); 
    return (i + 1); 
} 

void swap(int a, int b, int* swapCout) 
{ 
    int t = a; 
    a = b; 
    b = t; 
    (*swapCout)++;
}

void heapSort(vector<int> inputVector, int n, int* swapCount) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(inputVector, n, i, swapCount); 
  
    // One by one extract an element from heap 
    for (int i = n - 1; i >= 0; i--) { 
        // Move current root to end 
        swap(inputVector[0], inputVector[i], swapCount); 
  
        // call max heapify on the reduced heap 
        heapify(inputVector, i, 0, swapCount); 
    } 
} 


void heapify(vector<int> inputVector, int n, int i, int* swapCount) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && inputVector[l] > inputVector[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && inputVector[r] > inputVector[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) { 
        swap(inputVector[i], inputVector[largest], swapCount); 
  
        // Recursively heapify the affected sub-tree 
        heapify(inputVector, n, largest, swapCount); 
    } 
}