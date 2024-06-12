#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

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
    int n;
    cin >> n;
    while (n--)
    {
        ll num;
        cin >> num;

        int i = 0;
        while (true)
        {
           
            auto numstr = to_string(num);

            if (isPalindrome(numstr))
                break;
            
            ++i;
            reverse(numstr.begin(), numstr.end());
            num += stoll(numstr);
        }

        cout << i << " " << num << "\n";
    }
    
    return 0;
}
