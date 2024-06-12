#include <iostream>
#include <string>
using namespace std;
const string self_reverses = "AHIMOTUVWXY18";
const pair<string, string> diff_reverses = {"EJLSZ235", "3LJ25SEZ"};

bool isPalindrome(const string& str)
{
    if (str.empty())
        return true;
    for (auto i = str.begin(), j = str.end() - 1;
         j - i > 0; ++i, --j)
    {
        if (*i != *j)
            return false;
    }
    return true;
}

bool isMirrored(const string& str)
{
    if (str.empty())
        return true;
    for (auto i = str.begin(), j = str.end() - 1;
         j - i >= 0; ++i, --j)
    {
        if (i == j || *i == *j)
        {
            if (self_reverses.find(*i) == string::npos)
                return false;
        }
        else
        {
            auto idx = diff_reverses.first.find(*i);
            if (idx == string::npos)
                return false;
            if (*j != diff_reverses.second[idx])
                return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string str;
    while (cin >> str)
    {
        cout << str << " -- is ";
        bool ispal = isPalindrome(str);
        bool ismir = isMirrored(str);

        if (ispal && ismir)
            cout << "a mirrored palindrome.\n\n";
        else if (ispal)
            cout << "a regular palindrome.\n\n";
        else if (ismir)
            cout << "a mirrored string.\n\n";
        else
            cout << "not a palindrome.\n\n";
    }
    
    return 0;
}
