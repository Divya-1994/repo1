#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <chrono>
#include "input.h"

using namespace std;

void addEdge(list<int> adj[], int v1, int v2);
void visitedAssociation(list<int> adj[], int n);
void topologicalSort(int v, bool visited[], stack<int> &Stack, list<int> adj[]);

int main() {
   int n, e;
   int v1, v2;
   list<int> adj[n]; 
   std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
   std::chrono::nanoseconds elapsed_seconds;
   std::time_t end_time;
   cout<< "\nenter number of Vertices\n";
   cin>>n;
   cout << "\nEnter number of edges\n";
   cin >>e;
   cout << "\nEnter pair wise edges eg: 1 2 for edge between vertex 1 and 2\n";
   int count = e;
   while(count != 0) {
      cin >> v1 >> v2;
      addEdge(adj, v1, v2);
      count--;
   }
   cout << "\nTOPOLOGICAL SORTING\n";
   start = chrono::high_resolution_clock::now();
   visitedAssociation(adj, n);
   end = chrono::high_resolution_clock::now();
   end_time = std::chrono::high_resolution_clock::to_time_t(end);
   elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
   cout << "\nfinished computation at " << std::ctime(&end_time)
             << "elapsed time: " << elapsed_seconds.count() << " ns\n"
             << endl;

   return 0;
}

void addEdge(list<int> adj[], int v1, int v2){
    adj[v1].push_back(v2);
}

void visitedAssociation(list<int> adj[], int n) {
   stack<int> Stack;
   bool *visited = new bool[n];
   //Mark all the vertices which are not visited.
   for (int i = 0; i < n; i++)
      visited[i] = false;
      for (int i = 0; i < n; i++)
         if (visited[i] == false)
            topologicalSort(i, visited, Stack, adj);
         while (Stack.empty() == false) {
            cout << Stack.top() << " "; //print the element
            Stack.pop();
         }
}


void topologicalSort(int v, bool visited[], stack<int> &Stack, list<int> adj[]) {
   visited[v] = true; //mark current node as visited
   list<int>::iterator i;
   //Recur for all the vertices adjacent to this vertex.
   for (i = adj[v].begin(); i != adj[v].end(); ++i)
      if (!visited[*i])
         topologicalSort(*i, visited, Stack, adj);
         Stack.push(v);
}