#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    while (getline(cin >> ws, line))
        cout << line << "\n";
    return 0;
}
