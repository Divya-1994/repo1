#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include<chrono>

using namespace std;
using namespace std::chrono;

void printArrayElement(vector< vector<int>> &matrix, int m, int n);
void multiplyUsingBruteForce(vector<vector<int>> &A, vector<vector<int>> &B, int m, int n, int a, int b);
bool checkIfValidMul(int n, int a);

int main()
{
    int m, n, a, b;
    cout << "Matrix Multiplication using Brute force" << endl;
    cout << "Enter rows and columns of first matrix" << endl;
    cin >> m >> n;
    vector<vector<int>> A;
    //first matrix input
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int i=rand()%10;
            //cin >> i;
            temp.push_back(i);
        }
        A.push_back(temp);
    }
    cout<<"Matrix values are : "<<endl;
    
    printArrayElement(A,m,n);
    
    cout << "Enter rows and columns of second matrix" << endl;
    cin >> a >> b;
    vector<vector<int>> B;
    //second matrix input
    for (int i = 0; i < a; i++)
    {
        vector<int> temp;
        for (int j = 0; j < b; j++)
        {
            int i=rand()%10;
            //cin >> i;
            temp.push_back(i);
        }
        B.push_back(temp);
    }
    cout<<"Matrix values are : "<<endl;

    printArrayElement(B,a,b);

    auto start = high_resolution_clock::now();
         	
    bool check = checkIfValidMul(n, a);
    if (check)
    {
        multiplyUsingBruteForce(A, B, m, n, a, b);
    }
    else
    {
        cout << "martrix multiplication not possible";
    }
    auto stop = high_resolution_clock::now();
    auto duration_micro = duration_cast<microseconds>(stop - start);
    auto duration_seconds = duration_cast<seconds>(stop - start);

    cout << "Time taken by function (microseconds): "<< duration_micro.count() << " microseconds" << endl;
    cout << "Time taken by function (seconds): "<< duration_seconds.count() << " seconds" << endl<< endl;

    return 0;
}

void printArrayElement(vector< vector<int>> &matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != 0)
            {
                cout << "\t";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void multiplyUsingBruteForce(vector<vector<int>> &A, vector<vector<int>> &B, int m, int n, int a, int b)
{  
    vector<vector<int>> res;
    int i, j, k;
    for (i = 0; i < m; i++) {
        vector<int> temp;
        for (j = 0; j < b; j++) {
            temp.push_back(0);
            for (k = 0; k < n; k++) {
                temp.at(j) += A[i][k] * B[k][j];
            }
        }
        res.push_back(temp);
}
    cout<<"Matrix Multiplication : "<<endl;
    printArrayElement(res, m, b);
}

bool checkIfValidMul(int n, int a)
{
    if (n == a)
        return true;
    else
        return false;
}