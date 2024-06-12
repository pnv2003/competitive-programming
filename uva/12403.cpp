#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, money = 0;
    string cmd;
    cin >> n;
    while (n--)
    {
        int k;
        string w;
        getline(cin >> ws, cmd);
        if (cmd[0] == 'd')
        {
            stringstream ss{ cmd };
            ss >> w >> k;
            money += k;
        }
        else
            cout << money << "\n";
    }
    return 0;
}
