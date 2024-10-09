#include <iostream>

using namespace std ; 
    int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}
  
int main(){

    // Exemple 1

    int n =  10;
    int x = 0; 
    for (int i=0; i<n ; i++) {
        for (int j=0; j<n;j++) {
            x++; // Parm Baromètre
        }
    }
    cout << "---------------------------------------------------------" << endl;
    if (x == 100) {cout << "Algorithm compexity O^2"<<endl;}
    cout << "---------------------------------------------------------" << endl;
    // Exemple 2
    int y = 0;
    for (int i=1; i<=n ; i*=2) { y++ ;
    if ( i==8){cout <<"complexity of log2(n)"<<endl;};}
    cout << "---------------------------------------------------------" << endl;
    // Exemple 3 - Recursivite
    cout<<factorial(5)<<endl;
    /*
    factorial(5)
      = 5 * factorial(4)
      = 5 * (4 * factorial(3))
      = 5 * (4 * (3 * factorial(2)))
      = 5 * (4 * (3 * (2 * factorial(1))))
      = 5 * (4 * (3 * (2 * 1)))   --> base case reached here
      = 120
    */
  

    




    return 0;
}