#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

// declare functions
void isValid(ifstream &fin, ofstream &fout);
void encryptText(ifstream &fin, ofstream &fout, char ch, int key);
void preProcessFile(ifstream &fin, ofstream &fout);
void decryptText(ifstream &fin, ofstream &fout, char ch, int key);
void decryptUsingBruteForce(ifstream &fin, ofstream &fout, char ch, int key);
void decryptUsingFrequencyMethod(ifstream &fin, ofstream &fout, char ch);

int main()
{
    ifstream fin;
    ofstream fout;
    // convert each upper case letter to lower case
    preProcessFile(fin, fout);

    while (true)
    {
        int choice;
        char ch;
        int key = 3;
        cout << ("\n--------------------------------\n");
        cout << (" Enter 1 to generate Encrypted file \n ");
        cout << (" Enter 2 to generate Decrypted file \n ");
        cout << (" Enter 3 to apply Brute Force Method on file \n ");
        cout << (" Enter 4 to apply Brute Frequency Analysis on file \n ");
        cout << (" Enter 5 to Exit \n");
        cout << ("\n--------------------------------\n");
        cout << " Enter your choice \n ";
        cin >> choice;

        if (choice == 1)
        {
            // encrypt given input file
            fin.open("input.txt", ios::in);
            fout.open("encrypted.txt", ios::out);
            isValid(fin, fout);
            encryptText(fin, fout, ch, key);
            cout<< " file succesfully encrypted ";
        }
        else if (choice == 2)
        {
            // decrypt given encrypted file
            fin.open("encrypted.txt", ios::in);
            fout.open("decrypted.txt", ios::out);
            isValid(fin, fout);
            decryptText(fin, fout, ch, key);
             cout<< " file succesfully decrypted using shared key";
        }
        else if (choice == 3)
        {
            decryptUsingBruteForce(fin, fout, ch, key);
             cout<< " file succesfully decrypted using Brute Force";
        }
        else if (choice == 4)
        {
            fin.open("encrypted.txt", ios::in);
            decryptUsingFrequencyMethod(fin, fout, ch);
             cout<< " file succesfully decrypted using frequency method";
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << " choice entered is incorrect ";
            break;
        }
    }
}

void encryptText(ifstream &fin, ofstream &fout, char ch, int key)
{
    string encryp_text = "";
    while (fin)
    {
        fin.get(ch);
        if (ch >= 97 && ch <= 122)
        {
            ch = ch - 97;
            encryp_text += char(((ch + key) % 26) + 97);
        }
        else
        {
            encryp_text += char(ch);
        }
    }
    fout << encryp_text << endl;
    fin.close();
    fout.close();
}

void preProcessFile(ifstream &fin, ofstream &fout)
{
    cout << (" Preprocessing of file started \n");
    fin.open("text.txt", ios::in);
    fout.open("input.txt", ios::out);

    isValid(fin, fout);
    char ch;
    while (fin)
    {
        if (fin.get(ch) && isupper(ch))
        {
            ch += 32;
        }
        fout.put(ch);
    }
    fin.close();
    fout.close();
}

void decryptText(ifstream &fin, ofstream &fout, char ch, int key)
{
    string decryp_text = "";
    while (fin)
    {
        fin.get(ch);
        if (ch >= 97 && ch <= 122)
        {
            ch = ch - 97 - key;
            if (ch < 0)
            {
                ch = ch + 26;
            }
            decryp_text += char((ch % 26) + 97);
        }
        else
        {
            decryp_text += char(ch);
        }
    }
    fout << decryp_text << endl;
    fin.close();
    fout.close();
}

void decryptUsingBruteForce(ifstream &fin, ofstream &fout, char ch, int key)
{
    int falseKey;
    cout << " Enter key ";
    cin >> falseKey;
    int count = 0;
    while (falseKey >= count)
    {
        string fileName = "probe" + std::to_string(count) + ".txt";
        fin.open("encrypted.txt", ios::in);
        fout.open(fileName, ios::out);
        isValid(fin, fout);
        decryptText(fin, fout, ch, count);
        count++;
    }
}

void decryptUsingFrequencyMethod(ifstream &fin, ofstream &fout, char ch)
{
    int arr[26] = {0};
    while (fin)
    {
        fin.get(ch);
        if (ch >= 97 && ch <= 122)
        {
            ch = ch - 97;
            arr[ch] += 1;
        }
    }
    fin.close();
    int max = arr[0];
    char pos = 0;
    for (int i = 1; i < 26; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            pos = i;
        }
    }
    pos = pos + 97;
    cout << char(pos) << " occur " << max << " times" << endl;
    int key_e = pos > 101 ? pos - 101 : 101 - pos;
    fin.open("encrypted.txt", ios::out);
    fout.open("decryptes_e.txt", ios ::out);
    decryptText(fin, fout, ch, key_e);
    int key_i = pos > 105 ? pos - 105 : 105 - pos;
    fin.open("encrypted.txt", ios::out);
    fout.open("decryptes_i.txt", ios ::out);
    decryptText(fin, fout, ch, key_i);
    int key_a = pos - 97;
    fin.open("encrypted.txt", ios::out);
    fout.open("decryptes_a.txt", ios ::out);
    decryptText(fin, fout, ch, key_a);
}

void isValid(ifstream &fin, ofstream &fout)
{
    if (!fout || !fin)
    {
        cout << "Error in Opening file";
    }
}