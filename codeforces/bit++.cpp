#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, x = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string line;
        getline(cin >> ws, line);
        if (line.find('+') != string::npos)
            ++x;
        else if (line.find('-') != string::npos)
            --x;
    }
    cout << x;
    return 0;
}
