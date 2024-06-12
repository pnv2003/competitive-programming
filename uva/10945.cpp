#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool isPalindrome(const string& str)
{
    if (str.empty())
        return true;
    for (auto i = str.begin(), j = str.end() - 1;
         j - i > 0; ++i, --j)
    {
        while (!isalpha(*i))
        {
            if (j - i <= 0)
                return true;
            ++i;
        }
        
        while (!isalpha(*j))
        {
            if (j - i <= 0) 
                return true;
            --j;
        }

        if (*i != *j && 
            *i != (*j + ('a' - 'A')) &&
            *i != (*j + ('A' - 'a')))
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string sentence;
    while (getline(cin >> ws, sentence))
    {
        if (sentence == "DONE")
            break;
        cout << 
        (
            isPalindrome(sentence) ?
            "You won't be eaten!\n" :
            "Uh oh..\n"
        );
    }
    
    return 0;
}
