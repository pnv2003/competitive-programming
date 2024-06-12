#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    using psi = pair<string, int>;
    int t, rel, id = 1;
    string url; 
    vector<psi> v;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 10; ++i)
        {
            cin >> url >> rel;
            v.push_back(psi{url, rel});
        }
        int mrel = max_element(v.begin(), v.end(), 
                    [](const psi& p1, const psi& p2){ return p1.second < p2.second; })->second;

        cout << "Case #" << id++ << ":\n";
        for (const psi& p: v)
        {
            if (p.second == mrel)
                cout << p.first << "\n";
        }
        v.clear();
    }
    return 0;
}

