#include <iostream>
#include <memory> 
#include <vector>
#include <functional> 


using namespace std; 




class CompareLongueurGrand
{
public:
    bool operator()(const string& a, const string& b)
    {
        return a.length() > b.length();
    }
};

class CompareLongueur
{
public:
    bool operator()(const string& a, const string& b)
    {
        return a.length() < b.length();
    }
};


int
main (int argc, char** argv)
{
    auto ComparerParPlusLong = [](const string& a, const string& b)
    {
        return a.length() > b.length();
    };

    // std::sort(a.begin(), a.end(), ComparerParPlusLong);
    //std::sort(a.begin(), a.end());
    /* std::sort(a.begin(), a.end(), [](const string& a, const string& b)
     {
         return a.length() > b.length();
     });*/

    vector<string> a;
    a.push_back("allo");
    a.push_back("bye");
    a.push_back("patate");


    std::sort(a.begin(), a.end(), CompareLongueur());
    for(auto it=a.begin(); it!=a.end(); ++it)
    {
        cout << *it << endl;
    }

    std::sort(a.begin(), a.end(), CompareLongueurGrand());
    for(auto it=a.begin(); it!=a.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;

}