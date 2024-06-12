#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int t, id = 1;
    vector<int> v;
    cin >> t;

    int num, sp;
    while (t--)
    {
        cin >> num;
        while (num--)
        {
            cin >> sp;
            v.push_back(sp);
        }
        cout << "Case " << id++ << ": " << *max_element(v.begin(), v.end()) << "\n";
        v.clear();
    }

    return 0;
}
