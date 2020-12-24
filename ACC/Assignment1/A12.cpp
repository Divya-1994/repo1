#include <iostream> 
#include <cmath>
using namespace std; 

int *multiply(int A[], int B[], int m, int n);
int *mulUsingDnC(int p[], int q[], int m, int n);
void printPoly(int poly[], int n);

// Driver program to test above functions 
int main() 
{ 
    // The following array represents polynomial 5 + 10x^2 + 6x^3 
    int A[] = {5, 0, 10, 6}; 
  
    // The following array represents polynomial 1 + 2x + 4x^2 
    int B[] = {1, 2, 4}; 
    int m = sizeof(A)/sizeof(A[0]); 
    int n = sizeof(B)/sizeof(B[0]); 
  
    cout << "\nFirst polynomial is "; 
    printPoly(A, m); 
    cout << "\nSecond polynomial is "; 
    printPoly(B, n); 
  
    int *prod = multiply(A, B, m, n); 
  
    cout << "\nProduct polynomial By Brute Force is "; 
    printPoly(prod, m+n-1); 
    cout << endl;
    
    prod = mulUsingDnC(A, B, m, n);
    cout << "\nProduct polynomial By Divide n Conquer is ";
    printPoly(prod, (m*n)-1);
  
    return 0; 
} 
  

// m and n are sizes of A[] and B[] respectively 
int *multiply(int A[], int B[], int m, int n) 
{ 
   int *prod = new int[m+n-1]; 
  
   // Initialize the porduct polynomial 
   for (int i = 0; i<m+n-1; i++) 
     prod[i] = 0; 
  
   // Multiply two polynomials term by term 
   for (int i=0; i<m; i++) 
   { 
     for (int j=0; j<n; j++) 
         prod[i+j] += A[i]*B[j]; 
   } 
  
   return prod; 
}

int *mulUsingDnC(int p[], int q[], int m, int n) {
    if (n == 1 && m == 1) 
        {
            int *temp = new int[1];
            temp[1] = {p[0] * q[0]};
            return temp;
        }
        // dividing the problem to 'd' number of coefficients
        int d = m/2;
        int t = n/2;
        //split p and q into arrays that store low and high order terms respectively
        int pHigh[d];
        int qHigh[t];       
        int pLow[d-m%2];
        int qLow[t-n%2];
        
        // assigning the respective coefficients to low and high arrays of p and q
        for (int i = 0; i < d; i++) 
        {
            pHigh[i] = p[i+d];
            pLow[i] = p[i];
        }
        for (int i = 0; i < d; i++) 
        {
            qHigh[i] = q[i+t];
            qLow[i] = q[i];
        }
        
        
        // These are the 4 subproblems
        
        // The pLow.qLow part of the multiplication
        int *lowPQ = mulUsingDnC(pLow, qLow, d, t);  
        
        // the term in the addidtion, in the middle - pLow.qHigh
        int *lowPHighQ = mulUsingDnC(pLow, qHigh, d, t);
        
        // the other term in the addition in the middle - pHigh.gLow
        int *lowQHighP = mulUsingDnC(pHigh , qLow, d, t);
        
        // the last term pHigh.qHigh.x^n
        int *highPQ = mulUsingDnC(pHigh, qHigh , d, t);
        
        // the array that stores the product of the polynomials
        int *pq = new int[(m*n)-1];       
        
        // storing the collected values in the product array, refer description for more information
        for (int i = 0; i < n-1; i++) 
        {
            pq[i] += lowPQ[i];
            pq[i+d] += lowPHighQ[i] + lowQHighP[i];
            pq[i+(2*d)] += highPQ[i];
        }        
        //returning the product
        return pq;

}
  
// A utility function to print a polynomial 
void printPoly(int poly[], int n) 
{ 
    for (int i=0; i<n; i++) 
    { 
       cout << poly[i]; 
       if (i != 0) 
        cout << "x^" << i ; 
       if (i != n-1) 
       cout << " + "; 
    } 
} 
  
