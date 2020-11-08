#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>

using namespace std;

int main()
{
    int choice;
    std::string line;
    ifstream fin;
    ofstream fout;
    cout << ("\n--------------------------------\n");
    cout << (" Enter 1 to find GCD using Euclidean method \n ");
    cout << (" Enter 2 to find GCD using Extended Euclidean method \n ");
    cout << (" Enter 3 to find Multiplicative Inverse using Extended Euclidean method \n ");
    cout << (" Enter 5 to Exit \n");
    cout << ("\n--------------------------------\n");
    cout << " Enter your choice \n ";
    cin >> choice;
    fin.open("data.txt", ios::in);
    if (choice == 1)
    {
        int count;
        fout.open("output.txt", ios::out);
        getline(fin, line);
        std::istringstream my_stream(line);
        my_stream >> count;
    }
}