#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string s;
    while (n--)
    {
        cin >> s;
        if (s == "1" || s == "4" || s == "78")
            cout << "+\n";
        else if (s.substr(s.size() - 2, 2) == "35")
            cout << "-\n";
        else if (s[0] == '9' && s[s.size() - 1] == '4')
            cout << "*\n";
        else
            cout << "?\n";
    }
    return 0;
}
