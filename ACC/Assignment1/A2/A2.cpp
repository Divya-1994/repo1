#include <stdio.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <map>
#include "input.h"

using namespace std;

int main()
{
  vector<int> randomList;
  srand(time(0));

  // to generarte random numbers
  randomList = generateRandomNumbers();

  std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

  start = std::chrono::high_resolution_clock::now();

  vector<int> duplicateVectorList = printDuplicate(randomList);

  end = std::chrono::high_resolution_clock::now();

  std::time_t end_time = std::chrono::high_resolution_clock::to_time_t(end);

  std::chrono::microseconds elapsed_seconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  cout << "finished computation at " << std::ctime(&end_time)
       << "elapsed time for printing duplicates: " << elapsed_seconds.count() << " microsec\n";

  if (!duplicateVectorList.empty())
  {
    start = std::chrono::system_clock::now();

    checkIfDuplicateAndRoundOff(randomList);

    end = std::chrono::system_clock::now();

    //elapsed_seconds = end - start;

    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::chrono::microseconds elapsed_seconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time to round of duplicates: " << elapsed_seconds.count() << " microsec\n";
  }
}
