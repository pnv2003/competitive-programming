#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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

int main(int argc, char const *argv[])
{
    string str;
    while (cin >> str)
    {
        int count = 0;
        vector<string> pals;

        for (int ssize = 1; ssize <= str.size(); ++ssize)
        {
            for (int i = 0; i< str.size() - ssize + 1; ++i)
            {
                auto sub = str.substr(i, ssize);
                if (isPalindrome(sub))
                    pals.push_back(sub);
            }
        }

        sort(pals.begin(), pals.end());
        auto last = unique(pals.begin(), pals.end());
        pals.erase(last, pals.end());

        cout << "The string '" 
             << str 
             << "' contains "
             << pals.size()
             << " palindromes.\n";
    }
    
    return 0;
}
