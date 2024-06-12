#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string word;
    int id = 1;
    while(getline(cin >> ws, word))
    {
        if (word == "#") break;
        cout << "Case " << id << ": ";
        if (word == "HELLO")
            cout << "ENGLISH\n";
        else if (word == "HOLA")
            cout << "SPANISH\n";
        else if (word == "HALLO")
            cout << "GERMAN\n";
        else if (word == "BONJOUR")
            cout << "FRENCH\n";
        else if (word == "CIAO")
            cout << "ITALIAN\n";
        else if (word == "ZDRAVSTVUJTE")
            cout << "RUSSIAN\n";
        else
            cout << "UNKNOWN\n";
        ++id;
    }
    return 0;
}
