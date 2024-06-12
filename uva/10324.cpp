#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string bits;
    int q, i, j, id = 1;
    while (cin >> bits)
    {
        cout << "Case " << id++ << ":\n";
        cin >> q;
        while (q--)
        {
            cin >> i >> j;
            auto range = minmax(i, j);
            auto diff = adjacent_find(bits.begin() + range.first, 
                                      bits.begin() + range.second + 1,
                                      [](char c1, char c2) { return (c1 != c2); });
            if (diff > bits.begin() + range.second)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}
