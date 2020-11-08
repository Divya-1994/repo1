#include <iostream>
#include <fstream>
using namespace std;

void makeInput(string plainText, size_t len, string *nmsg);
void createTable(string key, char arr[5][5]);
string encryptORDecryptMessage(string *plainText, char arr[5][5], int dir);
char getChar(int a, int b, char arr[5][5]);

int main()
{
    ifstream fin;
    ofstream fout;
    char arr[5][5];
    int choice;
    string key, plainText;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    fin >> key;
    fin >> plainText;
    string nmsg = "";
    string changedTxt = "";
    size_t len = plainText.length();
    //key.append("abcdefghiklmnopqrstuvwxyz");

    while (true)
    {
        cout << ("\n--------------------------------\n");
        cout << (" Enter 1 to generate Encrypted text \n ");
        cout << (" Enter 2 to generate Decrypted text \n ");
        cout << (" Enter 3 to Exit \n");
        cout << ("\n--------------------------------\n");
        cout << " Enter your choice \n ";
        cin >> choice;
        char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                             'h', 'i', 'j', 'k', 'l', 'm', 'n',
                             'o', 'p', 'q', 'r', 's', 't', 'u',
                             'v', 'w', 'x', 'y', 'z'};

        string res = "";
        char ch;
        //generate random string of alphabets
        while(res.length() != 26) {
            ch = alphabet[rand() % 26];
            if(res.find(ch) == -1) {
                res += ch;
            }
        }

        key.append(res);

        if (choice == 1)
        {
            createTable(key, arr);
            makeInput(plainText, len, &nmsg);
            changedTxt = encryptORDecryptMessage(&nmsg, arr, 1);
            fout << "\nEncrypted text\n"
                 << changedTxt << endl;
        }
        else if (choice == 2)
        {
            createTable(key, arr);
            makeInput(plainText, len, &nmsg);
            changedTxt = encryptORDecryptMessage(&nmsg, arr, -1);
            fout << "\nDecrypted text\n"
                 << changedTxt << endl;
        }
        else if (choice == 3)
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

void createTable(string key, char arr[5][5])
{
    string s = "";
    for (string::iterator it = key.begin(); it != key.end(); it++)
    {
        *it = toupper(*it);
        if (*it < 65 || *it > 90)
            continue;
        if (s.find(*it) == -1)
            s += *it;
    }
    copy(s.begin(), s.end(), &arr[0][0]);
}

void makeInput(string plainText, size_t len, string *nmsg)
{
    if (len % 2 != 0)
    {
        plainText += 'X';
    }
    for (size_t x = 0; x < len; x++)
    {
        *nmsg += plainText.at(x);
        if (x % 2 != 0)
        {
            *nmsg += " ";
        }
    }
    plainText = *nmsg;
}

bool getPosition(char l, int &c, int &d, char arr[5][5])
{ //get the position
    if (toupper(l) == 'J')
    {
        l = 'i';
    }
    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++)
            if (char(arr[y][x]) == toupper(l))
            {
                c = x;
                d = y;
                return true;
            }
    return false;
}

string encryptORDecryptMessage(string *plainText, char arr[5][5], int dir)
{
    int j, k, p, q;
    string encryptedMsg;
    for (string::const_iterator it = (*plainText).begin(); it != (*plainText).end(); it++)
    {
        if (!isspace(*it))
        {
            if (getPosition(*it, j, k, arr))
            {
                if (getPosition(*(++it), p, q, arr))
                {
                    //for same row
                    if (j == p)
                    {
                        encryptedMsg += getChar(j, k + dir, arr);
                        encryptedMsg += getChar(p, q + dir, arr);
                    }
                    //for same column
                    else if (k == q)
                    {
                        encryptedMsg += getChar(j + dir, k, arr);
                        encryptedMsg += getChar(p + dir, q, arr);
                    }
                    else
                    {
                        encryptedMsg += getChar(p, k, arr);
                        encryptedMsg += getChar(j, q, arr);
                    }
                }
            }
        }
    }
    return encryptedMsg;
}

char getChar(int a, int b, char arr[5][5])
{ //get the characters
    return tolower(arr[(b + 5) % 5][(a + 5) % 5]);
}