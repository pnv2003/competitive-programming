#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int sz;
    vector<int> v;
    cout << "Lumberjacks:\n";
    while (n--)
    {
        for (int i = 0; i < 10; ++i)
        {
            cin >> sz;
            v.push_back(sz);
        }
        cout << (is_sorted(v.begin(), v.end()) || is_sorted(v.rbegin(), v.rend()) ? 
                 "Ordered\n" : 
                 "Unordered\n");
        v.clear();
    }
    return 0;
}
