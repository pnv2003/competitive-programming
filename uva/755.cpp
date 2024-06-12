#include <iostream>
#include <cctype>
#include <string>
#include <map>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main(int argc, char const *argv[])
{
    FASTIO
    int t, id = 1;
    cin >> t;
    while (t--)
    {
        int ntel;
        cin >> ntel;

        map<string, int> map_count;
        while (ntel--)
        {
            string str, num;
            cin >> str;

            for (char c: str)
            {
                if (c == '-')
                    continue;
                if (isdigit(c))
                    num.push_back(c);
                else
                {
                    char digit;
                    if (c >= 'A' && c <= 'C')   digit = '2';
                    else if (c <= 'F')          digit = '3';
                    else if (c <= 'I')          digit = '4';
                    else if (c <= 'L')          digit = '5';
                    else if (c <= 'O')          digit = '6';
                    else if (c <= 'S')          digit = '7';
                    else if (c <= 'V')          digit = '8';
                    else                        digit = '9';
                    num.push_back(digit);
                }
            }
            map_count[num]++;
        }

        if (id++ > 1)
            cout << "\n";
        bool hasDupl = false;
        for (const auto& p: map_count)
        {
            if (p.second > 1)
            {
                hasDupl = true;
                cout << p.first.substr(0, 3)
                    << "-"
                    << p.first.substr(3, 4)
                    << " "
                    << p.second
                    << "\n";
            }
        }
        if (!hasDupl)
            cout << "No duplicates.\n";
    }
    
    return 0;
}
