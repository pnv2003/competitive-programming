#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string w;
    int id = 1;
    for (;;)    
    {
        cin >> w;
        if (w == "*") break;
        cout << "Case " << id++ << ": ";
        if (w == "Hajj")
            cout << "Hajj-e-Akbar\n";
        else 
            cout << "Hajj-e-Asghar\n";
    }
    return 0;
}
