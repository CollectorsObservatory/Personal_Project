#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <functional>


using namespace std;

/*
Template implementation
*/
template <typename X, typename Y>

class Remix{

    private :
    X first_obj;
    Y second_obj;

    public:
    Remix(X fo, Y so) : first_obj(fo), second_obj(so)
    {cout <<"objet created" << endl;} ;

    void display_mix() {
        cout << "first object is " << first_obj << endl;
        cout << "Second object is " << second_obj << endl;

    }
    ~Remix() {cout << "object destroyed" <<endl;} ;




};

/*
Implementation d une classe qui respecte les bonne pratiques
en termes de la regle de 5 copliens
*/

class Voiture {

    private:

    string brand_name ;
    int n_km;

    public :


    Voiture () : brand_name("Unknown") , n_km(0) {}


    Voiture(string bn, int n) :
    brand_name(bn), n_km(n) {}


    Voiture(const Voiture& autre) {
        brand_name = autre.brand_name ;
        n_km = autre.n_km ; }

    Voiture(Voiture&& autre){
        brand_name = move(autre.brand_name);
        n_km = autre.n_km;}



    Voiture& operator=(const Voiture& autre) {
        if(this != &autre) {
            brand_name = autre.brand_name ;
            n_km = autre.n_km ;
        }
        return *this ; // this c un pointeur a l obj courant, * pour le passer par ref
    }

    Voiture& operator=(const Voiture&&autre) {
        if(this != &autre) {
            brand_name = move(autre.brand_name) ;
            n_km = autre.n_km ;}
        return *this ; // this c un pointeur a l obj courant, * pour le passer par ref
    }

    ~Voiture(){}

};


int main() {


    // Remix <string, int> test_obj("fares", 21) ;

    Voiture f_car; //defaut
    Voiture s_car("toyota", 1500); // base
    Voiture t_car; // defaut
    t_car = s_car; //op=
    Voiture fo_car = s_car; //copie
    Voiture x_car; // defaut
    x_car = move(f_car); // op= dep

   vector <int> numbers = {10,24,99,100,89,34,55,90,25,76,95};

   sort(numbers.begin(), numbers.end()); // tri par defaut croissant
   sort(numbers.begin() , numbers.end(), [](int a, int b)
   {
    return a > b;     //Lambda tri decroissant
   });

   vector<int>::iterator myit;

   for(myit = numbers.begin(); myit != numbers.end(); myit++){
    *myit*=2;
   }


   vector <string> names = {"a", "abc", "abcde", "abcd", "ab", "abcdef"} ;

   sort(names.begin(), names.end());
   // for (string name : names) {cout <<name << " " ;}

   sort(names.begin(), names.end(), [](string name1, string name2)
   {return name1 > name2;}
   );

    queue<int> file ;
    file.push(1);
    file.push(2);
    file.push(3);
    file.push(4);

    vector <int> vecteur; 
    cout << "Essaie avec Vecteur" << endl;

    while(!file.empty()) {vecteur.push_back(file.front());
        file.pop();}

    for (int number : vecteur) {cout << number << " ";}
    cout <<" " << endl;

    sort(vecteur.begin(), vecteur.end(), [] (int x, int y) { return x > y;});
    for (int number : vecteur) {cout << number << " ";} 

    cout << " " <<endl;

   
    // Probleme ici , avec les vecteurs on n a pas un pop front  
    queue<int> file_2 ;
    file_2.push(1);
    file_2.push(2);
    file_2.push(3);
    file_2.push(4);

    list<int> liste ;
    while(!file_2.empty()) {liste.push_back(file_2.front());
    file_2.pop();}

    cout << "Essaie avec Listes" << endl;

    for (int x : liste) {cout << x << " " ;}








    



   























    return 0;
}