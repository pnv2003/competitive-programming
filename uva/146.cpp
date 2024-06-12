#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string code;
    while (cin >> code)
    {
        if (code == "#") break;

        if (next_permutation(code.begin(), code.end()))
            cout << code << "\n";
        else
            cout << "No Successor\n";
    }
    
    return 0;
}
