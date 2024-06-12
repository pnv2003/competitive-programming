#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string s1, s2;
    getline(cin >> ws, s1);
    getline(cin >> ws, s2);
    for_each(s1.begin(), s1.end(), [](char& c){ c = tolower(c); });
    for_each(s2.begin(), s2.end(), [](char& c){ c = tolower(c); });
    if (s1 < s2)
        cout << -1;
    else if (s1 > s2)
        cout << 1;
    else
        cout << 0;
    return 0;
}
