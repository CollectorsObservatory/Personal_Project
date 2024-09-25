#include <iostream>

using namespace std ; 

int main(){

    // Exemple 1

    int n = 10 ;
    int x = 0; 
    for (int i=0; i<n ; i++) {
        for (int j=0; j<n;j++) {
            x++; // Parm Baromètre
        }
    }
    if (x == 100) {cout << "Algorithm compexity O^2"<<endl;}
    cout << "---------------------------------------------------------" << endl;

    




    return 0;
}