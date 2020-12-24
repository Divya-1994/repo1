#include <iostream>
#include <vector>
#include <chrono>
#include "input.h"

using namespace std;

void quickSort(vector<int> randNos, int p, int r);
size_t Partition(vector<int> randNos, int p, int r);
void quickSort_text(vector<int> randNos, int p, int r);
size_t Partition_text(vector<int> randNos, int p, int r);

int main() {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::nanoseconds elapsed_seconds;
    std::time_t end_time;
    vector<int> randNos = generateRandomNumbers(2048);
    randNos = checkIfDuplicateAndRoundOff(randNos);
    cout << "\nQuick Sort with pivot as first element\n";
    start = chrono::high_resolution_clock::now();
    quickSort(randNos, 0, randNos.size());
    end = chrono::high_resolution_clock::now();
        end_time = std::chrono::high_resolution_clock::to_time_t(end);
        elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        cout << "finished computation at " << std::ctime(&end_time)
             << "elapsed time: " << elapsed_seconds.count() << " ns\n"
             << endl;

    cout << "\nQuick Sort with pivot as last element (As in text)\n";
    start = chrono::high_resolution_clock::now();
    quickSort_text(randNos, 0, randNos.size());
    end = chrono::high_resolution_clock::now();
        end_time = std::chrono::high_resolution_clock::to_time_t(end);
        elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        cout << "finished computation at " << std::ctime(&end_time)
             << "elapsed time: " << elapsed_seconds.count() << " ns\n"
             << endl;

}

void quickSort(vector<int> randNos, int p, int r)
{
  if (r - p > 1)
  {
    int q = Partition(randNos, p, r);
    quickSort(randNos, p, q);
    quickSort(randNos , q+1, r);
  }
}

size_t Partition(vector<int> randNos, int p, int r)
{
  int i = p;
  for (int j = p; j < r-1; ++j)
  {
    if (randNos[j] <= randNos[r-1])
    {
      swap(randNos[i], randNos[j]);      
      ++i;
    }
  }
  // the last place requires no test:
  swap(randNos[i], randNos[r-1]);
  return i;
}

void quickSort_text(vector<int> randNos, int p, int r)
{
  if (r - p > 1)
  {
    int q = Partition(randNos, p, r);
    quickSort(randNos, p, q);
    quickSort(randNos , q+1, r);
  }
}

size_t Partition_text(vector<int> randNos, int p, int r)
{
  int i = r;
  for (int j = p; j < r-1; ++j)
  {
    if (randNos[j] <= randNos[r-1])
    {
      swap(randNos[i], randNos[j]);      
      ++i;
    }
  }
  // the last place requires no test:
  swap(randNos[i], randNos[r-1]);
  return i;
}