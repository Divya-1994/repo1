#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
using namespace std;

void setOrder(string key);
string encrypt(string plainText);
string decrypt(string cypher);

string const key = "COLUMNAR";  
map<int,int> keyMap;

int main() {

    string plainText;
    int choice;
    string cypher;
    ifstream fin;
    ofstream fout;
    while(true) {
        cout << ("\n--------------------------------\n");
        cout << (" Enter 1 to generate Encrypted text \n ");
        cout << (" Enter 2 to generate Decrypted text \n ");
        cout << (" Enter 3 to Exit \n");
        cout << ("\n--------------------------------\n");
        cout << " Enter your choice \n ";
        cin >> choice;

        if(choice == 1) {
            fin.open("ICS/input.txt", ios::in);
            fout.open("ICS/output.txt", ios::out);
            if(fin) {
                ostringstream ss;
                ss << fin.rdbuf();
                plainText = ss.str();
            }
            if(!plainText.empty()) {
                setOrder(key);
                cypher = encrypt(plainText);
                fout << cypher;
                cout << "\nText encrypted Successfully\n";
            } else {
                cout << "\nNo input given to encrypt\n";
            }
           
        } else if(choice == 2) {
            fin.open("ICS/output.txt", ios::in);
            if(fin) {
                    ostringstream ss;
                    ss << fin.rdbuf();
                    cypher = ss.str();
                }
            if(!cypher.empty()) {
                fout.open("ICS/decrypt.txt", ios::out);
                string msg = decrypt(cypher);
                fout << msg;
                if(msg == plainText) {
                    cout << "\ncypher decrypted successfully\n";
                }
            } else {
                cout << "\nNo cypher given to decrypt\n";
            }
        } else if(choice == 3) {
            break;
        } else {
            cout << "\nWrong choice entered\n";
            break;
        }
        fin.close();
        fout.close();
    }


}


void setOrder(string key) {
    for(int i=0; i < key.length(); i++) 
    { 
        keyMap[key[i]] = i; 
    } 
}

string encrypt(string plainText) {
    int row,col,j; 
    string cipher = ""; 
      
    /* calculate column of the matrix*/
    col = key.length();  
      
    /* calculate Maximum row of the matrix*/
    row = plainText.length()/col;  
      
    if (plainText.length() % col) 
        row += 1; 
  
    char array[row][col]; 
  
    for (int i=0,k=0; i < row; i++) 
    { 
        for (int j=0; j<col; ) 
        { 
            if(plainText[k] == '\0') 
            { 
                /* Adding the padding character '_' */
                array[i][j] = '_';      
                j++; 
            } 

            if(plainText[k] == '\n') {
                array[i][j] = '%';      
                j++;
            }
              
            if( isalpha(plainText[k]) || plainText[k]==' ') 
            {  
                /* Adding only space and alphabet into matrix*/
                array[i][j] = plainText[k]; 
                j++; 
            } 
            k++; 
        } 
    } 
  
    for (map<int,int>::iterator ii = keyMap.begin(); ii!=keyMap.end(); ++ii) 
    { 
        j=ii->second; 
          
        // getting cipher text from matrix column wise using permuted key 
        for (int i=0; i<row; i++) 
        { 
            if( isalpha(array[i][j]) || array[i][j]==' ' || array[i][j]=='_') 
                cipher += array[i][j]; 
        } 
    } 
  
    return cipher; 
}

string decrypt(string cypher) {
     /* calculate row and column for cipher Matrix */
    int col = key.length(); 
  
    int row = cypher.length()/col; 
    char cipherMat[row][col]; 
  
    /* add character into matrix column wise */
    for (int j=0,k=0; j<col; j++) 
        for (int i=0; i<row; i++) 
            cipherMat[i][j] = cypher[k++]; 
  
    /* update the order of key for decryption */
    int index = 0; 
    for( map<int,int>::iterator ii=keyMap.begin(); ii!=keyMap.end(); ++ii) 
        ii->second = index++; 
  
    /* Arrange the matrix column wise according  
    to permutation order by adding into new matrix */
    char decCipher[row][col]; 
    map<int,int>::iterator ii=keyMap.begin(); 
    int k = 0; 
    for (int l=0,j; key[l]!='\0'; k++) 
    { 
        j = keyMap[key[l++]]; 
        for (int i=0; i<row; i++) 
        { 
            decCipher[i][k]=cipherMat[i][j]; 
        } 
    } 
  
    /* getting Message using matrix */
    string msg = ""; 
    for (int i=0; i<row; i++) 
    { 
        for(int j=0; j<col; j++) 
        { 
            if(decCipher[i][j] != '_')
                if(decCipher[i][j] == '%') {
                    msg += '\n';
                } else {
                    msg += decCipher[i][j];
                } 
        } 
    } 
    return msg; 
}